#ifndef MYLIB_MYCLASS_HXX
#define MYLIB_MYCLASS_HXX


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


#endif  // MYLIB_MYCLASS_HXX
