cmake_minimum_required(VERSION 3.20)
project(Dissidia012 VERSION 0.1.0 LANGUAGES CXX)

set(PORTABLEKIT_ROOT "" CACHE PATH
    "Path to PortableKit source directory (e.g. path/to/Tenkawa/portablekit)")
if(NOT PORTABLEKIT_ROOT OR NOT EXISTS "${PORTABLEKIT_ROOT}/cmake/PortableKit.cmake")
    message(FATAL_ERROR "Set PORTABLEKIT_ROOT to the PortableKit source directory")
endif()

set(D012_PROFILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../d012")

add_subdirectory("${PORTABLEKIT_ROOT}" "${CMAKE_CURRENT_BINARY_DIR}/portablekit")

portablekit_add_game(d012_native
    PROFILE_DIR "${D012_PROFILE_DIR}"
    SOURCES host/d012_portablekit_profile.cpp)


# Overlay menu generated units (portablekit_add_game only globs generated/*.cpp)
file(GLOB D012_OVL_MENU CONFIGURE_DEPENDS
    "${D012_PROFILE_DIR}/generated/overlay_menu/*.cpp")
if(D012_OVL_MENU)
    if(MSVC)
        set_source_files_properties(${D012_OVL_MENU} PROPERTIES COMPILE_OPTIONS "/Od;/Ob0;/bigobj")
    endif()
    target_sources(d012_native_generated PRIVATE ${D012_OVL_MENU})
    target_include_directories(d012_native_generated PRIVATE
        "${D012_PROFILE_DIR}/generated/overlay_menu")
endif()

if(WIN32)
    target_link_libraries(d012_native PRIVATE winmm gdi32 user32)
endif()

# Ship the texture pack inside the executable: after every link the pack is appended to the
# exe itself (tools/textures/embed_textures.py), so the game is one file with the textures in it.
set(D012_TEXTURE_PACK_DIR "" CACHE PATH "Folder with textures.ini to embed (default: the script's)")
find_program(D012_PYTHON NAMES python python3)
set(D012_EMBED_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../../tools/textures/embed_textures.py")
if(D012_PYTHON AND EXISTS "${D012_EMBED_SCRIPT}")
    add_custom_command(TARGET d012_native POST_BUILD
        COMMAND "${D012_PYTHON}" "${D012_EMBED_SCRIPT}"
                "$<TARGET_FILE:d012_native>" ${D012_TEXTURE_PACK_DIR}
        COMMENT "Embedding the texture pack into the executable")
else()
    message(STATUS "d012_native: no texture packer here, building without an embedded texture pack")
endif()
