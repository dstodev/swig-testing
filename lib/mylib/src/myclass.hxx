#ifndef CPPKATA_MYCLASS_HXX
#define CPPKATA_MYCLASS_HXX


class MyClass
{
public:
	MyClass();
	~MyClass();

	void value(int value);
	int value() const;

private:
	int _value;
};


#endif  // CPPKATA_MYCLASS_HXX
