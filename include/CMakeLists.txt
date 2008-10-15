install(FILES
	SDL4Cpp/SDL4Cpp_audio.h
	SDL4Cpp/SDL4Cpp_cdrom.h
	SDL4Cpp/SDL4Cpp_events.h
	SDL4Cpp/SDL4Cpp.h
	SDL4Cpp/SDL4Cpp_joystick.h
	SDL4Cpp/SDL4Cpp_main.h
	SDL4Cpp/SDL4Cpp_mouse.h
	SDL4Cpp/SDL4Cpp_mt.h
	SDL4Cpp/SDL4Cpp_rwops.h
	SDL4Cpp/SDL4Cpp_time.h
	SDL4Cpp/SDL4Cpp_video.h
	SDL4Cpp/SDL4Cpp_wm.h

	DESTINATION ${INCLUDE_INSTALL_DIR}/SDL4Cpp)

if(ENABLE_MIXER)
	install(FILES
		SDL4Cpp/mixer/SDL4Cpp_mixer.h

		DESTINATION ${INCLUDE_INSTALL_DIR}/SDL4Cpp/mixer)
endif(ENABLE_MIXER)

if(ENABLE_IMAGE)
	install(FILES
		SDL4Cpp/image/SDL4Cpp_image.h

		DESTINATION ${INCLUDE_INSTALL_DIR}/SDL4Cpp/image)
endif(ENABLE_IMAGE)

