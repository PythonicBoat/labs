// WAP in java which will accept the size of rows and cols of a 2D array and elements form user and display the array in a matrix form.

import java.util.Scanner;

public class p1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Step 1
        System.out.print("Enter the number of rows: ");
        int rows = input.nextInt();
        System.out.print("Enter the number of columns: ");
        int cols = input.nextInt();

        // Step 2
        int[][] matrix = new int[rows][cols];

        // Step 3
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.printf("Enter the element at (%d, %d): ", i, j);
                matrix[i][j] = input.nextInt();
            }
        }

        // Step 4
        System.out.println("The matrix is:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}