cmake_minimum_required(VERSION 3.6)

set(BUILD_CONFIG NotebookCocos2d)

project(${BUILD_CONFIG})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(HEADERS_NotebookCocos2d
    # NotebookCocos2d Common
    NotebookCocos2d/StateMachineNotebookCocos2d.h
    NotebookCocos2d/CoreAppDelegateNotebookCocos2d.h
    # NotebookCocos2d Scenes
    NotebookCocos2d/Scenes/ISceneMain.h
    NotebookCocos2d/Scenes/SceneMain.h
    NotebookCocos2d/Scenes/MainWindow.h
    )

set(SOURCES_NotebookCocos2d
    # NotebookCocos2d Common
    NotebookCocos2d/StateMachineNotebookCocos2d.cpp
    NotebookCocos2d/CoreAppDelegateNotebookCocos2d.cpp
    # NotebookCocos2d Scenes
    NotebookCocos2d/Scenes/SceneMain.cpp
    NotebookCocos2d/Scenes/MainWindow.cpp
    )

set(UIS_NotebookCocos2d
    # NotebookCocos2d Scenes
    NotebookCocos2d/Scenes/MainWindow.ui
    )

# Next lines needed for building all Qt projects
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(subs)

# compile
add_executable(${BUILD_CONFIG}
    # Main
    main.cpp
    # NotebookCocos2d
    ${HEADERS_NotebookCocos2d}
    ${SOURCES_NotebookCocos2d}
    ${UIS_NotebookCocos2d}
)

include_directories(NotebookCocos2d/)

# build it (link libraries)
target_link_libraries(${BUILD_CONFIG}
    Qt5::Core
    Qt5::Widgets
    CoreCocos2d_LIB
    Cocos2dxViaQt
    nlohmann_json::nlohmann_json
)
