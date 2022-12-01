cmake_minimum_required(VERSION 3.23)
project(FaroBT VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /permissive-")

# Include QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build")
set(AUTOGEN_BUILD_DIR "${CMAKE_SOURCE_DIR}/build/autogen")
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS UiTools)

# Include Project Files
set(DEP_DIR "${CMAKE_SOURCE_DIR}/dep")
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(DEP_DIR)
include_directories(FORMS_DIR)
include_directories(INCLUDE_DIR)
include_directories(SRC_DIR)

file(GLOB_RECURSE SOURCES
		"*.qrc"
        "${DEP_DIR}/*"
        "${FORMS_DIR}/*.ui"
    )

# Setup Executable
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

add_executable(FaroBT WIN32
        "${SOURCES}"
        "${INCLUDE_DIR}/DefaultTableModel.h"
        "${INCLUDE_DIR}/FaroBT.h"
        "${INCLUDE_DIR}/GUIBuild.h"
        "${INCLUDE_DIR}/SideBar.h"
        "${INCLUDE_DIR}/SqlConnection.h"
        "include/TableView.h"
        "${INCLUDE_DIR}/UserSite.h"
        "${SRC_DIR}/DefaultTableModel.cpp"
        "${SRC_DIR}/FaroBT.cpp"
        "${SRC_DIR}/GUIBuild.cpp"
        "${SRC_DIR}/main.cpp"
        "${SRC_DIR}/SideBar.cpp"
        "${SRC_DIR}/SqlConnection.cpp"
        "src/TableView.cpp"
        "${SRC_DIR}/UserSite.cpp")

target_include_directories(FaroBT PRIVATE ${DEP_DIR})
target_include_directories(FaroBT PRIVATE ${FORMS_DIR})
target_include_directories(FaroBT PRIVATE ${INCLUDE_DIR})
target_include_directories(FaroBT PRIVATE ${SRC_DIR})

# Link Libraries
target_link_libraries(FaroBT PRIVATE Qt6::Core)
target_link_libraries(FaroBT PRIVATE Qt6::Widgets)
target_link_libraries(FaroBT PRIVATE Qt6::Gui)
target_link_libraries(FaroBT PRIVATE Qt6::Sql)
target_link_libraries(FaroBT PRIVATE Qt6::UiTools)

