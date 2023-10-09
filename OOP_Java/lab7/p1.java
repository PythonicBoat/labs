// WAP in java which will define an interface called inter having a unction disp() and a class variable int x. Create another class student which will implement the interface and override the body of the method and also access var x without object in the main methods. Try to change the value of x and display the error. 

interface Inter {
    int x = 10; // Class variable (final by default)

    void disp();
}

class Student implements Inter {
    // Override the method disp() defined in the interface.
    @Override
    public void disp() {
        System.out.println("Inside disp() method of Student class");
    }
}

public class p1 {
    public static void main(String[] args) {
        System.out.println("Value of x: " + Inter.x);
        Student student = new Student();
        student.disp();
    }
}
