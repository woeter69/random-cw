public class callByReference {
    int value;
    callByReference(int val) {
      this.value = val;
    }
    
    public static void increment(callByReference c) {
        c.value = c.value + 1; 
    }

    public static void main(String[] args) {
        callByReference myCounter = new callByReference(10);
        
        increment(myCounter);
        
        System.out.println("Value after method: " + myCounter.value); 
        // Output: 11
    }

}
