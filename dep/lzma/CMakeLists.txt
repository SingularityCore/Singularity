# Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set (lzma_SRCS
         ${CMAKE_CURRENT_SOURCE_DIR}/C/LzFind.c
         ${CMAKE_CURRENT_SOURCE_DIR}/C/LzmaDec.c
         ${CMAKE_CURRENT_SOURCE_DIR}/C/LzmaEnc.c
)

set(lzma_C_FLAGS "-D_7ZIP_ST -DBZ_STRICT_ANSI")

add_definitions(-D_7ZIP_ST -DBZ_STRICT_ANSI)

if(WIN32)
    if(MSVC)
        set(lzma_C_FLAGS "-D_7ZIP_ST -DWIN32")
    endif()
    set(lzma_SRC_ADDITIONAL_FILES ${ZLIB_BZIP2_FILES})
endif()

add_library(lzma STATIC ${lzma_SRCS})
