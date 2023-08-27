// 2. Aim of the program:  Write a program to print the corresponding grade for the given 	mark using if..else statement in Java
// Input:  Mention the grade in the program
// Output: Display the Grade either O/E/A/B/C
import java.util.Scanner;

public class p2 {
    public static void main(String[] args) {
        Scanner sc = new scanner(System.in) {
            System.out.print("Enter mark: ");
            if (mark >= 90) {
                System.out.println("O");
            } else if (mark >= 80) {
                System.out.println("E");
            } else if (mark >= 70) {
                System.out.println("A");
            } else if (mark >= 60) {
                System.out.println("B");
            } else if (mark >= 50) {
                System.out.println("C");
            } else {
                System.out.println("F");
            }
        }
    }
}
