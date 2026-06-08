cmake_minimum_required(VERSION 3.22)

# Grab all source files in this directory
# CONFIGURE_DEPENDS ensures that CMake checks for new files at build time.
file(GLOB_RECURSE application_source CONFIGURE_DEPENDS ./*.c)

target_sources(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
    ${application_source}
    )