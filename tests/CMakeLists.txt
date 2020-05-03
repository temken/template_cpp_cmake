add_executable(tests
	main.cpp)

target_compile_options(tests PUBLIC -Wall -pedantic)

target_link_libraries(tests PRIVATE module_library)

install(TARGETS tests DESTINATION ${TESTS_DIR})

add_test(NAME template_test COMMAND tests
	WORKING_DIRECTORY ${TESTS_DIR})
