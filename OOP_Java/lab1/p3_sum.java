// WAP in java to display the sum of two variable thrugh method calling

class p3_sum{
    int a=50;
    int b=90;
    int c;
    void add() {
        c = a+b;
        System.out.println("The sum is : "+c);
    }
    public static void main(String args[]) {
        p3_sum obj;
        obj = new p3_sum();

        obj.add();
    }
}
