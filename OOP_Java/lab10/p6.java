// 6. Write a java program to capitalize first letter of every word in a file.

import java.io.*;

public class p6 {
    public static void main(String[] args) {
        // Specify the file path
        String filePath = "cap.txt";

        try {
            // Read the content from the file
            FileReader fileReader = new FileReader(filePath);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            StringBuilder modifiedContent = new StringBuilder();

            String line;
            while ((line = bufferedReader.readLine()) != null) {
                String[] words = line.split("\\s");
                for (String word : words) {
                    if (!word.isEmpty()) {
                        char firstLetter = Character.toUpperCase(word.charAt(0));
                        String restOfWord = word.substring(1);
                        modifiedContent.append(firstLetter).append(restOfWord).append(" ");
                    }
                }
                modifiedContent.append("\n");
            }

            FileWriter fileWriter = new FileWriter(filePath);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write(modifiedContent.toString());

            bufferedReader.close();
            bufferedWriter.close();

            System.out.println("Successfully capitalized the first letter of every word in the file.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
