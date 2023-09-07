// WAP in java showing the scope of a variable

public class p6 {
    public static void main(String[] args) {
        int x = 10; // x is declared and initialized in the main method
        if (x == 10) {
            int y = 20; // y is declared and initialized in the if block
            System.out.println("x and y: " + x + " " + y);
            y = 30; // y is reassigned a new value
            System.out.println("x and y: " + x + " " + y); // print statement showing the changes
        }
        // y is not visible here because it was declared in the if block
        System.out.println("x: " + x);
    }
}