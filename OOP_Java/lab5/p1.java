// WAP in java to create a class Rectangle having data members length and breadth and three methods called read, calculate and display to read the values of length and breadth, calculate the area and perimeter of the rectangle and display the result respectively. 

public class p1 {
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

    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    public double calculateArea() {
        return length * breadth;
    }

    public double calculatePerimeter() {
        return 2 * (length + breadth);
    }

    public void display() {
        System.out.println("Area: " + calculateArea());
        System.out.println("Perimeter: " + calculatePerimeter());
    }
}