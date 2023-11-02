class Parent {
    int value = 5;

    public void display() {
        System.out.println("Value from Parent: " + value);
    }
}

class Child extends Parent {
    int value; // This shadows the value in Parent class

    public void display() {
        super.display(); // Calls the display() method of the superclass
        System.out.println("Value from Child: " + value);
    }
}

class supereg {
    public static void main(String[] args) {
        Child c = new Child();
        c.value = 10;
        c.display();
    }
}