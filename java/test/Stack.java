public class Stack {
  int stck[] = new int[10];
  int tos;


  Stack() {
    tos = -1;
  }

  public void push(int item) {
    if (tos == 9) {
      System.out.println("Stack Overflow!");
    }
    else {
      stck[++tos] = item;
    }
  }

  public int pop() {
    if (tos < 0) {
      System.out.println("Stack Underflow!");
    }
    else {
      return stck[tos--];
    }
  }

  public void peek() {
    System.out.println(stck[tos]);
  }
}
