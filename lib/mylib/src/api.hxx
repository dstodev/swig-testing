#ifndef MYLIB_API_H
#define MYLIB_API_H

#include "myclass.hxx"


extern "C" {
void make_classes(size_t n, MyClass ** out_array, size_t * out_array_len);
}


#endif
