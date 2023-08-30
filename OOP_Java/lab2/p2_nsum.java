// WAP in java which will acccept N number of argument from commandline and display the sum

public class p2_nsum {
    public static void main(String args[]) {
        String str[] = new String[args.length];
        for (int i = 0; i < args.length; i++) {
            str[i] = args[i];
        }
        int arr[] = new int[str.length];
        for (int i = 0; i < str.length; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        System.out.println("Sum is: " + sum);
    }
}
