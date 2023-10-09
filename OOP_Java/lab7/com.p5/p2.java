import p1.p1;

public class p2 extends p1 {

    public void display() {
        super.display();
    }
}

class OtherPackage {

    public void display(p2 protection2) {
        System.out.println("Public: " + protection2.pub);
        // System.out.println("Private: " + protection2.pri); // Cannot access private member from outside the class
        // System.out.println("Protected: " + protection2.pro); // Cannot access protected member from outside the package
        // System.out.println("Default: " + protection2.def); // Cannot access default member from outside the package
    }
}