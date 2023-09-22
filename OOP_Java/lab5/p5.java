// Write a function to use super keyword in java without the creation of objects.

//super class
class Person {
	Person()
	{
		System.out.println("Person class Constructor");
	}
}
 
//subclass extends superclass
class Student extends Person {
	Student()
	{
		//call parent class
		super();

		System.out.println("Student class Constructor");
	}
}

class p5 {
	public static void main(String[] args)
	{
		Student s = new Student();
	}
}
