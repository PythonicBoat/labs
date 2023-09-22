// Do program 5 but in demo class create the reference object of shape class, initialize that object with circle and rectangle class and call the methods

// Abstract class Shape
abstract class Shape {
    abstract double calcArea();
}

// Derived class Circle
class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double calcArea() {
        return Math.PI * Math.pow(radius, 2);
    }
}

// Derived class Rectangle
class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    double calcArea() {
        return length * width;
    }
}

// Class Demo
class p6 {
    public static void main(String[] args) {
        Shape shape; // Reference variable of type Shape

        // Creating a circle object with radius 5
        shape = new Circle(5);
        double circleArea = shape.calcArea();
        System.out.println("Area of the circle: " + circleArea);

        // Creating a rectangle object with length 4 and width 6
        shape = new Rectangle(4, 6);
        double rectangleArea = shape.calcArea();
        System.out.println("Area of the rectangle: " + rectangleArea);
    }
}
