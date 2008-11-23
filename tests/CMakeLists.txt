if(ENABLE_TESTS)
	Find_Package(OpenGL REQUIRED)
	# Build the paddleball example
	add_subdirectory(paddleball)

	set(INC "${CMAKE_SOURCE_DIR}/include/SDL4Cpp")

	link_libraries(${SDL_LIBRARY} "${PROJECT_BINARY_DIR}/src/${CMAKE_FIND_LIBRARY_PREFIXES}SDL4Cpp${CMAKE_SHARED_LIBRARY_SUFFIX}")
	add_executable(TestCD TestCD.cpp)
	set_property(TARGET TestCD APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestEvents TestEvents.cpp)
	set_property(TARGET TestEvents APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestGL TestGL.cpp)
	target_link_libraries(TestGL ${OPENGL_gl_LIBRARY})
	set_property(TARGET TestGL APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} -I${OPENGL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestJoystick TestJoystick.cpp)
	set_property(TARGET TestJoystick APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestKeyboard TestKeyboard.cpp)
	set_property(TARGET TestKeyboard APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestMouse TestMouse.cpp)
	set_property(TARGET TestMouse APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestVideo TestVideo.cpp)
	set_property(TARGET TestVideo APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	add_executable(TestWM TestWM.cpp)
	set_property(TARGET TestWM APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

	#add_executable(Transform Transform.cpp
	#set_property(TARGET Transform APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS} -Wall -Weffc++")

endif(ENABLE_TESTS)
