
#######################
# Option A: If a static library is built. (In this case coverage_config is contained in module_library.)
add_executable(tests
	main.cpp)
target_link_libraries(tests PRIVATE module_library)
#######################

#######################
# # Option B: If no static library is built.
# add_executable(tests
# 	main.cpp
# 	${SRC_DIR}/module.cpp)

# target_link_libraries(tests
# 	PUBLIC coverage_config 
# 	)
#######################

target_compile_options(tests PUBLIC -Wall -pedantic)

install(TARGETS tests DESTINATION ${TESTS_DIR})

add_test(NAME template_test COMMAND tests
	WORKING_DIRECTORY ${TESTS_DIR})
