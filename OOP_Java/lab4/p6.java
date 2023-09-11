// WAP in java which will display the working of static block.

public class p6 {
    static int a = 10;
    static {
        System.out.println("a = " + a);
        a = 20;
        System.out.println("a = " + a);
    }
    public static void main(String[] args) {
        System.out.println("a = " + a);
        a = 30;
        System.out.println("a = " + a);
    }
}
