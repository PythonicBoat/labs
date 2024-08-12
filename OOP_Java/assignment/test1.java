import java.io.*;

public class FileOperations {
    public static void main(String[] args) throws IOException {
        File file = new File("path_to_your_file");

        // Count words
        int wordCount = 0;
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                wordCount += line.split("\\s+").length;
            }
        }
        System.out.println("Word count: " + wordCount);

        // Get file size
        long fileSize = file.length();
        System.out.println("File size: " + fileSize + " bytes");

        // Read file in reverse
        try (RandomAccessFile raf = new RandomAccessFile(file, "r")) {
            long pointer = raf.length() - 1;
            while (pointer >= 0) {
                raf.seek(pointer);
                System.out.print((char) raf.read());
                pointer--;
            }
        }
        System.out.println();

        // Convert first letter of each word to uppercase
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                for (String word : line.split("\\s+")) {
                    String capitalizedWord = Character.toUpperCase(word.charAt(0)) + word.substring(1);
                    System.out.print(capitalizedWord + " ");
                }
            }
        }
        System.out.println();
    }
}