# Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources *.cpp)

set(stormlib_STAT_SRCS
  ${sources}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dep
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_SOURCE_DIR}/dep/bzip2
  ${CMAKE_SOURCE_DIR}/dep/jenkins
  ${CMAKE_SOURCE_DIR}/dep/libtomcrypt/src/headers
)

add_library(stormlib STATIC ${stormlib_STAT_SRCS})
