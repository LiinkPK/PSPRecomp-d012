set(D012_PROFILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(D012_ASSET_ROOT "${CMAKE_SOURCE_DIR}/original" CACHE PATH
    "Extracted D012 asset root used to create the self-contained native executable")
set(D012_DISC_ROOT "C:/Users/javi_/Downloads/Dissidia_012_EUR_FULL_UNDUB/Dissidia_012_EUR_FULL_UNDUB" CACHE PATH
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

add_executable(d012_native
    ${D012_GENERATED}
    "${D012_PROFILE_DIR}/host/main.cpp"
    "${D012_PROFILE_DIR}/host/d012_profile.cpp"
    "${D012_PROFILE_DIR}/host/win32_display.cpp"
    "${D012_PROFILE_DIR}/host/ge_render.cpp"
    "${D012_EMBED_CPP}"
)

target_include_directories(d012_native PRIVATE
    "${D012_PROFILE_DIR}/host"
    "${D012_PROFILE_DIR}/generated"
    "${CMAKE_SOURCE_DIR}/include"
    "${D012_EMBED_DIR}"
)

target_link_libraries(d012_native PRIVATE psprecomp_core)

if(WIN32)
    target_link_libraries(d012_native PRIVATE winmm gdi32 user32)
endif()

if(MSVC)
    target_link_options(d012_native PRIVATE /STACK:67108864)
endif()
