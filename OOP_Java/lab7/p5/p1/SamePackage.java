package p5.p1;

public class SamePackage {
    public SamePackage() {
        Protection obj = new Protection(1, 2, 3, 4);
        System.out.println("Values in SamePackage class constructor:");
        System.out.println("Public: " + obj.pub);
        // Private member 'pri' cannot be accessed directly in SamePackage class.
        System.out.println("Protected: " + obj.pro);
        System.out.println("Default: " + obj.defaultValue);
    }
}