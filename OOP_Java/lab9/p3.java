import java.util.Scanner;

public class p3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // User input for sb1
        System.out.println("Enter a string for sb1:");
        String input1 = scanner.nextLine();
        StringBuffer sb1 = new StringBuffer(input1); // constructor with user input

        // User input for sb2
        System.out.println("Enter another string for sb2:");
        String input2 = scanner.nextLine();
        StringBuffer sb2 = new StringBuffer(input2); // constructor with user input

        StringBuffer sb3 = new StringBuffer(10); // empty constructor

        // Methods
        sb1.append(" World"); // append method
        sb2.insert(0, "World "); // insert method
        sb3.append("Hello").append(" World"); // chaining of append method

        System.out.println("sb1: " + sb1);
        System.out.println("sb2: " + sb2);
        System.out.println("sb3: " + sb3);

        sb1.reverse(); // reverse method
        System.out.println("sb1 (reversed): " + sb1);

        sb2.replace(0, 5, "Hi"); // replace method
        System.out.println("sb2 (replaced): " + sb2);

        sb3.delete(0, 5); // delete method
        System.out.println("sb3 (deleted): " + sb3);

        int capacity = sb3.capacity(); // capacity method
        System.out.println("sb3 capacity: " + capacity);

        char ch = sb2.charAt(0); // charAt method
        System.out.println("sb2 first character: " + ch);

        int length = sb2.length(); // length method
        System.out.println("sb2 length: " + length);

        sb3.ensureCapacity(20); // ensureCapacity method
        System.out.println("sb3 capacity after ensureCapacity: " + sb3.capacity());

        sb1.setLength(3); // setLength method
        System.out.println("sb1 after setLength(3): " + sb1);

        // Additional methods
        String substring = sb2.substring(1, 3); // substring method
        System.out.println("Substring of sb2 (1 to 3): " + substring);

        int indexOfChar = sb3.indexOf("W"); // indexOf method
        System.out.println("Index of 'W' in sb3: " + indexOfChar);

        int lastIndexOfChar = sb3.lastIndexOf("W"); // lastIndexOf method
        System.out.println("Last index of 'W' in sb3: " + lastIndexOfChar);

        sb2.deleteCharAt(2); // deleteCharAt method
        System.out.println("sb2 after deleting character at index 2: " + sb2);

        sb1.setCharAt(1, 'X'); // setCharAt method
        System.out.println("sb1 after setting character at index 1 to 'X': " + sb1);

        // Custom methods
        insertAt(sb1, 1, "InsertAt"); // insertAt method
        System.out.println("sb1 after insertAt(1, \"InsertAt\"): " + sb1);

        reverseStringBuffer(sb2); // reverseStringBuffer method
        System.out.println("sb2 after reverseStringBuffer: " + sb2);

        replaceStringBuffer(sb3, "Hello", "Java"); // replaceStringBuffer method
        System.out.println("sb3 after replaceStringBuffer: " + sb3);

        appendStringBuffer(sb1, " Appended"); // appendStringBuffer method
        System.out.println("sb1 after appendStringBuffer: " + sb1);

        // Custom method
        deleteRange(sb3, 2, 3); // deleteRange method
        System.out.println("sb3 after deleting range (2 to 5): " + sb3);

        scanner.close();
    }

    // Custom method to insert at a specific index
    private static void insertAt(StringBuffer stringBuffer, int index, String text) {
        stringBuffer.insert(index, text);
    }

    // Custom method to reverse a StringBuffer
    private static void reverseStringBuffer(StringBuffer stringBuffer) {
        stringBuffer.reverse();
    }

    // Custom method to replace a substring in StringBuffer
    private static void replaceStringBuffer(StringBuffer stringBuffer, String oldStr, String newStr) {
        int index = stringBuffer.indexOf(oldStr);
        stringBuffer.replace(index, index + oldStr.length(), newStr);
    }

    // Custom method to append to a StringBuffer
    private static void appendStringBuffer(StringBuffer stringBuffer, String text) {
        stringBuffer.append(text);
    }

    // Custom method to delete a range of characters in StringBuffer
    private static void deleteRange(StringBuffer stringBuffer, int start, int end) {
        stringBuffer.delete(start, end);
    }
}
