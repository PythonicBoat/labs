// 4. Using sequenceINputStream read two file parallely and writer to the third fil;e, again read from the third file and display on the monitor

import java.io.*;
import java.util.*;

public class p4 {
    public static void main(String[] args) {
        // Define the names of the input files and the output file
        String inputFile1 = "p1.txt";
        String inputFile2 = "p2.txt";
        String outputFile = "outputFile.txt";

        try {
            // Create FileInputStreams for the two input files
            FileInputStream fis1 = new FileInputStream(inputFile1);
            FileInputStream fis2 = new FileInputStream(inputFile2);

            // Create an enumeration of InputStreams
            Enumeration<FileInputStream> inputStreams = Collections.enumeration(
                    // Adding FileInputStreams to the enumeration
                    Collections.list(fis1, fis2)
            );

            // Create a SequenceInputStream with the enumeration
            SequenceInputStream sis = new SequenceInputStream(inputStreams);

            // Create a FileOutputStream for the output file
            FileOutputStream fos = new FileOutputStream(outputFile);

            // Read from SequenceInputStream and write to the output file
            int data;
            while ((data = sis.read()) != -1) {
                fos.write(data);
            }

            // Close the input and output streams
            fis1.close();
            fis2.close();
            sis.close();
            fos.close();

            // Display the content of the output file on the monitor
            FileInputStream fis3 = new FileInputStream(outputFile);
            int readByte;
            while ((readByte = fis3.read()) != -1) {
                System.out.print((char) readByte);
            }
            fis3.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
