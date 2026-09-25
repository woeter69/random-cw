import java.util.Scanner;

interface IntStack {
    void push(int item);
    int pop();
}

class DynStack implements IntStack {
    private int stck[];
    private int tos;

    DynStack(int size) {
        stck = new int[size];
        tos = -1;
    }

    public void push(int item) {
        if (tos == stck.length - 1) {
            int temp[] = new int[stck.length * 2];
            for (int i = 0; i < stck.length; i++) {
                temp[i] = stck[i];
            }
            stck = temp;
        }
        stck[++tos] = item;
    }

    public int pop() {
        if (tos < 0) {
            System.out.println("Stack underflow.");
            return 0;
        }
        return stck[tos--];
    }
}

class Dynamic_Stack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter initial size of the stack: ");
        int size = scanner.nextInt();

        DynStack mystack = new DynStack(size);
        
        boolean running = true;
        while (running) {
            System.out.println("\n1. Push  2. Pop  3. Exit");
            System.out.print("Choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    int val = scanner.nextInt();
                    mystack.push(val);
                    break;
                case 2:
                    int popped = mystack.pop();
                    if (popped != 0 || size == 0) {
                        System.out.println("Popped: " + popped);
                    }
                    break;
                case 3:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        scanner.close();
    }
}
