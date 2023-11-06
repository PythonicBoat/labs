// Multiple catch

package lab8;

public class p4 {
    public static void main(String[] args) {
        try {
        } catch (ArithmeticException | NullPointerException e) {
            // handle ArithmeticException and NullPointerException
            System.out.println("Exception caught: " + e);
        }
    }
}
