abstract class twod {
    double length, breadth;
    abstract double area();
}

abstract class threed extends twod {
    double height;
    abstract double volume();
}

class Box extends threed {
    double cost2 = 40;
    double cost3 = 60;

    double area() {
        return length*breadth;
    }

    double volume() {
        return length*breadth*height;
    }

    void display() {
        double area = area();
        double volume = volume();
        double cost = (area*cost2) + (volume*cost3);
        System.out.println("cost of box is :"+cost);
    }
}

public class test {
    public static void main(String[] args) {
        Box b = new Box();
        System.out.println();
        b.length();
        System.out.println();
        System.out.println();
    }
}
