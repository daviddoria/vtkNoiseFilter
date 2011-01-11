cmake_minimum_required(VERSION 2.6)

PROJECT(vtkNoiseFilter)
ENABLE_TESTING()

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

SET(BUILD_PARAVIEW_PLUGIN OFF CACHE BOOL "Build Paraview plugin?")

if(BUILD_PARAVIEW_PLUGIN)
 SUBDIRS(plugin)
endif(BUILD_PARAVIEW_PLUGIN)

ADD_EXECUTABLE(vtkNoiseFilterExample vtkNoiseFilterExample.cxx
vtkNoiseFilter.cxx)
TARGET_LINK_LIBRARIES(vtkNoiseFilterExample vtkHybrid )

