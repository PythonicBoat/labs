// Write a program to display sum of two variables by taking input from user. 

import java.util.Scanner;

public class p4_user {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = sc.nextInt();
        System.out.print("Enter the second number: ");
        int b = sc.nextInt();
        int c = a+b;
        System.out.println("The sum is: "+c);
    }
}