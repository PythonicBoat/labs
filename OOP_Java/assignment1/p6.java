class Point2D {
    protected double x, y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Point2D other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2));
    }

    public void move(double dx, double dy) {
        this.x += dx;
        this.y += dy;
    }

    @Override
    public String toString() {
        return "Point2D(" + "x=" + x + ", y=" + y + ')';
    }
}

class Point3D extends Point2D {
    private double z;

    public Point3D(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    public double distance(Point3D other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2) + Math.pow(this.z - other.z, 2));
    }

    public void move(double dx, double dy, double dz) {
        super.move(dx, dy);
        this.z += dz;
    }

    @Override
    public String toString() {
        return "Point3D(" + "x=" + x + ", y=" + y + ", z=" + z + ')';
    }
}

public class p6 {
    public static void main(String[] args) {
        Point2D p2d1 = new Point2D(1, 2);
        Point2D p2d2 = new Point2D(4, 6);
        System.out.println("Distance between p2d1 and p2d2: " + p2d1.distance(p2d2));
        p2d1.move(1, 1);
        System.out.println("After moving p2d1: " + p2d1);

        Point3D p3d1 = new Point3D(1, 2, 3);
        Point3D p3d2 = new Point3D(4, 6, 8);
        System.out.println("Distance between p3d1 and p3d2: " + p3d1.distance(p3d2));
        p3d1.move(1, 1, 1);
        System.out.println("After moving p3d1: " + p3d1);
    }
}