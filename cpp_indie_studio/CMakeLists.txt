cmake_minimum_required(VERSION 2.6)

SET(CMAKE_INSTALL_PREFIX .)

project(indie_studio)

include_directories(include/ irr/include/)

link_directories("../irr/lib/")

add_executable(
	indie_studio
	include/Events.hh
	irr/include/irrlicht.h
	irr/include/IrrlichtDevice.h
	src/main.cpp
)

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=gnu++0x")

	target_link_libraries(indie_studio Irrlicht X11 GL Xxf86vm)

	install(TARGETS indie_studio 
		RUNTIME DESTINATION bin
	)

endif()

if(WIN32)
	set(CMAKE_C_FLAGS "Irrlicht")
	
	target_link_libraries(indie_studio Irrlicht gdi32 opengl32 d3dx9d winmm m)

	install(TARGETS indie_studio 
		RUNTIME DESTINATION bin
	)

endif()

#target_link_libraries(indie_studio Irrlicht X11 GL Xxf86vm)
