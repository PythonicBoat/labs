// WAP in java showing the working of bitwise and ternary operator

public class p8 {
    public static void main(String[] args) {
        // Bitwise AND operator
        int x = 5; // 0101 in binary
        int y = 3; // 0011 in binary
        int z = x & y; // 0001 in binary
        System.out.println("x & y: " + z);

        // Bitwise OR operator
        z = x | y; // 0111 in binary
        System.out.println("x | y: " + z);
        
        // Ternary operator
        int a = 10;
        int b = 20;
        int max = (a > b) ? a : b; // if a > b, max = a, otherwise max = b
        System.out.println("max: " + max);
    }
}