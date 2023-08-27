// 1.	Aim of the program - Write a program to print your name, roll no, section and branch in separate lines.
// Input:  	Mention Name, Roll no, Section and branch 
// Output:	Display Name
//    	    Display Roll No
//   	    Display Section
//   	    Display Branch

import java.util.Scanner;

public class p1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            System.out.print("Enter Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Roll No.: ");
            int roll = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter Section: ");
            String section = sc.nextLine();
            System.out.print("Enter Branch: ");
            String branch = sc.nextLine();
            System.out.println(name);
            System.out.println(roll);
            System.out.println(section);
            System.out.println(branch);
    }
}
