// WAP in java to define a class Shape which has data member 'area' and a member function showArea(). Derive to classes Circle and Rectangle from shape class. Add approriate data members and member functions to calculate and display the area of circle and rectangle.

public class p2 {
    public static void main(String[] args) {
        Circle c = new Circle(5);
        Rectangle r = new Rectangle(5, 10);
        c.displayArea();
        r.displayArea();
    }
}

abstract class Shape {
    double area;

    Shape(double area) {
        this.area = area;
    }

    void showArea() {
        System.out.println("Area: " + area);
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        super(Math.PI * radius * radius);
        this.radius = radius;
    }

    void displayArea() {
        System.out.println("Circle");
        showArea();
    }
}

class Rectangle extends Shape {
    double length, breadth;

    Rectangle(double length, double breadth) {
        super(length * breadth);
        this.length = length;
        this.breadth = breadth;
    }

    void displayArea() {
        System.out.println("Rectangle");
        showArea();
    }
}
