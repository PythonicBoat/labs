// Program on default constructor and parameterized constructor

class MyClass {
    int number;

    // Default Constructor
    MyClass() {
        number = 0; // Initialize number to a default value
    }

    // Parameterized Constructor
    MyClass(int num) {
        number = num; // Initialize number with the provided value
    }

    void displayNumber() {
        System.out.println("Number: " + number);
    }
}

public class p7 {
    public static void main(String[] args) {
        MyClass obj1 = new MyClass(); // Calls the default constructor
        obj1.displayNumber(); // Output: Number: 0

        MyClass obj2 = new MyClass(42); // Calls the parameterized constructor with value 42
        obj2.displayNumber(); // Output: Number: 42
    }
}
