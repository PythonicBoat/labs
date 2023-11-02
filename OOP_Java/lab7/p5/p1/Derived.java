package p5.p1;

public class Derived extends Protection {
    public Derived(int pub, int pri, int pro, int defaultValue) {
        super(pub, pri, pro, defaultValue);
        System.out.println("Values in Derived class constructor:");
        System.out.println("Public: " + pub);
        // Private member 'pri' cannot be accessed directly in Derived class.
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + defaultValue);
    }
}