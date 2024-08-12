import java.math.BigInteger;
import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter number of elements : ");
        int n = sc.nextInt();
        
        int[] arr = new int[n];

        System.out.println("Enter elements : ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        sc.close();
        if (n < 2) {
            System.out.println("Not enough elements to find second smallest and largest");
            return;
        }

        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            if (arr[i] < smallest) {
                secondSmallest = smallest;
                smallest = arr[i];
            } else if (arr[i] < secondSmallest && arr[i] != smallest) {
                secondSmallest = arr[i];
            }

            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }

        System.out.println("Second smallest element : " + secondSmallest);
        System.out.println("Second largest element : " + secondLargest);

        int startTime = 0;
        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;   
        long nsTime = totalTime / 1000000000;
        System.out.println("Total time : "+ nsTime/1000 + " ms");   
    }
}
