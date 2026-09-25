public class Queue {
  private int[] queue;
  private int front;
  private int rear;
  private int capacity;

  public Queue(int capacity) {
    this.capacity = capacity;
    this.queue = new int[capacity];
    this.front = -1;
    this.rear = -1;
  }

  public boolean isFull() {
    return (rear + 1) % capacity == front;
  }

  public boolean isEmpty() {
    return front == -1;
  }

  public void enqueue(int item) {
    if (isFull()) {
      System.out.println("Queue Overflow!");
      return;
    }

    if (isEmpty()) {
      rear = 0;
      front = 0;
    }

    else {
      rear = (rear + 1) % capacity;
    }

    queue[rear] = item;
    System.out.println("Enqueued: " + item);
  }

  public int dequeue() {
    if (isEmpty()) {
      System.out.println("Queue Underflow!");
      return -1;
    }
    int item = queue[front];

    if (front == rear) {
      front = -1;
      rear = -1;
    }
    else {
      front = (front + 1) % capacity;
    }
    System.out.println("Dequeued: " + item);
    return item;
  }
}
