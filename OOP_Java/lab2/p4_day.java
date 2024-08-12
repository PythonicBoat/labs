// Program to print the corresponding week day for the given day no. of the current month using switch..case statement in Java

import java.time.LocalDate;
import java.time.format.TextStyle;
import java.util.Locale;

public class p4_day {
    public static void main(String[] args) {
        int dayOfMonth = 27; // Replace with the day number you want to check
        LocalDate date = LocalDate.now().withDayOfMonth(dayOfMonth);
        String dayOfWeek = date.getDayOfWeek().getDisplayName(TextStyle.FULL, Locale.getDefault());
        System.out.println(dayOfWeek);
    }
}

// import java.util.Scanner;

// public class day() {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.println("Enter the day no. of the current month: ");
//         int day = sc.nextInt();
//         switch(day) {
//             case 1: System.out.println("Sunday");
//                     break;
//             case 2: System.out.println("Monday");
//                     break;
//             case 3: System.out.println("Tuesday");
//                     break;
//             case 4: System.out.println("Wednesday");
//                     break;
//             case 5: System.out.println("Thursday");
//                     break;
//             case 6: System.out.println("Friday");
//                     break;
//             case 7: System.out.println("Saturday");
//                     break;
//             default: System.out.println("Invalid day no.");
//         }
//     }
// }