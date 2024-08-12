package otherpackage;

import p5.p1.Protection;
import p5.p2.Protection2;

public class OtherPackage {
    public OtherPackage() {
        Protection obj1 = new Protection(5, 6, 7, 8);
        Protection2 obj2 = new Protection2(50, 60, 70, 80);
        System.out.println("Values in OtherPackage class constructor:");
        System.out.println("Public in Protection: " + obj1.pub);
        // Private member 'pri' cannot be accessed directly in OtherPackage class.
        // Protected member 'pro' cannot be accessed directly in OtherPackage class.
        // System.out.println("Default in Protection: " + obj1.getDefault());
        System.out.println("Public in Protection2: " + obj2.pub);
        // Private member 'pri' cannot be accessed directly in OtherPackage class.
        // Protected member 'pro' cannot be accessed directly in OtherPackage class.
        // System.out.println("Default in Protection2: " + obj2.defaultValue());
    }
}
