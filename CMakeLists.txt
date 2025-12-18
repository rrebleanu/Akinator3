# 1. Setează o versiune minimă modernă, care include toate politicile necesare.
cmake_minimum_required(VERSION 3.20)

set(MAIN_PROJECT_NAME "oop")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")

project(${MAIN_PROJECT_NAME})

# 2. Standard C++ (Păstrează standardul 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# FIX CRITIC: Setează politica CMake la un nivel modern (3.12).
cmake_policy(VERSION 3.12)

# Include modulele ajutatoare
include(cmake/Options.cmake)
include(cmake/CompilerFlags.cmake)
include(cmake/CopyHelper.cmake)

set(SOURCES
        main.cpp
        Arbore.cpp
        JocAkinator.cpp
        Intrebare.cpp
        RaspunsFinal.cpp
        RaspunsDetaliat.cpp
        Nod.cpp
        Parser.cpp

)


# Adăugăm executabilul folosind lista completă de surse
add_executable(${MAIN_EXECUTABLE_NAME}
        ${SOURCES}
)

# Setări de compilare
set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES ${MAIN_EXECUTABLE_NAME})

# Include directorul sursă curent (pentru fișierele .hpp)
target_include_directories(${MAIN_EXECUTABLE_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Legătura cu biblioteca Threads (Standard C++)
find_package(Threads REQUIRED)
target_link_libraries(${MAIN_EXECUTABLE_NAME} PRIVATE Threads::Threads)


# Copiază executabilul în directorul de destinație
install(TARGETS ${MAIN_EXECUTABLE_NAME} DESTINATION ${DESTINATION_DIR})

# Copiază fișierul de intrare (tastatura.txt)
copy_files(FILES tastatura.txt COPY_TO_DESTINATION TARGET_NAME ${MAIN_EXECUTABLE_NAME})