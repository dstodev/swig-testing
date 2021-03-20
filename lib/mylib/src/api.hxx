#ifndef MYLIB_API_H
#define MYLIB_API_H

#include "myclass.hxx"
#include <cstddef>


extern "C" {
void make_classes(std::size_t n, MyClass ** out_array, std::size_t * out_array_len);
void destroy_classes(MyClass ** inout_array, std::size_t * inout_array_len);
}


#endif
