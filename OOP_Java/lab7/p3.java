// WAP in which one interface can be extended from another interface. WAP in java to implement the logic.

interface KIIT {
    void engineering();
}

interface KIMS extends KIIT {
    void medical();
}

class college implements KIMS {
    public void engineering() {
        System.out.println("An engineering college");
    }

    public void medical() {
        System.out.println("A medical college");
    }
}

public class p3 {
    public static void main(String[] args) {
        college obj = new college();
        obj.engineering();
        obj.medical();
    }
}
