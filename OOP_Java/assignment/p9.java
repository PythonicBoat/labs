// 9.	Write a program in java to define a class Shape which has data member „area‟ and a
// member function showArea(). Derive two classes Circle and Rectangle from Shape
// class. Add appropriate data members and member functions to calculate and display
// the area of Circle and Rectangle.

class Shape {
    double area;

    void showArea() {
        System.out.println("Area = " + area);
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
        area = Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    double length, breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
        area = length * breadth;
    }
}

public class p9 {
    public static void main(String[] args) {
        Circle c = new Circle(10);
        Rectangle r = new Rectangle(10, 20);
        c.showArea();
        r.showArea();
    }
}