// Write a class Account containing acc no balance as data members and two methods as input() for taking user inut from user and disp() method to display the details. Create a subclass Person which has name and aadhar no as extra data members and override disp() function. Write the complete program to take and print details of three persons.

import java.util.Scanner;

class Account {
    int accNo;
    double balance;

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter account number: ");
        accNo = sc.nextInt();
        System.out.print("Enter balance: ");
        balance = sc.nextDouble();
    }

    void disp() {
        System.out.println("Account number: " + accNo);
        System.out.println("Balance: " + balance);
    }
}

class Person extends Account {
    String name;
    long aadharNo;

    @Override
    void disp() {
        super.disp();
        System.out.println("Name: " + name);
        System.out.println("Aadhar number: " + aadharNo);
    }
}

public class p6 {
    public static void main(String[] args) {
        Person[] persons = new Person[args.length];

        for (int i = 0; i < persons.length; i++) {
            persons[i] = new Person();
            persons[i].input();
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter name: ");
            persons[i].name = sc.nextLine();
            System.out.print("Enter Aadhar number: ");
            persons[i].aadharNo = sc.nextLong();
        }

        for (Person person : persons) {
            person.disp();
        }
    }
}