// Finally Block

package lab8;

public class p5 {
    public static void main(String[] args) {
        try {
            int result = 10 / 2; // This will throw an ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Caught an exception: " + e.getMessage());
        } finally {
            System.out.println("This will always be printed, regardless of whether an exception was thrown.");
        }
    }
}
