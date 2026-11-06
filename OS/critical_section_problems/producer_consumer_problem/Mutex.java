import java.util.concurrent.atomic.AtomicBoolean;

public class Mutex {
  public class SimpleSpinLock {
    private final AtomicBoolean locked = new AtomicBoolean(false);

    public void lock() {
      // Checking if locked state is false, if yes then false->true
      while (!locked.compareAndSet(false, true)) {
        Thread.onSpinWait();
      }
    }

    public void unlock() {
      locked.set(false);
    }
  }

  private static int counter = 0;
  private final SimpleSpinLock myLock = new SimpleSpinLock();

  public class Task implements Runnable {
    @Override
    public void run() {
      for (int i = 0; i < 50000; i++) {
        myLock.lock();
        try {
          counter++;
        } finally {
          myLock.unlock();
        }
      }
    }
  }

  public static void main(String[] args) throws InterruptedException {
    Mutex mutex = new Mutex();

    Task task = mutex.new Task();

    Thread t1 = new Thread(task);
    Thread t2 = new Thread(task);

    t1.start();
    t2.start();

    t1.join();
    t2.join();

    System.out.println("Final counter value: " + counter);
  }
}
