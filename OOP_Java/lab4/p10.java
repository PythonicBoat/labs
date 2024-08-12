// WAP which will overload the area() method and display the area of circle, triangle and square as per user choice and user entered dimensions.

import java.util.Scanner;

class Area {
    void area(int r) {
        System.out.println("Area of circle = " + 3.14 * r * r);
    }
    void area(int l, int b) {
        System.out.println("Area of rectangle = " + l * b);
    }
    void area(int a, int b, int c) {
        int s = (a + b + c) / 2;
        System.out.println("Area of triangle = " + Math.sqrt(s * (s - a) * (s - b) * (s - c)));
    }
}

public class p10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Area a = new Area();
        System.out.println("1. Circle");
        System.out.println("2. Rectangle");
        System.out.println("3. Triangle");
        System.out.print("Enter your choice: ");
        int ch = sc.nextInt();
        switch (ch) {
            case 1:
                System.out.print("Enter radius: ");
                int r = sc.nextInt();
                a.area(r);
                break;
            case 2:
                System.out.print("Enter length: ");
                int l = sc.nextInt();
                System.out.print("Enter breadth: ");
                int b = sc.nextInt();
                a.area(l, b);
                break;
            case 3:
                System.out.print("Enter side 1: ");
                int s1 = sc.nextInt();
                System.out.print("Enter side 2: ");
                int s2 = sc.nextInt();
                System.out.print("Enter side 3: ");
                int s3 = sc.nextInt();
                a.area(s1, s2, s3);
                break;
            default:
                System.out.println("Invalid choice");
        }
    }
}