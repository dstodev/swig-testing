
#[[
	Build target 'mylib' at configure time, so that SWIG can generate C#-binding sources.
]]
set(dir_bind_input ${CMAKE_CURRENT_LIST_DIR}/mylib)
set(dir_bind_output ${PROJECT_BINARY_DIR}/bind)

file(MAKE_DIRECTORY ${dir_bind_output})

execute_process(
	COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -A "${CMAKE_GENERATOR_PLATFORM}" ${dir_bind_input}
	WORKING_DIRECTORY ${dir_bind_output}
	RESULT_VARIABLE status
)
if (status)
	message(FATAL_ERROR "Could not generate bindings!")
endif ()

execute_process(
	COMMAND ${CMAKE_COMMAND} --build ${dir_bind_output}
	WORKING_DIRECTORY ${dir_bind_output}
	RESULT_VARIABLE status
)
if (status)
	message(FATAL_ERROR "Could not build bindings!")
endif ()

#[[
	Imports targets:
		swig::shared
]]
include(${dir_bind_output}/cmake/bind.cmake)

set(target_name csbind)

file(GLOB target_sources CONFIGURE_DEPENDS ${dir_bind_output}/generated/*.cs)

add_library(${target_name}
	SHARED
		${target_sources}
)
set_target_properties(${target_name}
	PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)
add_custom_command(TARGET ${target_name}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:swig::shared>
		$<TARGET_FILE_DIR:${target_name}>
)
