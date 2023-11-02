abstract class Shape {
    double dim1;
    double dim2;

    Shape(double a, double b) {
        dim1 = a;
        dim2 = b;
    }

    abstract double area();
}

class Rectangle extends Shape {
    Rectangle(double a, double b) {
        super(a, b);
    }

    double area() {
        System.out.println("Inside area for rectangle.");
        return dim1 * dim2;
    }
}

class Triangle extends Shape {
    Triangle(double a, double b) {
        super(a, b);
    }

    double area() {
        System.out.println("Inside area for triangle.");
        return dim1 * dim2 / 2;
    }
}

public class p2 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(7, 3);
        double area = r.area();
        System.out.println("Area of rectangle: " + area);

        Triangle t = new Triangle(7, 3);
        area = t.area();
        System.out.println("Area of triangle: " + area);
    }
}


// import java.io.*;
// import java.util.*;

// abstract class shape {
//     double dim1();
//     double dim2();

//     shape (double a, double b) {
//         dim1 = a;
//         dim2 = b;
//     }
// }

// class rectangle extends shape {
//     rectangle (double a, double b) {
//         super(a, b);
//     }

//     double area() {
//         System.out.println("Inside area for rectangle.");
//         return dim1 * dim2;
//     }
// }

// class triangle extends shape {
//     triangle (double a, double b) {
//         super(a, b);
//     }

//     double area() {
//         System.out.println("Inside area for triangle.");
//         return dim1 * dim2 / 2;
//     }
// }
