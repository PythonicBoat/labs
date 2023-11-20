// Write a java program to compare two binary files, printing the first byte
// position where they differ. use the functionlity of DataInput and DOS, and PrintStream

import java.io.*;

public class p7 {
    public static void main(String[] args) {
        String filePath1 = "p1.txt";
        String filePath2 = "p2.txt";

        try {
            DataInputStream dis1 = new DataInputStream(new FileInputStream(filePath1));
            DataInputStream dis2 = new DataInputStream(new FileInputStream(filePath2));

            long bytePosition = 0;
            boolean filesDiffer = false;

            while (dis1.available() > 0 && dis2.available() > 0) {
                byte byte1 = dis1.readByte();
                byte byte2 = dis2.readByte();

                if (byte1 != byte2) {
                    filesDiffer = true;
                    break;
                }

                bytePosition++;
            }

            dis1.close();
            dis2.close();

            if (filesDiffer) {
                System.out.println("Files differ at byte position: " + bytePosition);
            } else {
                System.out.println("Files are identical.");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
