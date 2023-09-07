// WAP in java showing immlicit and explicit type conversion. 

public class p7 {
    public static void main(String[] args) {
        // Implicit type conversion
        int x = 10;
        double y = x; // int is implicitly converted to double
        System.out.println("x: " + x);
        System.out.println("y: " + y);

        // Explicit type conversion
        double z = 10.5;
        int w = (int) z; // double is explicitly converted to int
        System.out.println("z: " + z);
        System.out.println("w: " + w);
    }
}