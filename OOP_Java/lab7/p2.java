// Create an interface INTER-1 having a method disp(). Create a class student who will implement the interface INTER-1 and override the disp() method. The class have their own methods called nonIFaceMethod() also.
// Create the object of the class and call the both the methods. Also create a reference object of the interface and allocate memory to the class type. And then try to call both the methods. Also display error.

interface INTER1 {
    void disp();
}

class Student implements INTER1 {
    @Override
    public void disp() {
        System.out.println("Inside disp() method of Student class");
    }

    public void nonIFaceMethod() {
        System.out.println("Inside nonIFaceMethod() method of Student class");
    }
}

public class p2 {
    public static void main(String[] args) {
        // Create an object of the class and call both the methods.
        Student student = new Student();
        student.disp();
        student.nonIFaceMethod();

        INTER1 interfaceRef = new Student();
        interfaceRef.disp(); // This works because it's defined in the interface.

        System.out.println("Error: nonIFaceMethod() cannot be called through the interface reference.");
    }
}
