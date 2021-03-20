#include "api.hxx"

using std::size_t;


void make_classes(size_t n, MyClass ** out_array, size_t * out_array_len)
{
	const bool parameters_valid = (n > 0 && out_array != nullptr && out_array_len != nullptr);

	if (parameters_valid) {
		*out_array = new MyClass[n];
		*out_array_len = n;
	}
}

void destroy_classes(MyClass ** inout_array, std::size_t * inout_array_len)
{
	const bool parameters_valid = (inout_array != nullptr && inout_array_len != nullptr);

	if (parameters_valid) {
		delete[](*inout_array);
		*inout_array = nullptr;
		*inout_array_len = 0;
	}
}
