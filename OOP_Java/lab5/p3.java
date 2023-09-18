// A plastic manufacturer sells plastic in different shapes like 2d sheet and 3d box. The cost of box is Rs 40/ sqft and the cost of box is Rs 60/ cuft. Implement it in java to calculate the cost of plastic as per the dimensions given by the user where 3d inherits from 2D. Single inheritance.

class TwoD {
    double length, breadth;

    double area() {
        return length * breadth;
    }
}

class ThreeD extends TwoD {
    double height;

    double volume() {
        return length * breadth * height;
    }
}

class Box extends ThreeD {
    double costPerSqft = 40;
    double costPerCuft = 60;

    void display() {
        double area = area();
        double volume = volume();
        double cost = (area * costPerSqft) + (volume * costPerCuft);
        System.out.println("Cost of the box is Rs " + cost);
    }
}

public class p3 {
    public static void main(String[] args) {
        Box b = new Box();
        System.out.println("Enter the length of the box:");
        b.length = Double.parseDouble(System.console().readLine());
        System.out.println("Enter the breadth of the box:");
        b.breadth = Double.parseDouble(System.console().readLine());
        System.out.println("Enter the height of the box:");
        b.height = Double.parseDouble(System.console().readLine());
        b.display();
    }
}