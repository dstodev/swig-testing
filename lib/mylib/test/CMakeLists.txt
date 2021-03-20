include(GoogleTest)

set(target_name test_mylib)

add_executable(${target_name}
	test_api.cxx
	test_myclass.cxx
)
target_link_libraries(${target_name}
	PRIVATE
		mylib
		gtest_main
)
set_target_properties(${target_name}
	PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)

gtest_discover_tests(${target_name})

add_custom_command(TARGET ${target_name} POST_BUILD
	COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --rerun-failed --output-on-failure
)
