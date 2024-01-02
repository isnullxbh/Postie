cmake_minimum_required(VERSION 3.25)
project(Postie VERSION 0.0.0
               DESCRIPTION "A message-based communication environment"
               HOMEPAGE_URL "https://github.com/isnullxbh/Postie")

option(POSTIE_BUILD_TESTS "Generates build targets for unit tests" OFF)

add_subdirectory(libs)

# Installation
install(EXPORT PostieTargets
    DESTINATION lib/cmake/Postie
    FILE PostieTargets.cmake)

install(
    TARGETS
        Postie.MessageSet
    EXPORT PostieTargets
    FILE_SET HEADERS
        DESTINATION include)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/PostieConfig.cmake
    INSTALL_DESTINATION lib/cmake/Postie
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/PostieConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/PostieConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/PostieConfigVersion.cmake
    DESTINATION lib/cmake/Postie)
