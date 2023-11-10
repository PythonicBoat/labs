// 3.  All constructor and methods of StringBuffer Classs

package lab9;

public class p3 {
    public static void main(String[] args) {
        // Constructors
        StringBuffer sb1 = new StringBuffer(); // empty constructor
        StringBuffer sb2 = new StringBuffer("Hello"); // constructor with string
        StringBuffer sb3 = new StringBuffer(10); // constructor with capacity

        // Methods
        sb1.append("World"); // append method
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

        // Custom methods
        insertAt(sb1, 1, "InsertAt"); // insertAt method
        System.out.println("sb1 after insertAt(1, \"InsertAt\"): " + sb1);

        reverseStringBuffer(sb2); // reverseStringBuffer method
        System.out.println("sb2 after reverseStringBuffer: " + sb2);

        replaceStringBuffer(sb3, "Hello", "Java"); // replaceStringBuffer method
        System.out.println("sb3 after replaceStringBuffer: " + sb3);

        appendStringBuffer(sb1, " Appended"); // appendStringBuffer method
        System.out.println("sb1 after appendStringBuffer: " + sb1);
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
}
