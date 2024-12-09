package p8;

import java.util.Scanner;
import p8.shapes.Circle;
import p8.utilities.MathDemo;


public class p8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Circle circle = new Circle();
        System.out.print("Enter radius of the circle: ");
        double radius = scanner.nextDouble();
        
        double area = circle.calculateArea(radius);
        double circumference = circle.calculateCircumference(radius);
        
        System.out.println("Circle Area: " + area);
        System.out.println("Circle Circumference: " + circumference);
        
        MathDemo mathDemo = new MathDemo();
        System.out.print("Enter two integers to find the maximum and minimum: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        
        int max = mathDemo.findMax(num1, num2);
        int min = mathDemo.findMin(num1, num2);
        
        System.out.println("Maximum: " + max);
        System.out.println("Minimum: " + min);
    
        scanner.close();
    }
}