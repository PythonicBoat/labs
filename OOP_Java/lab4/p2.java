// WAP in java which will create a class called customer having three variable CustID, CustName, CustAge and two methods acceptDetails() and displayDetails(). Create another class called CustomerDemo which will create an array of objects of Customer class and display the details of all the customers.

import java.util.Scanner;

class Customer {
    int CustID;
    String CustName;
    int CustAge;

    void acceptDetails() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Customer ID: ");
        CustID = input.nextInt();
        System.out.print("Enter Customer Name: ");
        CustName = input.next();
        System.out.print("Enter Customer Age: ");
        CustAge = input.nextInt();
    }

    void displayDetails() {
        System.out.println("Customer ID: " + CustID);
        System.out.println("Customer Name: " + CustName);
        System.out.println("Customer Age: " + CustAge);
    }
}

class p2 {
    public static void main(String[] args) {
        Customer[] customers = new Customer[args.length];

        for (int i = 0; i < customers.length; i++) {
            customers[i] = new Customer();
            customers[i].acceptDetails();
        }

        for (int i = 0; i < customers.length; i++) {
            customers[i].displayDetails();
            System.out.println();
        }
    }
}