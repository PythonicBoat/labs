import java.util.Scanner;

public class p2 {
    // Constructor
    public p2(String str) {
        System.out.println("Constructor called with string: " + str);
        // Using toCharArray() in the constructor
        char[] charArray = str.toCharArray();
        System.out.print("Character array from the constructor: ");
        for (char ch : charArray) {
            System.out.print(ch + " ");
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string:");
        String str1 = new String(sc.nextLine());
        System.out.println("Enter another string:");
        String str2 = new String(sc.nextLine());

		System.out.println("\n+All String Classes and Methods==========================+\n");

        // charAt
		System.out.println("Character at index 0 in the first string: " + str1.charAt(0));

		// Length
        System.out.println("Length of first string: " + str1.length());
        System.out.println("Length of second string: " + str2.length());

		// Concatenation
        System.out.println("Concatenation: " + str1.concat(str2));

		// Case change
        System.out.println("First string to uppercase: " + str1.toUpperCase());
        System.out.println("Second string to lowercase: " + str2.toLowerCase());

		// Equality
        System.out.println("Does first string equal second string? " + str1.equals(str2));
		System.out.println("Does first string equal second string? (Ignore Case) " + str1.equalsIgnoreCase(str2));

        // Replace
        System.out.println("Replace 'a' with 'x' in the first string: " + str1.replace('e', 'o'));

		// Substring
        System.out.println("Substring from index 1 to 5 in the first string: " + str1.substring(1, 5));

        // IndexOf
        System.out.println("Index of 'o' in the first string: " + str1.indexOf('o'));

        // LastIndexOf
        System.out.println("Last index of 'l' in the first string: " + str1.lastIndexOf('l'));

        // startsWith
        System.out.println("Does the first string start with 'Enter'? " + str1.startsWith("Enter"));

        // endsWith
        System.out.println("Does the first string end with 'string'? " + str1.endsWith("string"));

		// isEmpty
        System.out.println("String 1 is Empty? - "+str1.isEmpty()+"\nString 2 is Empty? - "+str2.isEmpty());

		// trim
		System.out.println("Trimmed String 1: " + str1.trim());
		System.out.println("Trimmed String 2: " + str2.trim());

        // toCharArray
        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();
        System.out.print("Character array from the first string: ");
        for (char ch : charArray1) {
            System.out.print(ch + " ");
        }
        System.out.println("\nCharacter array from the second string: ");
        for (char ch : charArray2) {
            System.out.print(ch + " ");
        }
        System.out.println("\n");

        // Using the constructor
        p2 obj = new p2("Hello, this is a sample string for the constructor.");

        sc.close();
   }
} //immutable
