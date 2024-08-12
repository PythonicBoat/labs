// WAP in java using the working of break and continue keyword.

public class p5 {
    public static void main(String[] args) {
        // Example of break keyword
        for (int i = 1; i <= 10; i++) {
            if (i == 5) {
                break; // Exit the loop when i is 5
            }
            System.out.print(i + " ");
        }
        System.out.println(); // Print a new line

        // Example of continue keyword
        for (int i = 1; i <= 10; i++) {
            if (i == 5) {
                continue; // Skip the iteration when i is 5
            }
            System.out.print(i + " ");
        }
        System.out.println(); // Print a new line
    }
}