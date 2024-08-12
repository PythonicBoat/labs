import java.io.*;
import java.util.*;

public class args{
    public static void main(String[] args) {
        int n = args.length;
        int even = 0, odd = 0, s_even = 0, s_odd = 0, g_total = 0, num = 0;
        for (int i = 0; i < n; i++) {
            num = Integer.parseInt(args[i]);
            if (num % 2 == 0) {
                even++;
                s_even += num;
            } else {
                odd++;
                s_odd += num;
            }
        }
        g_total = s_even + s_odd;
        System.out.println("Even Nos : " + even);
        System.out.println("Odd Nos : " + odd);
        System.out.println("Sum of Even : " + s_even);
        System.out.println("Sum of Odd : " + s_odd);
        System.out.println("Total Sum : " + g_total);
    }
}