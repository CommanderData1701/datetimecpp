cmake_minimum_required(VERSION 3.16)
project(datetimecpp
    VERSION         1.0
    LANGUAGES       CXX
    DESCRIPTION     "A datetime library for C++"
)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 17)

################################################################################
#                       Setting library name                                   #
################################################################################
add_library(${PROJECT_NAME}
    src/AbstractDateTime.cpp
    src/Timespan.cpp

    src/constructors.cpp
    src/operations.cpp
)

add_compile_options(-Wall -Wextra --pedantic -Wno-unused-parameter)

################################################################################
#                       Setting include directories                            #
################################################################################
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

################################################################################
#                       Set installation config                                #
################################################################################
install(TARGETS         ${PROJECT_NAME}
    EXPORT              ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT  ${PROJECT_NAME}Targets
    FILE        ${PROJECT_NAME}Targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

configure_package_config_file(
    cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
