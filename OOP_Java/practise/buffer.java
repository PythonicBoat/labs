public class buffer {
    public static void main(String[] args) {

        // constructor 1
        StringBuffer sb = new StringBuffer();

        // constructor 2
        StringBuffer sb2 = new StringBuffer();

        // constructor 3
        StringBuffer sb3 = new StringBuffer();

        sb.append("My !");
        sb.insert(3, "world");

        // mutable -> content loaded to Buffer without creation of new Object
        // StringBuffer sb = new StringBuffer();
        // sb.append("Hello!");

        // immutable -> content cannot be modified
        String str = sb.toString();
        System.out.println(str);
    }
}
