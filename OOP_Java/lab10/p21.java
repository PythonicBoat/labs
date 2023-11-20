// also try thsame prog 2 by FIS and FOS

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class p21 {
    public static void main(String[] args) {
        // Specify the file paths
        String sourceFilePath = "p1.txt";
        String destinationFilePath = "p2.txt";

        try {
            // Create FileReader for the source file
            FileReader reader = new FileReader(sourceFilePath);

            // Create FileWriter for the destination file
            FileWriter writer = new FileWriter(destinationFilePath);

            // Read and write character by character
            int character;
            while ((character = reader.read()) != -1) {
                writer.write(character);
            }

            // Close the FileReader and FileWriter
            reader.close();
            writer.close();

            System.out.println("File copied successfully.");
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
