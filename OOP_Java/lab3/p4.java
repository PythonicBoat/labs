// Display the sum of 10 numbers using for each loop in java.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] numbers = new int[10];

        System.out.println("Enter 10 numbers:");

        for (int i = 0; i < 10; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
        }

        int sum = 0;

        for (int number : numbers) {
            sum += number;
        }

        System.out.println("Sum of the 10 numbers = " + sum);
    }
}