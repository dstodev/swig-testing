#include <gtest/gtest.h>
#include <myclass.hxx>


TEST(MyClass, instance)
{
	MyClass c;
	(void) c;
}

TEST(MyClass, value)
{
	MyClass c;
	ASSERT_EQ(0, c.value());

	c.value(11);
	ASSERT_EQ(11, c.value());
}
