// 1.  Prog on userdefined exception - like accept your marks and check whether marks is < 0 or  >100, if so throw one userdefined exception otherwise show the marks

import java.util.Scanner;

class InvalidMarksException extends Exception {
    public InvalidMarksException(String message) {
        super(message);
    }
}

public class p1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your marks:");
        int marks = sc.nextInt();

        try {
            if (marks < 0 || marks > 100) {
                throw new InvalidMarksException("Marks must be between 0 and 100.");
            } else {
                System.out.println("Your marks: " + marks);
            }
        } catch (InvalidMarksException e) {
            e.printStackTrace();
		}
	}
}
