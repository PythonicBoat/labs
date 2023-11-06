// Nested Try Catch

package lab8;

public class p6 {
    public static void main(String[] args) {
        try {
            int[] arr = new int[5];
            System.out.println(arr[10]); // This will throw ArrayIndexOutOfBoundsException

            try {
                int division = 10 / 0; // This will throw ArithmeticException
                System.out.println("This line will not be executed");
            } catch (ArithmeticException e) {
                System.out.println("ArithmeticException caught in nested try block");
            }

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException caught in outer try block");
        }
    }
}
