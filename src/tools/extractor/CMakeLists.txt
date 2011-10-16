# Copyright (C) 2011 Singularity <http://www.singularitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(extractor_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/adt.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/adt.h
	${CMAKE_CURRENT_SOURCE_DIR}/dbc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/dbc.h
	${CMAKE_CURRENT_SOURCE_DIR}/DBCFile.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DBCFile.h
	${CMAKE_CURRENT_SOURCE_DIR}/FileLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FileLoader.h
	${CMAKE_CURRENT_SOURCE_DIR}/headers.h
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/map.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/map.h
	${CMAKE_CURRENT_SOURCE_DIR}/misc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/misc.h
	${CMAKE_CURRENT_SOURCE_DIR}/MPQ.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MPQ.h
	${CMAKE_CURRENT_SOURCE_DIR}/MPQFile.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MPQFile.h
	${CMAKE_CURRENT_SOURCE_DIR}/typedefs.h
	${CMAKE_CURRENT_SOURCE_DIR}/wdt.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/wdt.h
)

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/StormLib
  ${CMAKE_SOURCE_DIR}/dep/libtomcrypt/src/headers
  ${CMAKE_SOURCE_DIR}/dep/jenkins
)

set(extractor_C_FLAGS "-D_7ZIP_ST -DBZ_STRICT_ANSI")

if(WIN32)
    if(MSVC)
        set(extractor_C_FLAGS "-D_7ZIP_ST -DWIN32")
    endif()
    set(extractor_SRC_ADDITIONAL_FILES ${ZLIB_BZIP2_FILES})
endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    set(extractor_LINK_FLAGS "-lz -lbz2")
endif()

add_executable(extractor ${stormlib_SRCS} ${libtomcrypt_STAT_SRCS} ${ZLIB_BZIP2_FILES} ${extractor_SRCS})

set_target_properties(extractor PROPERTIES COMPILE_FLAGS "${extractor_C_FLAGS}" LINK_FLAGS "${extractor_LINK_FLAGS}")

target_link_libraries(extractor
  stormlib
  libtomcrypt
  jenkins
  libtommath
  adpcm
  pklib
  huffman
  sparse
  lzma
  ${BZIP2_LIBRARIES}
  ${ZLIB_LIBRARIES}
)

if( UNIX )
  install(TARGETS extractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS extractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
