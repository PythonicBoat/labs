// Iluustrate the usage of abstract class with following java classes - i) An abstract class 'student' with data member roll no, reg no and a abstract method course().
// ii) A subclass 'kiitian' with course() method implementation.

import java.util.Scanner;

public class p4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rollno: ");
        int rollno = sc.nextInt();
        System.out.print("Enter regno: ");
        int regno = sc.nextInt();
        kiitian k = new kiitian();
        k.rollno = rollno;
        k.regno = regno;
        k.course();
    }

    abstract static class student{
        int rollno;
        int regno;
        abstract void course();
    }

    static class kiitian extends student {
        void course() {
            System.out.println("I am a kiitian");
            System.out.println("Roll no: " + rollno);
            System.out.println("Reg no: " + regno);
        }
    }
}