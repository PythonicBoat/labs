// 3.	WAP in java which will read the data from a file and copy to another file in char by char 	format and byte by byte format.

import java.io.*;

public class p3 {
    public static void copyFileCharByChar(String sourceFile, String destinationFile) throws IOException {
        FileReader fr = null;
        FileWriter fw = null;
        try {
            fr = new FileReader(sourceFile);
            fw = new FileWriter(destinationFile);
            int c;
            while ((c = fr.read()) != -1) {
                fw.write(c);
            }
        } finally {
            if (fr != null) {
                fr.close();
            }
            if (fw != null) {
                fw.close();
            }
        }
    }

    public static void copyFileByteByByte(String sourceFile, String destinationFile) throws IOException {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        try {
            fis = new FileInputStream(sourceFile);
            fos = new FileOutputStream(destinationFile);
            int b;
            while ((b = fis.read()) != -1) {
                fos.write(b);
            }
        } finally {
            if (fis != null) {
                fis.close();
            }
            if (fos != null) {
                fos.close();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        copyFileCharByChar("source.txt", "destinationChar.txt");
        copyFileByteByByte("source.txt", "destinationByte.txt");
    }
}