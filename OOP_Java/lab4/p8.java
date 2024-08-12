// Write a class file - box with three data members length, width and height. and a method volume(). Also implement the application class Demo where  object of the box class is created with user entered dimensions and volume is printed.

import java.util.Scanner;

class Box {
    int length, width, height;
    void volume() {
        System.out.println("Volume = " + length * width * height);
    }
}

public class p8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Box b = new Box();
        System.out.print("Enter length: ");
        b.length = sc.nextInt();
        System.out.print("Enter width: ");
        b.width = sc.nextInt();
        System.out.print("Enter height: ");
        b.height = sc.nextInt();
        b.volume();
    }
}
