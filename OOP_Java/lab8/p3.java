// Array Index out of bounds

package lab8;

public class p3 {
    public static void main(String[] args) {
        int[] array = new int[5];
        // accessing element at index at 5, while supported are indices 0-4
        System.out.println(array[5]);
    }
}
