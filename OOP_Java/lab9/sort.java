import java.util.Arrays;

public class sort {

    public static String reorderSentence(String inputSentence) {
        // Split the sentence into an array of words
        String[] words = inputSentence.split("\\s+");

        // Reorder the words (you can implement your own custom logic here)
        Arrays.sort(words);

        // Join the words to form the reordered sentence
        String reorderedSentence = String.join(" ", words);

        return reorderedSentence;
    }

    public static void main(String[] args) {
        // Example usage
        String inputSentence = "The quick brown fox jumps over the lazy dog";
        String reorderedSentence = reorderSentence(inputSentence);

        // Display the result
        System.out.println("Original Sentence: " + inputSentence);
        System.out.println("Reordered Sentence: " + reorderedSentence);
    }
}
