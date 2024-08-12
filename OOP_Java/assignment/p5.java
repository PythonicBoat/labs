// 5.	Write a program in java using the concept of user defined exception,  The program will   
//        	 accept the marks of a student from the keyboard, if the (marks <0 or marks >100), the 
//       	 program will throw the necessary exception and handle it. Use thorw, throws 

import java.util.Scanner;

// Define custom exception
class InvalidMarksException extends Exception {
    public InvalidMarksException(String message) {
        super(message);
    }
}

public class p5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the marks of the student:");

        try {
            int marks = sc.nextInt();
            if (marks < 0 || marks > 100) {
                throw new InvalidMarksException("Marks must be between 0 and 100");
            }
            System.out.println("Marks entered are valid");
        } catch (InvalidMarksException e) {
            System.out.println(e.getMessage());
        }
    }
}