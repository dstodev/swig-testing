using System;

class Project {
	static int Main(string[] args) {

		var mc = new MyClass();

		Console.WriteLine("Before set: {0}", mc.value());

		mc.value(10);

		Console.WriteLine("After set: {0}", mc.value());

		return 0;
	}
}
