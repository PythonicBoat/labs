package p5.p1;

public class Demo {
    public static void main(String[] args) {
        new Protection(10, 20, 30, 40);
        Derived d = new Derived(100, 200, 300, 400);
        SamePackage s = new SamePackage();
        System.out.println(d); // added this line to use the variable d
        System.out.println(s); // added this line to use the variable s
    }
}