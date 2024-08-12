// WAP in java which will acccept 10 integer from command line argument and display the sum

import java.util.Scanner;

public class p1_cmd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 integer: ");
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int n = sc.nextInt();
            sum += n;
        }
        System.out.println("Sum is: " + sum);
    }
}
