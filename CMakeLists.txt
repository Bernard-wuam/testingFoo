cmake_minimum_required(VERSION 3.10.0)
project(learningcxxlibinstallation VERSION 0.1.0 LANGUAGES C CXX)
find_package(boost_json CONFIG REQUIRED)

add_library(Foo STATIC)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_PROJECT_NAME})

target_sources(
    Foo
    PUBLIC
    FILE_SET headers TYPE HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src
    FILES
    src/foo/foo.h
    PRIVATE
    src/foo.cpp
)

install(TARGETS Foo
    EXPORT FooTargets
    FILE_SET headers)

install(EXPORT FooTargets
    DESTINATION share/cmake/foo
    NAMESPACE Foo::)
add_executable(learningcxxlibinstallation main.cpp)
target_link_libraries(learningcxxlibinstallation PUBLIC Boost::json)

target_link_libraries(Foo PUBLIC Boost::json)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/FooConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake"
    COPYONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake
    DESTINATION share/cmake/foo)