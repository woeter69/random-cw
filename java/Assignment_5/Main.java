import java.util.Scanner;

class VowelException extends Exception {
    public VowelException(String message) {
        super(message);
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        try {
            boolean containsVowel = false;

            for (char c : str.toCharArray()) {
                boolean isVowel = String.valueOf(c).matches("[aeiouAEIOU]");
                
                if (isVowel) {
                    containsVowel = true;
                    break; 
                }
            }

            if (!containsVowel) {
                throw new VowelException("Invalid string: No vowels were found.");
            }

            System.out.println("Success: Your string contains a vowel.");

        } 
        catch (VowelException e) {
            System.out.println("Error Caught: " + e.getMessage());
            
        } 
        finally {
            scanner.close(); 
        }
    }
}
