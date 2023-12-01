// 8.	Write a program in java using inheritance to show how to call the base class parameterized constructors from the derived class using super.

// Base class
class Base {
    int number;

    // Parameterized constructor
    Base(int number) {
        this.number = number;
    }
}

// Derived class
class Derived extends Base {
    int anotherNumber;

    // Parameterized constructor
    Derived(int number, int anotherNumber) {
        super(number);  // Calling the base class constructor
        this.anotherNumber = anotherNumber;
    }

    void display() {
        System.out.println("Number = " + number);
        System.out.println("Another Number = " + anotherNumber);
    }
}

// Main class
public class p8 {
    public static void main(String[] args) {
        Derived d = new Derived(10, 20);
        d.display();
    }
}