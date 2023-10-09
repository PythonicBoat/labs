public class p1 {

    public int pub;
    private int pri;
    protected int pro;
    int def;

    public p1() {
        pub = 10;
        pri = 20;
        pro = 30;
        def = 40;
    }

    public void display() {
        System.out.println("Public: " + pub);
        System.out.println("Private: " + pri);
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + def);
    }
}

class Derive extends p1 {

    public void display() {
        super.display();
    }
}

class SamePackage {

    public void display(p1 protection) {
        System.out.println("Public: " + protection.pub);
        // System.out.println("Private: " + protection.pri); // Cannot access private member from outside the class
        System.out.println("Protected: " + protection.pro);
        System.out.println("Default: " + protection.def);
    }
}