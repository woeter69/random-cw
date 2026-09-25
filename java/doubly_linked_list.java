public static class doubly_linked_list { 
  public static class Node {
    int data;
    Node next;
    Node prev;
    Node(int d) {
      data = d;
      next = null;
      prev = null;
    }
  }

  public static class DDL {
    Node head;
    
    DDL() {
      head = null;
    }

    public void addStart(int data) {
      Node p = new Node(data);
      if (head == null) {
        head = p;
        return;
      }
      p.next = head;
      head.prev = p;
      head = p;
    }

    public void addEnd (int data) {
      Node p = new Node(data);
      if (head == null) {
        head = p;
        return;
      }
      Node current = head;
      while (current.next != null) {
        current = current.next;
      }
      current.next = p;
      p.prev = current;
    }

    public void addTarget(int data, int target) {
      if (head == null) {
        System.out.println("Linked list not initialized");
      }
      Node current = head;
      while (current != null && current.data != target) {
        current = current.next;
      }

      if (current != null) {
        Node n = new Node(data);
        n.next = current.next;
        n.prev = current;

        if (n.next != null) {
          n.next.prev = n;
        }
        current.next = n;
      }
    }
    public void removeStart {
      if (head == null) {
        System.out.println("Linked list does not exist");
        return;
      }
      else if (head.next == null) {
        head = null;
      }
      else {
        Node p = head;
        head = head.next;
        p.next = null;
        head.prev = null;
      }
    }
  }
}
