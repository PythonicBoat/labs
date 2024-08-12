// WAP using inheritance to show how to call the base class paramterized constructor from the derived class using super.

class Base {
    int num;

    Base(int num) {
        this.num = num;
    }
}

class Derived extends Base {
    Derived(int num) {
        super(num);
    }

    void display() {
        System.out.println("The value of num in the base class is: " + num);
    }
}

public class p1 {
    public static void main(String[] args) {
        Derived d = new Derived(10);
        d.display();
    }
}