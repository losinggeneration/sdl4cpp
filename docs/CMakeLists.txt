if(ENABLE_DOXYGEN)
	Find_Package(Doxygen REQUIRED)

	# If set, documentation will be generated during every build
	if(GENERATE_DOCS)
		set(ALWAYS_GENERATE ALL)
	endif(GENERATE_DOCS)

	# The configure file didn't seem to like taking CMAKE_SOURCE_DIR directly
	set(SOURCE_DIR ${CMAKE_SOURCE_DIR})

	# Configure the doxygen file
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/SDL4Cpp.doxy.in"
		"${CMAKE_CURRENT_BINARY_DIR}/SDL4Cpp.doxy"
		IMMEDIATE @ONLY)

	# This is our psudo target
	add_custom_target(doc_sdl4cpp
		COMMAND ${DOXYGEN_EXECUTABLE} SDL4Cpp.doxy
		COMMENT "Building documentation")

	# Target that gets called
	add_custom_target(docs ${ALWAYS_GENERATE})

	# Link our psudo target to target that gets called
	add_dependencies(docs doc_sdl4cpp)
endif(ENABLE_DOXYGEN)
