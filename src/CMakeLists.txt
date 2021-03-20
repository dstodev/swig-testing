set(target_name main)

add_executable(${target_name}
	main.cs
)
target_link_libraries(${target_name}
	PRIVATE
		csbind
)
set_target_properties(${target_name}
	PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)
