// Write a program in Java to take first name and last name from user and print both in one line as last name followed by first name.

import java.util.Scanner;

public class save {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your first name: ");
        String fname = sc.nextLine();
        System.out.println("Enter your last name: ");
        String fsurname = sc.nextLine();
        System.out.println("Your full name is: " + fname + " " + fsurname);
    }
}
