public class callByValue {
    public static void increment(int number) {
        number = number + 1;
    }

    public static void main(String[] args) {
        int count = 10;
        increment(count);
        
        System.out.println("Value after method: " + count); 
        // Output: 10
    }

}
