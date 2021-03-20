set(target_name mylib)

add_library(${target_name}
	myclass.hxx
	myclass.cxx
)
target_include_directories(${target_name}
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)

include(bind.cmake)
