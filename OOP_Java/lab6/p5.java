// Create an Abstract class shape with an abstract method calcArea(). Derive two classes Circle and Rectangle and override the display area methods. Create another class Demo which will create the object of circle and rectangle and call the calcArea() methods.

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
class Demo {
    public static void main(String[] args) {
        Circle circle = new Circle(5);  // Creating a circle object with radius 5
        Rectangle rectangle = new Rectangle(4, 6);  // Creating a rectangle object with length 4 and width 6

        double circleArea = circle.calcArea();
        double rectangleArea = rectangle.calcArea();

        System.out.println("Area of the circle: " + circleArea);
        System.out.println("Area of the rectangle: " + rectangleArea);
    }
}
