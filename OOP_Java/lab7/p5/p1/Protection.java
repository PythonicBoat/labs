package p5.p1;

public class Protection {
    public int pub;
    private int pri;
    protected int pro;
    int defaultValue;

    public void printPri() {
        System.out.println("Private: " + pri);
    }

    public Protection(int pub, int pri, int pro, int defaultValue) {
        this.pub = pub;
        this.pri = pri;
        this.pro = pro;
        this.defaultValue = defaultValue;
        System.out.println("Values in Protection class constructor:");
        System.out.println("Public: " + pub);
        System.out.println("Private: " + pri);
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + defaultValue);
    }
}