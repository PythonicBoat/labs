// Write a program to find even and odd, total no. of even and odd, grand total and sum of even and odd.

import java.util.Scanner;

public class p7_sumtype {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int even = 0, odd = 0, sum_even = 0, sum_odd = 0;
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements: ");
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
            if(arr[i]%2==0) {
                even++;
                sum_even += arr[i];
            }
            else {
                odd++;
                sum_odd += arr[i];
            }
        }
        System.out.println("Total even numbers: "+even);
        System.out.println("Total odd numbers: "+odd);
        System.out.println("Grand total: "+(even+odd));
        System.out.println("Sum of even numbers: "+sum_even);
        System.out.println("Sum of odd numbers: "+sum_odd);
    }
}