public class Stack {
  private int tos;
  private int[] stack;
  private int size;

  public Stack(int size) {
    size = this.size;
    tos = -1;
    stack = new int[size];
  }

  public boolean isFull() {
    return tos == size - 1;
  }

  public boolean isEmpty() {
    return tos == -1;
  }

  public void push(int item) {
    if (isFull()) {
      System.out.println("Stack full!");
      return;
    }

    stack[++tos] = item;
    System.out.println("Pushed " + item);
  }

  public int pop() {
    if (isEmpty()) {
      System.out.println("Stack Empty!");
      return -1;
    }

    int item = stack[tos--];
    System.out.println("Popped " + item);
    return item;
  }

  public int peek() {
    if (isEmpty()) {
      System.out.println("Stack Empty!");
      return -1;
    }

    return stack[tos];
  }
}
