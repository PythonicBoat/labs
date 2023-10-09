// Write a program in java which will implements the the use of all access specifier in java. Package p1 -class protection- having 4 variable - pub, pri, pro and default and having a constructor which will display the value Class derive extends protection and display all the possible values Class samepackage which will crease the object of class protecton and display all possible values Class Demo having the main function and in the constructor create the object of Protection, Derived and SamePackge Package p2 class protecton 2 extends pl.protection and display all possible values Otherpackage having a constructor and display values Class Demo2 having the main function and create the objecto of Protecton2 and otherpkg and disply all the possible values


package com.p5;

import p1.Protection;
import p1.Derive;
import p1.SamePackage;
import p2.Protection2;
import p2.OtherPackage;

public class p5 {

    public static void main(String[] args) {
        // Create objects of all classes
        Protection protection = new Protection();
        Derive derive = new Derive();
        SamePackage samePackage = new SamePackage();
        Protection2 protection2 = new Protection2();
        OtherPackage otherPackage = new OtherPackage();

        // Display values of all variables
        protection.display();
        derive.display();
        samePackage.display(protection);
        protection2.display();
        otherPackage.display(protection2);
    }
}
