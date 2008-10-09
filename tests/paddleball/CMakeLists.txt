set(INC "${CMAKE_SOURCE_DIR}/include/SDL4Cpp")

link_libraries(${SDL_LIBRARY} "${PROJECT_BINARY_DIR}/src/${CMAKE_FIND_LIBRARY_PREFIXES}SDL4Cpp${CMAKE_SHARED_LIBRARY_SUFFIX}")
add_executable(paddleball
	ball.cpp
	computer.cpp
	main.cpp
	paddle.cpp
	score.cpp)

set_property(TARGET paddleball APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS}")
