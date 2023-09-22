// Do program 5 but in demo class create the reference object of shape class, initialize that object with circle and rectangle class and call the methods

import java.util.Scanner;

abstract class Shape {
    abstract double calcArea();
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    double calcArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    double length;
    double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    double calcArea() {
        return length * width;
    }
}

class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius of circle: ");
        double radius = sc.nextDouble();
        System.out.print("Enter length of rectangle: ");
        double length = sc.nextDouble();
        System.out.print("Enter width of rectangle: ");
        double width = sc.nextDouble();

        Circle myCircle = new Circle(radius);
        Rectangle myRectangle = new Rectangle(length, width);
    
        Shape myShape = myCircle;
        System.out.println("Area of circle: " + myShape.calcArea());

        myShape = myRectangle;
        System.out.println("Area of rectangle: " + myShape.calcArea());
    }
}