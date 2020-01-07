cmake_minimum_required(VERSION 3.6) # Проверка версии CMake.

set(BUILD_CONFIG NotebookCocos2d)

project(${BUILD_CONFIG})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${BUILD_CONFIG}
    main.cpp
    StateMachineNote.h
    StateMachineNote.cpp
    CoreAppDelegateCocosNodePlusPlus.h
    CoreAppDelegateCocosNodePlusPlus.cpp
)

add_subdirectory(subs)

target_link_libraries(${BUILD_CONFIG} CoreCocos2d_LIB)
