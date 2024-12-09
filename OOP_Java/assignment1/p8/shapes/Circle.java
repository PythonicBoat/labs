package p8.shapes;

public class Circle {
    public double calculateArea(double radius) {
        return Math.PI * Math.pow(radius, 2);
    }

    public double calculateCircumference(double radius) {
        return 2 * Math.PI * radius;
    }
}
