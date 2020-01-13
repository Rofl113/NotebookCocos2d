cmake_minimum_required(VERSION 3.6) # Проверка версии CMake.

set(BUILD_CONFIG NotebookCocos2d)

project(${BUILD_CONFIG})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/release/${BUILD_CONFIG})
if(NOT EXISTS ${CMAKE_BINARY_DIR})
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/release/${BUILD_CONFIG})
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(HEADERS_NotebookCocos2d
    # NotebookCocos2d Common
    NotebookCocos2d/StateMachineNotebookCocos2d.h
    NotebookCocos2d/CoreAppDelegateNotebookCocos2d.h
    # NotebookCocos2d Scenes
    NotebookCocos2d/Scenes/ISceneMain.h
    NotebookCocos2d/Scenes/SceneMain.h
    )

set(SOURCES_NotebookCocos2d
    main.cpp
    # NotebookCocos2d Common
    NotebookCocos2d/StateMachineNotebookCocos2d.cpp
    NotebookCocos2d/CoreAppDelegateNotebookCocos2d.cpp
    # NotebookCocos2d Scenes
    NotebookCocos2d/Scenes/SceneMain.cpp
    )

add_executable(${BUILD_CONFIG}
    # Main
    main.cpp
    # NotebookCocos2d
    ${SOURCES_NotebookCocos2d}
    ${HEADERS_NotebookCocos2d}
)

add_subdirectory(subs)

target_link_libraries(${BUILD_CONFIG} CoreCocos2d_LIB)
target_link_libraries(${BUILD_CONFIG} nlohmann_json::nlohmann_json)
