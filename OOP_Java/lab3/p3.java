// Create a menu driven program as follows:
// A. Addition of two numbers
// B. Subtraction of two numbers
// C. Multiplication of two numbers
// D. Division of two numbers
// After selecting a particular menu, the program will work accordingly. Finally at the end, the program will also ask the user - Do you want to continue and again start working based on the input of the user.

import java.util.Scanner;

public class p3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char choice;

        do {
            System.out.println("Menu:");
            System.out.println("A. Addition of two numbers");
            System.out.println("B. Subtraction of two numbers");
            System.out.println("C. Multiplication of two numbers");
            System.out.println("D. Division of two numbers");

            System.out.print("Enter your choice: ");
            choice = sc.next().charAt(0);

            switch (choice) {
                case 'A':
                case 'a':
                    System.out.print("Enter first number: ");
                    double num1 = sc.nextDouble();
                    System.out.print("Enter second number: ");
                    double num2 = sc.nextDouble();
                    double sum = num1 + num2;
                    System.out.println("Sum = " + sum);
                    break;

                case 'B':
                case 'b':
                    System.out.print("Enter first number: ");
                    num1 = sc.nextDouble();
                    System.out.print("Enter second number: ");
                    num2 = sc.nextDouble();
                    double diff = num1 - num2;
                    System.out.println("Difference = " + diff);
                    break;

                case 'C':
                case 'c':
                    System.out.print("Enter first number: ");
                    num1 = sc.nextDouble();
                    System.out.print("Enter second number: ");
                    num2 = sc.nextDouble();
                    double product = num1 * num2;
                    System.out.println("Product = " + product);
                    break;

                case 'D':
                case 'd':
                    System.out.print("Enter first number: ");
                    num1 = sc.nextDouble();
                    System.out.print("Enter second number: ");
                    num2 = sc.nextDouble();
                    if (num2 == 0) {
                        System.out.println("Error: Division by zero");
                    } else {
                        double quotient = num1 / num2;
                        System.out.println("Quotient = " + quotient);
                    }
                    break;

                default:
                    System.out.println("Invalid choice");
                    break;
            }

            System.out.print("Do you want to continue? (Y/N): ");
            choice = sc.next().charAt(0);
        } while (choice == 'Y' || choice == 'y');

        sc.close();
    }
}