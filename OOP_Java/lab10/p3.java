// 3. RandomAccess file - using rw permission, writer some data to the file and read the same and display on montor, here u use the funcion writeChar(), writeInt(), writerBoolean()....

import java.io.RandomAccessFile;
import java.io.IOException;

public class p3 {
    public static void main(String[] args) {
        // Define the file name
        String fileName = "randomAccessFile.dat";

        try {
            // Open the RandomAccess file with read-write permissions
            RandomAccessFile randomAccessFile = new RandomAccessFile(fileName, "rw");

            // Write data to the file using various write methods
            randomAccessFile.writeChar('A');
            randomAccessFile.writeInt(123);
            randomAccessFile.writeBoolean(true);

            // Move the file pointer to the beginning for reading
            randomAccessFile.seek(0);

            // Read and display the data using corresponding read methods
            char charValue = randomAccessFile.readChar();
            int intValue = randomAccessFile.readInt();
            boolean booleanValue = randomAccessFile.readBoolean();

            // Close the file
            randomAccessFile.close();

            // Display the read data on the console
            System.out.println("Character: " + charValue);
            System.out.println("Integer: " + intValue);
            System.out.println("Boolean: " + booleanValue);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
