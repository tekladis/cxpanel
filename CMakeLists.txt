cmake_minimum_required(VERSION 3.16)

project(cxpanel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(XCB REQUIRED xcb)

add_executable(${PROJECT_NAME} 
  src/xcb/connection.h
  src/xcb/event.h
  src/xcb/window.h

  src/xcb/connection.cpp
  src/xcb/event.cpp
  src/xcb/window.cpp
  src/main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE 
  -Wall 
  -Wextra 
  -pedantic
  $<$<CONFIG:Debug>:-g>
  $<$<CONFIG:Release>:-O2>
)

target_include_directories(${PROJECT_NAME} PRIVATE 
  ${XCB_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${XCB_LIBRARIES}
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
