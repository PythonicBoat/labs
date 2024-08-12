// WAP in java which will accept the student RollNo, Name, marks of four subjects using InputStreamReader and BufferedReader and finally display the grade of the students.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p2 {
    private static int rollNo;
    private static String name;
    private static int subject1, subject2, subject3, subject4;
    private static int totalMarks;
    private static double percentage;
    private static String grade;

    public static void main(String[] args) throws IOException {
        acceptDetails();
        calculateGrade();
        displayDetails();
    }

    private static void acceptDetails() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter RollNo: ");
        rollNo = Integer.parseInt(br.readLine());

        System.out.print("Enter Name: ");
        name = br.readLine();
        
        for (int i=0; i<4; i++) {
            System.out.print("Enter marks of subject " + (i+1) + ": ");
            int marks = Integer.parseInt(br.readLine());
            switch (i) {
                case 0:
                    subject1 = marks;
                    break;
                case 1:
                    subject2 = marks;
                    break;
                case 2:
                    subject3 = marks;
                    break;
                case 3:
                    subject4 = marks;
                    break;
            }
        }
    }

    private static void calculateGrade() {
        totalMarks = subject1 + subject2 + subject3 + subject4;
        percentage = (double) totalMarks / 4;

        if (percentage >= 90) {
            grade = "O";
        } else if (percentage >= 80) {
            grade = "E";
        } else if (percentage >= 70) {
            grade = "A";
        } else if (percentage >= 60) {
            grade = "B";
        } else if (percentage >= 50) {
            grade = "C";
        } else {
            grade = "D";
        }
    }

    private static void displayDetails() {
        System.out.println("RollNo: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Percentage: " + percentage);
        System.out.println("Grade: " + grade);
    }
}