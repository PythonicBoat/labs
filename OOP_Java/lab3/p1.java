// WAP to find even and odd, total no. of even, grand total and sum of even and odd 

import java.io.*;

public class p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int totalEven = 0;
        int totalOdd = 0;
        int grandTotal = 0;
        int sumEven = 0;
        int sumOdd = 0;

        while (true) {
            System.out.print("Enter an integer (0 to exit): ");
            int num = Integer.parseInt(reader.readLine());

            if (num == 0) {
                break;
            }

            grandTotal += num;

            if (num % 2 == 0) {
                totalEven++;
                sumEven += num;
            } else {
                totalOdd++;
                sumOdd += num;
            }
        }

        System.out.println("Total even numbers: " + totalEven);
        System.out.println("Total odd numbers: " + totalOdd);
        System.out.println("Grand total: " + grandTotal);
        System.out.println("Sum of even numbers: " + sumEven);
        System.out.println("Sum of odd numbers: " + sumOdd);
    }
}