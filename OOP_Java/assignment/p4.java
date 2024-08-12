// 4.	WAP in java which will read the data from two files simultaneously using SequenceInputStream and display on the monitor as well write the data to the third file.
import java.io.*;

public class p4 {
    public static void main(String[] args) {
        try {
            FileInputStream fis1 = new FileInputStream("file1.txt");
            FileInputStream fis2 = new FileInputStream("file2.txt");
            SequenceInputStream sis = new SequenceInputStream(fis1, fis2);
            FileOutputStream fos = new FileOutputStream("file3.txt");

            int i;
            while ((i = sis.read()) != -1) {
                System.out.print((char) i);
                fos.write(i);
            }

            // add display of file3.txt
            System.out.println("\n\nContents of file3.txt:");
            FileInputStream fis3 = new FileInputStream("file3.txt");
            while ((i = fis3.read()) != -1) {
                System.out.print((char) i);
            }
            fis3.close();

            fis1.close();
            fis2.close();
            sis.close();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}