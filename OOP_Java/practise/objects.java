public class objects {

    static String emp_name;
    static int emp_id;

    static void set(String n, int m) {
        emp_name = n;
        emp_id = m;
    }

    static void get() {
        System.out.println("Employee name : "+emp_name);
        System.out.println("Employee ID : "+emp_id);
    }

    public static void main(String[] args) {
        statuc.set("Yashvardhan Singh", 2206065);
        statuc.get();
    }
}