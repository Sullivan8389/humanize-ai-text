cmake_minimum_required(VERSION 3.16)
project(humanize-ai-text CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(humanizeaitext
    src/main.cpp
    src/humanizer.cpp
    src/patterns.cpp
    src/paraphrase.cpp
)

target_include_directories(humanizeaitext PRIVATE include)

if(WIN32)
    target_link_libraries(humanizeaitext PRIVATE userenv)
endif()
