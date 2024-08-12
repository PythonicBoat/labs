// 1.	Accept a String and a character from the keyboard and do the following operations
// 	i.	convert the string in upper case
// 	ii.	Convert the string in lowercase
// 	iii.	Check whether the string is a palindrome or not
// 	iv.	Find the length of the String
// 	v.	Check that the accepted character is repeated how many times in the 
// String and at what position.
// 	vi.	Display the String in reverse order.
// 	vii.	Count the number of words in the String.
// 	viii.	Count the number of vowel in the String.
// 	ix.	Display the initials of the string.
// 	x.	Display the string in alphabetical order.

import java.io.*;
import java.util.Arrays;

public class p1 {
    private String str;
    private char ch;

    public p1(String str, char ch) {
        this.str = str;
        this.ch = ch;
    }

    public String toUpperCase() {
        return str.toUpperCase();
    }

    public String toLowerCase() {
        return str.toLowerCase();
    }

    public boolean isPalindrome() {
        String reversed = new StringBuilder(str).reverse().toString();
        return str.equals(reversed);
    }

    public int length() {
        return str.length();
    }

    public int countCharacterOccurrences() {
        int count = 0;
        for (char c : str.toCharArray()) {
            if (c == ch) {
                count++;
            }
        }
        return count;
    }

    public String reverse() {
        return new StringBuilder(str).reverse().toString();
    }

    public int countWords() {
        return str.split("\\s+").length;
    }

    public int countVowels() {
        int count = 0;
        for (char c : str.toLowerCase().toCharArray()) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    public String getInitials() {
        String[] words = str.split("\\s+");
        StringBuilder initials = new StringBuilder();
        for (String word : words) {
            initials.append(word.charAt(0));
        }
        return initials.toString().toUpperCase();
    }

    public String sortAlphabetically() {
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter string : ");
        String str = null;
        try {
            str = bf.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        p1 p = new p1(str, 'l');
        System.out.println(p.toUpperCase());
        System.out.println(p.toLowerCase());
        System.out.println(p.isPalindrome());
        System.out.println(p.length());
        System.out.println(p.countCharacterOccurrences());
        System.out.println(p.reverse());
        System.out.println(p.countWords());
        System.out.println(p.countVowels());
        System.out.println(p.getInitials());
        System.out.println(p.sortAlphabetically());
    }
}
// 