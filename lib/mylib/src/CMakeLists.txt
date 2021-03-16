add_library(swiglib
	myclass.hxx
	myclass.cxx
)
target_include_directories(swiglib
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)
