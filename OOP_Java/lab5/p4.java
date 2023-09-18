// Sequence of constructor invocation in case of multi level inheritance. Illustrate the execution of constructors in multi-level inheritance with three java classes. 

class A {
    A() {
        System.out.println("Constructor of class A");
    }
}

class B extends A {
    B() {
        System.out.println("B extends A");
        System.out.println("Constructor of class B");
    }
}

class C extends B {
    C() {
        System.out.println("C extends B");
        System.out.println("Constructor of class C");
    }
}

public class p4 {
    public static void main(String[] args) {
        C c = new C();
    }
}