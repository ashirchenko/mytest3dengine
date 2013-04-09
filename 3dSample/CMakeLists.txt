cmake_minimum_required (VERSION 2.8)

if(WIN32)
	
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/
						${PROJECT_SOURCE_DIR}/mytest3dengine/include/
    )

	set(sample_src ${CMAKE_CURRENT_SOURCE_DIR}/src/3dSample.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/resource/window/3dSample.rc
	)
	
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

	add_executable(3dengineSample ${sample_src})
	target_link_libraries(3dengineSample 3dengine)
	
	add_dependencies(3dengineSample 3dengine)
	
	message("Cmake_win32")

endif()
