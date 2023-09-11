// Program on default constructor and parameterized constructor

class Person {
    String name;
    int age;

    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
    }

    // Parameterized constructor
    Person(String n, int a) {
        name = n;
        age = a;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class p7 {
    public static void main(String[] args) {
        // Creating objects using default constructor
        Person p1 = new Person();
        Person p2 = new Person();

        // Creating objects using parameterized constructor
        Person p3 = new Person("John", 25);
        Person p4 = new Person("Jane", 30);

        // Displaying details of all persons
        System.out.println("Details of p1:");
        p1.display();

        System.out.println("Details of p2:");
        p2.display();

        System.out.println("Details of p3:");
        p3.display();

        System.out.println("Details of p4:");
        p4.display();
    }
}