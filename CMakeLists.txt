############################################################
# Basic
############################################################
# min wersja cmake
cmake_minimum_required(VERSION 3.16.3)

# nazwa projektu i wersja
project(Organizer VERSION 1.0)

set(SOURCES
    Src/Main.cpp
)

set(HEADERS
    Include/Config.h.in
)

# wskazanie maina
add_executable(${PROJECT_NAME} ${SOURCES})

# dodanie pliku konfiguracyjnego projektu
configure_file(Include/Config.h.in Include/Config.h)

############################################################
# External Libraries
############################################################
option(ADD_NCURSES "Include ncurses lib in project" ON)
option(ADD_BOOST   "Include boost lib in project"   ON)

if(ADD_NCURSES)
    find_package(Curses REQUIRED)

    list(APPEND EXTRA_INCLUDES ${CURSES_INCLUDE_DIR})
    list(APPEND EXTRA_LINKS    ${CURSES_LIBRARIES})
endif()

if(ADD_BOOST)
    set(Boost_FIND_REQUIRED TRUE)
    set(Boost_FIND_QUIETLY TRUE)
    set(Boost_DEBUG FALSE)
    set(Boost_USE_MULTITHREADED TRUE)
    set(Boost_USE_STATIC_LIBS TRUE)
    #set(Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")

    find_package(Boost COMPONENTS regex)

    list(APPEND EXTRA_INCLUDES ${Boost_INCLUDE_DIRS})
    list(APPEND EXTRA_LINKS    ${Boost_LIBRARIES})    
endif()

############################################################
# Target 
############################################################
# dodanie podfolderów do projektu
add_subdirectory(Lib)
add_subdirectory(Tests)

# wskazanie folderów "include"(plików nagłówkowych bibliotek)
target_include_directories(${PROJECT_NAME} 
    PRIVATE ${PROJECT_BINARY_DIR}
    PRIVATE ${EXTRA_INCLUDES}
    PRIVATE ${PROJECT_SOURCE_DIR}/Include
)

# wskazanie folderów "src"(plików źródłowych bibliotek)
target_link_directories(${PROJECT_NAME}
    PRIVATE ${EXTRA_LIBS}
)

# linkowanie blibliotek
target_link_libraries(${PROJECT_NAME} 
    ${EXTRA_LINKS}
)

############################################################
# Install
############################################################
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES   ${HEADERS}      DESTINATION include)