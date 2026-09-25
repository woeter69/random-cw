public class methodOverload {
  int length;
  int width;
  
  static int area() {
    int length = 10;
    int width = 10;
    return width * length;
  }

  static int area(int length, int width) {
    return length*width;
  }

  public static void main(String[] args) {
    
    System.out.println(area(10,20));
    System.out.println(area());
  } 
}
