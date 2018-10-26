cmake_minimum_required(VERSION 3.12)
project(Assignment3)

set(CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

add_library(fraction SHARED fraction_15ks2.cpp fraction_15ks2.h)
target_compile_definitions(fraction PRIVATE BUILDING_FRACTION_DLL)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Populate a CMake variable with the sources
set(CALCULATOR_SRCS
        main.cpp
        calculator.h calculator.cpp)
# Tell CMake to create the helloworld executable
add_executable(calculator WIN32 ${CALCULATOR_SRCS})

target_link_libraries(calculator fraction)
target_link_libraries(calculator Qt5::Widgets)
