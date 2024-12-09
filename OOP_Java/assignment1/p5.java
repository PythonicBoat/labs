import java.util.Scanner;

class Matrix2D {
    int row, column;
    int[][] matrix;

    Matrix2D(int row, int column) {
        this.row = row;
        this.column = column;
        matrix = new int[row][column];
    }

    void setElement(int row, int column, int value) {
        matrix[row][column] = value;
    }

    Matrix2D add(Matrix2D b) {
        Matrix2D c = new Matrix2D(row, column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                c.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
        return c;
    }

    Matrix2D subtract(Matrix2D b) {
        Matrix2D c = new Matrix2D(row, column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                c.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
        return c;
    }

    Matrix2D multiply(Matrix2D b) {
        Matrix2D c = new Matrix2D(row, b.column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < b.column; j++)
                for (int k = 0; k < column; k++)
                    c.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
        return c;
    }

    void print() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
    }
}

public class p5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Matrix2D a = new Matrix2D(2, 2);
        Matrix2D b = new Matrix2D(2, 2);
        Matrix2D c;

        System.out.println("Enter elements for matrix a:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("a[" + i + "][" + j + "]: ");
                a.setElement(i, j, scanner.nextInt());
            }
        }

        System.out.println("Enter elements for matrix b:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("b[" + i + "][" + j + "]: ");
                b.setElement(i, j, scanner.nextInt());
            }
        }

        System.out.println("Matrix Addition:");
        c = a.add(b);
        c.print();
        System.out.println("Matrix Subtraction:");
        c = a.subtract(b);
        c.print();
        System.out.println("Matrix Multiplication:");
        c = a.multiply(b);
        c.print();

        scanner.close();
    }
}