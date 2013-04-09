cmake_minimum_required (VERSION 2.8)
project (3dengine)

if(WIN32)

	include_directories($ENV{DXSDK_DIR}/Include)
	link_directories("$ENV{DXSDK_DIR}/Lib/x86")
	
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/core/
						${CMAKE_CURRENT_SOURCE_DIR}/include/export/
						${CMAKE_CURRENT_SOURCE_DIR}/include/support/
						${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/
						${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/listeners/
						
						${CMAKE_CURRENT_SOURCE_DIR}/src/private/include/core/
						${CMAKE_CURRENT_SOURCE_DIR}/src/private/include/support/
                    )

	set(engine_src ${CMAKE_CURRENT_SOURCE_DIR}/src/dllmain.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Core.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Text.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Sprite.cpp
				   
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/private/src/core/Timer.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/private/src/core/ViewMatrix.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/private/src/core/ProjectionMatrix.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/private/src/support/Vertex3PN.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/src/private/src/support/Vertex3PNT.cpp
	)
	
	ADD_LIBRARY(3dengine SHARED ${engine_src})
	target_link_libraries(3dengine LINK_PRIVATE d3d9.lib d3dx9.lib)
	
	set(LIB_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/my3dengine/lib/)
	install(TARGETS 3dengine DESTINATION ${LIB_INSTALL_PATH})

	message("Cmake_win32")

endif()
