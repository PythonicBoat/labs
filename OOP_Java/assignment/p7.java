// 7.	WAP in java showing the implementation / workings of the following with example

// 	A.	compareTo() and compareToIgnoreCase() methods of the String Class 
// 	B.	indexOf() and lastIndexOf() methods of the String class
// 	C.	substring(), concate() and replace() methods of the string class
// 	D.	trim(), toLowerCase() and toUpperCase() methods of the String class
// 	E.	join() method of the String class

public class p7 {
    public static void main(String[] args) {
        String str1 = "Hello World";
        String str2 = "hello world";
        String str3 = "   Hello World   ";
        String str4 = "Hello,World,Java,Programming";

        // A. compareTo() and compareToIgnoreCase() methods
        System.out.println(str1.compareTo(str2)); // returns positive number
        System.out.println(str1.compareToIgnoreCase(str2)); // returns 0

        // B. indexOf() and lastIndexOf() methods
        System.out.println(str1.indexOf('o')); // returns 4
        System.out.println(str1.lastIndexOf('o')); // returns 7

        // C. substring(), concat() and replace() methods
        System.out.println(str1.substring(6)); // returns "World"
        System.out.println(str1.concat("!!!")); // returns "Hello World!!!"
        System.out.println(str1.replace('o', 'O')); // returns "HellO WOrld"

        // D. trim(), toLowerCase() and toUpperCase() methods
        System.out.println(str3.trim()); // returns "Hello World"
        System.out.println(str1.toLowerCase()); // returns "hello world"
        System.out.println(str1.toUpperCase()); // returns "HELLO WORLD"

        // E. join() method
        String[] strArray = str4.split(",");
        System.out.println(String.join("-", strArray)); // returns "Hello-World-Java-Programming"
    }
}