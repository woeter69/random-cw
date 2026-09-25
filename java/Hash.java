public class Hash {
  private class HashNode {
    String key;
    int value;
    HashNode next;

    public HashNode(String key, int value) {
      this.key = key;
      this.value = value;
      this.next = null;
    }
  }
  HashNode[] buckets;
  private int capacity;
  private int size;

  private static final double LOAD_FACTOR = 0.75;

  public Hash(int capacity) {
    this.capacity = capacity;
    this.size = 0;
    buckets = new HashNode[capacity];
  }

  private int getIndex(String key) {
    return Math.abs(key.hashCode() % capacity);
  }

  public void put(String key, int value) {
    if ((double) size/capacity >= LOAD_FACTOR) {
      rehash();
    }

    int index = getIndex(key);
    HashNode head = buckets[index];

    HashNode current = head;
    
    while (current != null) {
      if (current.key.equals(key)) {
        current.value = value;
        return;
      }
      current = current.next;
    }
    HashNode newNode = new HashNode(key, value);
    newNode.next = head;
    buckets[index] = newNode;
    size++;
  }

  public int get(String key) {
    int index = getIndex(key);
    HashNode head = buckets[index];

    HashNode current = head;

    while (current != null) {
      if (current.key.equals(key)) {
        return current.value;
      }
      current = current.next;
    }
    return -1;
  }

  public void rehash() {
    HashNode[] oldBuckets = buckets;
    capacity = capacity * 2;
    buckets = new HashNode[capacity];
    size = 0;

    for (int i = 0; i < oldBuckets.length; i++) {
      HashNode current = oldBuckets[i];

      while (current != null) {
        put(current.key, current.value);
        current = current.next;
      }
    }
  }
}
