// WAP in java using constructor overloading concept to calculate the area of a rectangle having data member as length and breadth. Use default constructor to initialize the value of the data member to zero and parameterized constructor to initialize the value of data member according to the user input.

public class p2 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.display();
    }
}

class Rectangle {
    double length;
    double breadth;

    Rectangle() {
        System.out.println("Accept length and breadth:");
        length = Double.parseDouble(System.console().readLine());
        breadth = Double.parseDouble(System.console().readLine());
    }

    public void display() {
        System.out.println("Area: " + area());
    }

    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
}
