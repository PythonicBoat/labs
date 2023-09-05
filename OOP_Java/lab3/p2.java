import java.io.*;

public class p2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Accepting student details
        System.out.print("Enter student roll no: ");
        int rollNo = Integer.parseInt(br.readLine());

        System.out.print("Enter student name: ");
        String name = br.readLine();

        System.out.print("Enter marks in subject 1: ");
        int sub1 = Integer.parseInt(br.readLine());

        System.out.print("Enter marks in subject 2: ");
        int sub2 = Integer.parseInt(br.readLine());

        System.out.print("Enter marks in subject 3: ");
        int sub3 = Integer.parseInt(br.readLine());

        System.out.print("Enter marks in subject 4: ");
        int sub4 = Integer.parseInt(br.readLine());

        // Calculating total marks and grade
        int totalMarks = sub1 + sub2 + sub3 + sub4;
        double percentage = (double) totalMarks / 4;
        String grade;

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

        // Displaying student details and grade
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Marks in Subject 1: " + sub1);
        System.out.println("Marks in Subject 2: " + sub2);
        System.out.println("Marks in Subject 3: " + sub3);
        System.out.println("Marks in Subject 4: " + sub4);
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Percentage: " + percentage);
        System.out.println("Grade: " + grade);
    }
}