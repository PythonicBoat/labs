// Display the sum of 10 numbers using for each loop in java

import java.io.*;

public class p4 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter numbers separated by spaces:");
        String[] input = reader.readLine().split(" ");
        int sum = 0;
        for (String num : input) {
            sum += Integer.parseInt(num);
        }
        System.out.println("Sum of numbers: " + sum);
    }
}
