// Create an Abstract class shape with an abstract method calcArea(). Derive two classes Circle and Rectangle and override the display area methods. Create another class Demo which will create the object of circle and rectangle and call the calcArea() methods.

import java.util.Scanner;

abstract class Shape {
    abstract void calcArea();
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    void calcArea() {
        System.out.println("Area of circle: " + Math.PI * radius * radius);
    }
}

class Rectangle extends Shape {
    double length, breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    void calcArea() {
        System.out.println("Area of rectangle: " + length * breadth);
    }
}

class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius of circle: ");
        double radius = sc.nextDouble();
        System.out.print("Enter length of rectangle: ");
        double length = sc.nextDouble();
        System.out.print("Enter breadth of rectangle: ");
        double breadth = sc.nextDouble();
        Circle myCircle = new Circle(radius);
        Rectangle myRectangle = new Rectangle(length, breadth);

        myCircle.calcArea();
        myRectangle.calcArea();
    }
}

public class p5 {
    public static void main(String[] args) {
        Demo.main(args);
    }
}