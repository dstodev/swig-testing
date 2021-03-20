cmake_policy(SET CMP0078 NEW)  # https://cmake.org/cmake/help/latest/policy/CMP0078.html
cmake_policy(SET CMP0086 NEW)  # https://cmake.org/cmake/help/latest/policy/CMP0086.html

find_package(SWIG 4.0 REQUIRED
	COMPONENTS
		csharp
)

if (SWIG_FOUND)
	include(UseSWIG)

	set(target_name "shared")
	set(target_sources
		bind.i
	)
	set(dir_bindings ${PROJECT_BINARY_DIR}/generated)

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

			OUTPUT_NAME swig

			RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin

	)
	target_link_libraries(${target_name}
		PRIVATE
			mylib
	)
	export(
		TARGETS
			${target_name}

		NAMESPACE swig::
		FILE ${PROJECT_BINARY_DIR}/cmake/bind.cmake
	)
endif ()
