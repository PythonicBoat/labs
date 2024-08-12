// WAP in java which will display the working of static block.

public class p6 {
    {System.out.println("Static block");}
    static int a = 10;

    static {
        System.out.println("a = " + a);
        System.out.println("Static block changed a");
        a = 20;
        System.out.println("a = " + a);
    }
    public static void main(String[] args) {
        System.out.println("a = " + a);
        System.out.println("Main changed a");
        a = 30;
        System.out.println("a = " + a);
    }
}
