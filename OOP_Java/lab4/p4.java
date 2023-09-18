// WAP in java which shows the working of static variable.

class Example {
    static int staticVariable = 0;
    int instanceVariable = 0;

    Example() {
        staticVariable++;
        instanceVariable++;
    }

    static void display() {
        System.out.println("Static Variable: " + staticVariable);
    }

    void show() {
        System.out.println("Instance Variable: " + instanceVariable);
    }
}

public class p4 {
    public static void main(String[] args) {
        Example obj1 = new Example();
        Example.display();  // Displaying static variable
        obj1.show();        // Displaying instance variable

        Example obj2 = new Example();
        Example.display();  // Displaying static variable
        obj2.show();        // Displaying instance variable
    }
}
