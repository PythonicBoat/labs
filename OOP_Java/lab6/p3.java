// Program on Dynamic Method dispatch.

public class p3 {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        C c = new C();
        A r;
        r = a;
        r.callme();
        r = b;
        r.callme();
        r = c;
        r.callme();
    }        

    static class A {
        void callme() {
            System.out.println("Inside A's callme method");
        }
    }

    static class B extends A {
        void callme() {
            System.out.println("Inside B's callme method");
        }
    }

    static class C extends B {
        void callme() {
            System.out.println("Inside C's callme method");
        }
    }
}