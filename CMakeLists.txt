cmake_minimum_required(VERSION 3.10)

project(RType)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(Doxygen)
find_package(Boost 1.71 REQUIRED COMPONENTS system thread)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1
)
FetchContent_MakeAvailable(sfml)

# Attempt to fetch Boost
FetchContent_Declare(
    boost
    URL https://boostorg.jfrog.io/artifactory/main/release/1.71.0/source/boost_1_71_0.tar.gz
)
FetchContent_GetProperties(boost)
if(NOT boost_POPULATED)
    FetchContent_Populate(boost)
    # Assuming the fetched Boost is header-only or does not require building
else()
    # Fallback to system Boost if fetching failed
    find_package(Boost 1.71 REQUIRED COMPONENTS system thread)
endif()


# CPack for packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "R-typeBinary")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-system-dev, libboost-thread-dev, libsfml-dev,
libopenal-dev, libglew-dev, libjpeg-dev, libfreetype6-dev, libvorbis-dev, libogg-dev,
libflac-dev, libx11-dev, libxrandr-dev, libudev-dev")
include(CPack)

# Doxygen setup
if(DOXYGEN_FOUND)
    message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE}")
    set(DOXYGEN_CONF ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONF}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else()
    message(STATUS "Doxygen not found !.")
endif()

# Include subdirectories
add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(GameEngine)
