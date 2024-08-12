public class p9 {
    public static void main(String[] args) {
        p9 obj = new p9();
        System.out.println(obj.add(1, 2));
        System.out.println(obj.add(1.0, 2));
        System.out.println(obj.add(1, "2"));
        System.out.println(obj.add(1, 2, 3));
        System.out.println(obj.add(1.0, 2.0, 3.0));
    }
    public int add(int a, int b) {
        return a + b;
    }
    
    public double add(double a, int b) {
        return a + b;
    }
    
    public String add(int a, String b) {
        return a + b;
    }
    
    public int add(int a, int b, int c) {
        return a + b + c;
    }
    
    public double add(double a, double b, double c) {
        return a + b + c;
    }
}
    