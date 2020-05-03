
# Executable
add_executable(executable
	main.cpp
	module.cpp)

target_compile_options(executable PUBLIC -Wall -pedantic)

target_link_libraries(executable
	PUBLIC coverage_config 
	)

install(TARGETS executable DESTINATION ${BIN_DIR})


# Static library (optional)
add_library(module_library STATIC
    module.cpp
)

target_compile_options(module_library PUBLIC -Wall -pedantic)

target_link_libraries(module_library
	PUBLIC coverage_config 
	)

target_include_directories(module_library  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS module_library DESTINATION ${LIB_DIR})
