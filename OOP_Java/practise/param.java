import java.util.Scanner;

class TwoD {
    double length, breadth;

    double area(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
        return length * breadth;
    }
}

class ThreeD extends TwoD {
    double height;

    double volume(double length, double breadth, double height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
        return length * breadth * height;
    }
}

class Box extends ThreeD {
    double costPerSqft = 40;
    double costPerCuft = 60;

    void display() {
        double area = area(length, breadth);
        double volume = volume(length, breadth, height);
        double cost = (area * costPerSqft) + (volume * costPerCuft);
        System.out.println("Cost of the box is Rs " + cost);
    }

    public static void param(String[] args) {
        Scanner sc = new Scanner(System.in);
        Box b = new Box();

        System.out.println("Enter the length of the box:");
        b.length = sc.nextDouble();

        System.out.println("Enter the breadth of the box:");
        b.breadth = sc.nextDouble();

        System.out.println("Enter the height of the box:");
        b.height = sc.nextDouble();

        b.display();
    }
}