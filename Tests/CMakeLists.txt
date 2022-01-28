############################################################
# Basic
############################################################
cmake_minimum_required(VERSION 3.16.3)

project(UnitTests)

get_filename_component(PARENT_DIR "${PROJECT_NAME}" DIRECTORY)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

set(SOURCES
    ${PARENT_DIR}/Src/Note.cpp
    ${PARENT_DIR}/Src/InfoCollection.cpp
    ${PARENT_DIR}/Src/InfoElement.cpp
    ${PARENT_DIR}/Include/Config.h.in
)   
set(TESTS_SOURCES
    TestMain.cpp
)

# GTest as a testing framework
find_package(GTest)

enable_testing()

add_executable(UnitTests ${TESTS_SOURCES} ${SOURCES}) #${SOURCES}

# dodanie pliku konfiguracyjnego projektu
# configure_file(${PARENT_DIR}/Include/Config.h.in ${PARENT_DIR}/Include/Config.h)

# to prevent collision with the main
target_compile_definitions(UnitTests PUBLIC UNIT_TESTS)
# to use executable as a link library to inherit all compiler options and library dependencies
set_target_properties(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS ON)

target_link_libraries(UnitTests PUBLIC
    ${GTEST_BOTH_LIBRARIES}
)

# doesn't do anything on Linux
target_include_directories(UnitTests PUBLIC
    PRIVATE ${PARENT_DIR}/Include    
    PRIVATE ${GTEST_INCLUDE_DIRS} 
    PRIVATE ${EXTRA_INCLUDES}
    
)