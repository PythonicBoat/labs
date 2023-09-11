// Toy program which was displayed in the classroom.

import java.io.*;

public class p3 {
    public static double totalAmount;
    public double indAmount;
    public String ToyId;
    public String ToyName;
    public double Price;
    public int Qty;

    public void acceptData() throws IOException {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(is);

        System.out.println("Enter Id of the Toy");
        ToyId = bf.readLine();
        System.out.println("Enter Name of the Toy");
        ToyName = bf.readLine();
        System.out.println("Enter Price of the Toy");
        Price = Double.valueOf(bf.readLine()).doubleValue();
        System.out.println("Enter Quantity of the Toy");
        Qty = Integer.parseInt(bf.readLine());

        indAmount = Price * Qty;
        totalAmount = totalAmount + indAmount;
    }

    public void displayData() {
        System.out.println("Toy Id is : " + ToyId);
        System.out.println("Toy Name is : " + ToyName);
        System.out.println("Toy Price is : " + Price);
        System.out.println("Toy Qty is : : " + Qty);
        System.out.println("Total Amount for this Toy is : " + indAmount);
    }

    public void displayTotalAmount() {
        System.out.println("Total Amount for all the Toys are " + totalAmount);
    }

    public static void main(String args[]) throws IOException {
        int nos;
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(is);

        System.out.println("How Many Toy Details you want to accept");
        nos = Integer.parseInt(bf.readLine());

        p3[] Obj = new p3[nos];//dynamic object creation during run time

        for (int i = 0; i < nos; i++) {
            Obj[i] = new p3();//we have to allocate the individual memory
            Obj[i].acceptData();
        }
        for (int i = 0; i < nos; i++) {
            Obj[i].displayData();
        }
        Obj[0].displayTotalAmount();
    }
}