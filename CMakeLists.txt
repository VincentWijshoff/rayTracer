cmake_minimum_required(VERSION 3.12)
project(raytracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Add the source files for your project
set(SOURCES
    main.cpp
    ./helper/point.cpp
    ./helper/vector.cpp
    ./screen/camera.cpp
    ./screen/viewplane.cpp
    ./screen/colour.cpp
    ./screen/visualengine.cpp
    ./engine/ray.cpp
    ./engine/tracer.cpp
    ./objects/circle.cpp
    ./objects/objecthandler.cpp
    ./objects/object.cpp
)

# Add the header files for your project
set(HEADERS
    ./helper/point.hpp
    ./helper/vector.hpp
    ./screen/camera.hpp
    ./screen/viewplane.hpp
    ./screen/colour.hpp
    ./screen/visualengine.hpp
    ./engine/ray.hpp
    ./engine/tracer.hpp
    ./objects/circle.hpp
    ./objects/object.hpp
    ./objects/objecthandler.hpp
)

# Create an executable target for your project
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ${PROJECT_NAME})