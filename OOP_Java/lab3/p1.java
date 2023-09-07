// WAP to find even and odd, total no. of even and odd, grand total and sum of even and odd using InputStreamReader and Buffered Reader.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int evenCount = 0;
        int oddCount = 0;
        int evenSum = 0;
        int oddSum = 0;
        int grandTotal = 0;

        System.out.print("Enter the number of elements: ");
        int n = Integer.parseInt(br.readLine());

        int[] numbers = new int[n];

        System.out.println("Enter the elements:");

        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
            grandTotal += numbers[i];

            if (numbers[i] % 2 == 0) {
                evenCount++;
                evenSum += numbers[i];
            } else {
                oddCount++;
                oddSum += numbers[i];
            }
        }

        System.out.println("Even numbers: " + evenCount);
        System.out.println("Odd numbers: " + oddCount);
        System.out.println("Total numbers: " + n);
        System.out.println("Grand total: " + grandTotal);
        System.out.println("Sum of even numbers: " + evenSum);
        System.out.println("Sum of odd numbers: " + oddSum);
    }
}