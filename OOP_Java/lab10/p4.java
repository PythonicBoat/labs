// 4. Using sequenceINputStream read two file parallely and writer to the third fil;e, again read from the third file and display on the monitor

import java.io.*;

public class p4 {
    public static void main(String[] args) {
        // Define the paths of the two input files and the output file
        String inputFile1 = "p1.txt";
        String inputFile2 = "p2.txt";
        String outputFile = "main.txt";

        try {
            // Create FileInputStreams for the two input files
            FileInputStream fis1 = new FileInputStream(inputFile1);
            FileInputStream fis2 = new FileInputStream(inputFile2);

            // Create a SequenceInputStream to read from the two input streams
            SequenceInputStream sis = new SequenceInputStream(fis1, fis2);

            // Create FileOutputStream for the output file
            FileOutputStream fos = new FileOutputStream(outputFile);

            // Read from the SequenceInputStream and write to the output file
            int bytesRead;
            byte[] buffer = new byte[1024];
            while ((bytesRead = sis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }

            // Close the input and output streams
            sis.close();
            fos.close();

            // Display the content of the third file on the monitor
            displayFileContent(outputFile);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void displayFileContent(String filePath) {
        try {
            // Create a FileInputStream for reading from the third file
            FileInputStream fis = new FileInputStream(filePath);

            // Create a BufferedReader for efficient reading
            BufferedReader reader = new BufferedReader(new InputStreamReader(fis));

            // Read and display each line from the file
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            // Close the input stream
            fis.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
