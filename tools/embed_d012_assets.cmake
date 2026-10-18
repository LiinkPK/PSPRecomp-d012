if(NOT DEFINED OUTPUT_CPP OR NOT DEFINED OUTPUT_HPP OR NOT DEFINED ROOT)
  message(FATAL_ERROR "OUTPUT_CPP, OUTPUT_HPP and ROOT are required")
endif()
if(NOT DEFINED DISC_ROOT)
  set(DISC_ROOT "")
endif()

set(ASSETS
  "BOOT.bin|BOOT.bin"
  "OVL_MENU_APP.ELF|OVL_MENU_APP.ELF"
  "language.bin|language.bin"
  "general_archive/main/main.bin|general_archive/main/main.bin"
  "general_archive/main/JP/main_lang.bin|general_archive/main/JP/main_lang.bin"
  "save/JP/PARAM.SFO|save/JP/PARAM.SFO"
  "menu_pk_loading_gim_0.bin|menu_pk_loading_gim_0.bin"
  "menu_lpk_loading_gim_0.bin|menu_lpk_loading_gim_0.bin"
  "menu_pk_loading_seq_0.bin|menu_pk_loading_seq_0.bin"
  "menu_lpk_loading_seq_0.bin|menu_lpk_loading_seq_0.bin"
  "@PACKAGE_INFO.BIN|package_info.bin"
)

set(HPP_CONTENT "#pragma once\n#include <cstddef>\n#include <string_view>\nnamespace d012::embedded {\nstruct Asset { const unsigned char *data; std::size_t size; };\nAsset find(std::string_view path);\n}\n")
get_filename_component(OUTPUT_HPP_NAME "${OUTPUT_HPP}" NAME)
set(CPP_CONTENT "#include \"${OUTPUT_HPP_NAME}\"\n#include <cstring>\nnamespace d012::embedded {\n")

set(TABLE "")
foreach(ITEM IN LISTS ASSETS)
  string(REPLACE "|" ";" PARTS "${ITEM}")
  list(GET PARTS 0 NAME)
  list(GET PARTS 1 GUEST)
  string(REGEX REPLACE "[^A-Za-z0-9_]" "_" ID "${GUEST}")
  if(NAME MATCHES "^@(.+)$")
    set(SOURCE "${DISC_ROOT}/PSP_GAME/USRDIR/DATA/${CMAKE_MATCH_1}")
  else()
    set(SOURCE "${ROOT}/${NAME}")
  endif()
  if(NOT EXISTS "${SOURCE}")
    message(FATAL_ERROR "Missing embedded D012 asset: ${SOURCE}")
  endif()
  file(READ "${SOURCE}" HEXDATA HEX)
  string(REGEX REPLACE "([0-9A-Fa-f][0-9A-Fa-f])" "0x\\1," BYTES "${HEXDATA}")
  string(APPEND CPP_CONTENT "static const unsigned char a_${ID}[] = {${BYTES}};\n")
  string(APPEND CPP_CONTENT "static constexpr std::size_t n_${ID} = sizeof(a_${ID});\n")
  string(APPEND TABLE "  if (path == \"${GUEST}\") return {a_${ID}, n_${ID}};\n")
endforeach()
string(APPEND CPP_CONTENT "Asset find(std::string_view path) {\n${TABLE}  return {nullptr, 0};\n}\n}\n")
file(WRITE "${OUTPUT_HPP}" "${HPP_CONTENT}")
file(WRITE "${OUTPUT_CPP}" "${CPP_CONTENT}")
