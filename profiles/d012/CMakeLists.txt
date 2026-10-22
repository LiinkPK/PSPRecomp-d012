set(D012_PROFILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(D012_ASSET_ROOT "${CMAKE_SOURCE_DIR}/original" CACHE PATH
    "Extracted D012 asset root used to create the self-contained native executable")
set(D012_DISC_ROOT "" CACHE PATH
    "Extracted disc root used only at build time for small startup metadata")
set(D012_EMBED_DIR "${CMAKE_CURRENT_BINARY_DIR}/embedded6")
set(D012_EMBED_CPP "${D012_EMBED_DIR}/d012_embedded_assets_v2.cpp")
set(D012_EMBED_HPP "${D012_EMBED_DIR}/d012_embedded_assets_v2.hpp")
file(MAKE_DIRECTORY "${D012_EMBED_DIR}")
execute_process(
    COMMAND "${CMAKE_COMMAND}" -DOUTPUT_CPP=${D012_EMBED_CPP}
            -DOUTPUT_HPP=${D012_EMBED_HPP}
            -DROOT=${D012_ASSET_ROOT}
            -DDISC_ROOT=${D012_DISC_ROOT}
            -P "${CMAKE_SOURCE_DIR}/tools/embed_d012_assets.cmake"
    RESULT_VARIABLE D012_EMBED_RESULT)
if(NOT D012_EMBED_RESULT EQUAL 0)
    message(FATAL_ERROR "Could not embed D012 assets")
endif()

set(D012_GENERATED
    "${D012_PROFILE_DIR}/generated/generated_init_funcs.cpp"
    "${D012_PROFILE_DIR}/generated/generated_registry.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0000.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0001.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0002.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0003.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0004.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0005.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0006.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0007.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0008.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0009.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0010.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0011.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0012.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0013.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0014.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0015.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0016.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0017.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0018.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0019.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0020.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0021.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0022.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0023.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0024.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0025.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0026.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0042.cpp"
    "${D012_PROFILE_DIR}/generated/generated_unit_0136.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0000.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0001.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0002.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0003.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0004.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0005.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0006.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0007.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0008.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0009.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0010.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/generated_unit_0011.cpp"
    "${D012_PROFILE_DIR}/generated/overlay_menu/target_registry.cpp"
)

if(MSVC)
    set_source_files_properties(${D012_GENERATED} PROPERTIES COMPILE_OPTIONS
        "/Od;/Ob0;/bigobj")
endif()

# --- PortableKit renderer integration ---
set(PORTABLEKIT_ROOT "" CACHE PATH
    "Path to PortableKit source directory")

# Find SDL3 and Vulkan for the renderer
find_package(SDL3 QUIET)
find_package(Vulkan QUIET HINTS "D:/VulkanSDK/1.4.363.0")
find_program(PORTABLEKIT_GLSLANG NAMES glslangValidator glslang
    HINTS "D:/VulkanSDK/1.4.363.0/Bin")

set(PK_HOST_SOURCES
    "${PORTABLEKIT_ROOT}/host/gpu/ge_state.cpp"
    "${PORTABLEKIT_ROOT}/host/gpu/texture_decode.cpp"
)

set(PK_RENDERER_SOURCES)
set(D012_HAS_RENDERER OFF)
if(SDL3_FOUND AND Vulkan_FOUND AND PORTABLEKIT_GLSLANG)
    message(STATUS "d012: Vulkan renderer enabled")
    set(D012_HAS_RENDERER ON)

    set(shader_inc "${CMAKE_CURRENT_BINARY_DIR}/generated_shaders/ge_shaders.inc")
    add_custom_command(
        OUTPUT "${shader_inc}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/generated_shaders"
        COMMAND py "${PORTABLEKIT_ROOT}/tools/embed_shaders.py" "${PORTABLEKIT_GLSLANG}" "${shader_inc}"
                "kGeVertexShader=${PORTABLEKIT_ROOT}/host/gpu/shaders/ge.vert"
                "kGeFragmentShader=${PORTABLEKIT_ROOT}/host/gpu/shaders/ge.frag"
        DEPENDS "${PORTABLEKIT_ROOT}/host/gpu/shaders/ge.vert"
                "${PORTABLEKIT_ROOT}/host/gpu/shaders/ge.frag"
                "${PORTABLEKIT_ROOT}/tools/embed_shaders.py"
        COMMENT "Compiling GE shaders to SPIR-V")
    add_custom_target(d012_native_shaders DEPENDS "${shader_inc}")

    list(APPEND PK_RENDERER_SOURCES
        "${PORTABLEKIT_ROOT}/host/gpu/vulkan_renderer.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/imgui.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/imgui_draw.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/imgui_tables.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/imgui_widgets.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/backends/imgui_impl_sdl3.cpp"
        "${PORTABLEKIT_ROOT}/third_party/imgui/backends/imgui_impl_vulkan.cpp"
    )
else()
    message(STATUS "d012: renderer disabled (SDL3, Vulkan or glslang not found)")
endif()

add_executable(d012_native
    ${D012_GENERATED}
    "${D012_PROFILE_DIR}/host/main.cpp"
    "${D012_PROFILE_DIR}/host/d012_profile.cpp"
    "${D012_PROFILE_DIR}/host/ge_render.cpp"
    ${PK_HOST_SOURCES}
    ${PK_RENDERER_SOURCES}
    "${D012_EMBED_CPP}"
)

target_include_directories(d012_native PRIVATE
    "${D012_PROFILE_DIR}/host"
    "${D012_PROFILE_DIR}/generated"
    "${CMAKE_SOURCE_DIR}/include"
    "${D012_EMBED_DIR}"
    "${PORTABLEKIT_ROOT}/host"
    "${PORTABLEKIT_ROOT}/include"
    "${PORTABLEKIT_ROOT}/third_party"
)

target_link_libraries(d012_native PRIVATE psprecomp_core)

if(D012_HAS_RENDERER)
    add_dependencies(d012_native d012_native_shaders)
    target_compile_definitions(d012_native PRIVATE
        PORTABLEKIT_HAS_RENDERER=1 D012_HAS_VULKAN_RENDERER=1)
    target_include_directories(d012_native PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}/generated_shaders"
    )
    target_link_libraries(d012_native PRIVATE SDL3::SDL3 Vulkan::Vulkan)
endif()

if(WIN32)
    target_link_libraries(d012_native PRIVATE winmm gdi32 user32 ws2_32)
endif()

if(MSVC)
    target_link_options(d012_native PRIVATE /STACK:67108864)
    target_compile_options(d012_native PRIVATE /bigobj)
endif()
