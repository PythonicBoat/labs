// 2. Uisng FileReader and FileWriter(char by char) - copy the data of one file to another file

import java.io.*;

class p2 {
    public static void main(String[] args) {
        try {
            File inputFile = new File("p1.txt");
            File outputFile = new File("p2.txt");

            if (!inputFile.exists()) {
                System.out.println("Input file does not exist.");
                return;
            }

            FileReader fr = new FileReader(inputFile);
            FileWriter fw = new FileWriter(outputFile);

            int c;
            while ((c = fr.read()) != -1) {
                fw.write(c);
            }

            // read p2.txt file


            fr.close();
            fw.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}