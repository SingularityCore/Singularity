# Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources src/*.c)

set(libtomcrypt_STAT_SRCS
  ${sources}
)


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hashes
  ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
  ${CMAKE_CURRENT_SOURCE_DIR}/src/math
  ${CMAKE_CURRENT_SOURCE_DIR}/src/misc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pk
)

add_library(libtomcrypt STATIC ${libtomcrypt_STAT_SRCS})
