// Write a Java program to find GCD and LCM of two numbers?

import java.util.Scanner;

public class p2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        System.out.println("GCD of " + a + " and " + b + " is " + gcd(a, b));
        System.out.println("LCM of " + a + " and " + b + " is " + lcm(a, b));
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
}