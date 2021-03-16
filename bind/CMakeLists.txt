find_package(SWIG 4.0
	COMPONENTS
		csharp
)

if (SWIG_FOUND)
	include(UseSWIG)

	set(target_name "swig_test")
	set(target_sources
		bind.i
	)
	set(dir_bindings "${PROJECT_BINARY_DIR}/bind")

	message(STATUS "SWIG found: ${SWIG_EXECUTABLE}")
	message(STATUS "Generating bindings in: ${dir_bindings}")

	set_source_files_properties(${target_sources}
		PROPERTIES
			CPLUSPLUS TRUE
	)
	swig_add_library(${target_name}
		TYPE SHARED
		LANGUAGE csharp
		SOURCES ${target_sources}
		OUTPUT_DIR ${dir_bindings}
	)
	set_target_properties(${target_name}
		PROPERTIES
			SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE
	)
	target_link_libraries(${target_name}
		PRIVATE
			swiglib
	)
endif ()
