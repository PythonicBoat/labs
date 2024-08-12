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

// class demo

class Demo {
    public static void main(String[] args) {
        Shape circle = new Circle(5);  // Creating a circle object with radius 5
        Shape rectangle = new Rectangle(4, 6);  // Creating a rectangle object with length 4 and width 6

        double circleArea = circle.calcArea();
        double rectangleArea = rectangle.calcArea();

        System.out.println("Area of the circle: " + circleArea);
        System.out.println("Area of the rectangle: " + rectangleArea);
    }
}