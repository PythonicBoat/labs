// WAP in java which will display the working of static methods

class Example {
    static int count = 0; // Static variable

    static void incrementCount() { // Static method
        count++;
    }

    void displayCount() { // Non-static method
        System.out.println("Count: " + count);
    }
}

public class p5 {
    public static void main(String[] args) {
        Example.incrementCount(); // Calling static method using class name
        Example.incrementCount(); // Count will be 2 now

        Example obj1 = new Example();
        Example obj2 = new Example();

        obj1.displayCount(); // Count: 2
        obj2.displayCount(); // Count: 2

        Example.incrementCount(); // Count will be 3

        obj1.displayCount(); // Count: 3
        obj2.displayCount(); // Count: 3
    }
}
