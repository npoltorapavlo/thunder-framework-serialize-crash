cmake_minimum_required(VERSION 3.14)

project(thunder-framework-serialize-crash)

set(CMAKE_CXX_STANDARD 11)

find_package(Thunder NAMES WPEFramework Thunder)
find_package(${NAMESPACE}Core REQUIRED)

add_executable(${PROJECT_NAME}
        Module.cpp
        ThunderFrameworkSerializeCrash.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${NAMESPACE}Core::${NAMESPACE}Core
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
