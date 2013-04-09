cmake_minimum_required (VERSION 2.8)
project(mytest3dengine)

project (3dengineSolution)

if(WIN32)

	add_subdirectory(3dSample)
	add_subdirectory(mytest3dengine)
	
endif()
