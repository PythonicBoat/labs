// 1. Using FIS and FOS - read Stu roll no and name from key board, then write to a file, thean open the file read the data and display on the monitor

import java.io.*;
import java.util.*;

class p1 {
    public static void main(String[] args) throws IOException {
        try {
            File inputFile = new File("p1.txt");
            if (!inputFile.exists()) {
                inputFile.createNewFile();
            }

            FileOutputStream fos = new FileOutputStream("p1.txt");

            System.out.println("Enter roll no and name: ");
            Scanner sc = new Scanner(System.in);
            int roll = sc.nextInt();
            String name = sc.next();

            System.out.println("\nOutput file :\n");
            fos.write(Integer.toString(roll).getBytes());
            fos.write("\n".getBytes());
            fos.write(name.getBytes());

            fos.close();

            FileInputStream fis = new FileInputStream("p1.txt");
            int i;
            while ((i = fis.read()) != -1) {
                System.out.print((char) i);
            }
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}