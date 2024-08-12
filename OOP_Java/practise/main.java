// import java.io.*;
// import java.util.*;

// public class main {
//     public static void main(String args[]) {
//         int n;
//         n = args.length();
//         for (int i=0; i<n; i++) {
//             int a[i] = args[i].parseint();
//         }

//         Scanner sc = new Scanner(System.in);

//         System.out.println("Pass Argument: ");
//         int b = sc.nextInt();
//         System.out.println("Arguments a and b are"+a+" "+b);
//     }
// }

// import java.io.*;
// import java.util.*;

// class main{
//     private double l;
//     private double b;

//     public class area (double length, double breadth)
//     {
//         l = this.length;
//         b = this.breadth;
//     }

// }

// public class main {
//     public static void main(String[] args) {
//         int n;
//         n = args.length;
//         int[] a = new int[n];
//         for (int i=0; i<n; i++) {
//             a[i] = Integer.parseInt(args[i]);
//         }

//         Scanner sc = new Scanner(System.in);

//         System.out.println("Pass Argument: ");
//         int b = sc.nextInt();
//         System.out.println("Arguments a and b are "+ Arrays.toString(a) +" "+b);
//     }
// }


interface Calculate {
    double calculateInterest();
}

class HDFC implements Calculate {
    private double principal;
    private double years;
    private double roi;

    HDFC(double p, double y, double r) {
        this.principal = p;
        this.years = y;
        this.roi = r;
    }

    public double calculateInterest() {
        return principal * years * roi;
    }
}