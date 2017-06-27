INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SHREE shree)

FIND_PATH(
    SHREE_INCLUDE_DIRS
    NAMES shree/api.h
    HINTS $ENV{SHREE_DIR}/include
        ${PC_SHREE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SHREE_LIBRARIES
    NAMES gnuradio-shree
    HINTS $ENV{SHREE_DIR}/lib
        ${PC_SHREE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SHREE DEFAULT_MSG SHREE_LIBRARIES SHREE_INCLUDE_DIRS)
MARK_AS_ADVANCED(SHREE_LIBRARIES SHREE_INCLUDE_DIRS)

