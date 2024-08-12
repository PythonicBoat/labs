// write a java code for implicit to explicit typecasting

class typecast
{
    public static void main(String args[])
    {
        int a = 10;
        double b = a; // implicit typecasting
        System.out.println("Implicit typecasting: " + b);
        double c = 10.5;
        int d = (int)c; // explicit typecasting
        System.out.println("Explicit typecasting: " + d);
    }
}