package p5.p2;

import p5.p1.Protection;

public class Protection2 extends Protection {
    public Protection2(int pub, int pri, int pro, int defaultValue) {
        super(pub, pri, pro, defaultValue);
        System.out.println("Values in Protection2 class constructor:");
        System.out.println("Public: " + pub);
        // Private member 'pri' cannot be accessed directly in Protection2 class.
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + defaultValue);
    }
}
