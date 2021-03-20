#include <gtest/gtest.h>
#include <api.hxx>

using std::size_t;


TEST(API, make_classes_0)
{
	make_classes(0, nullptr, nullptr);  // Exception check
}

TEST(API, make_classes_1)
{
	MyClass * array;
	size_t array_len;

	make_classes(1, &array, &array_len);

	ASSERT_EQ(1, array_len);
	array[0].value();  // Exception check
}

TEST(API, make_classes_2)
{
	MyClass * array;
	size_t array_len;

	make_classes(2, &array, &array_len);

	ASSERT_EQ(2, array_len);
	array[0].value();
	array[1].value();
}

TEST(API, destroy_classes_0)
{
	destroy_classes(nullptr, 0);
}

TEST(API, destroy_classes_1)
{
	MyClass * array;
	size_t array_len;

	make_classes(1, &array, &array_len);
	destroy_classes(&array, &array_len);

	ASSERT_EQ(nullptr, array);
	ASSERT_EQ(0, array_len);
}

TEST(API, destroy_classes_2)
{
	MyClass * array;
	size_t array_len;

	make_classes(2, &array, &array_len);
	destroy_classes(&array, &array_len);

	ASSERT_EQ(nullptr, array);
	ASSERT_EQ(0, array_len);
}
