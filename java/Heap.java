public class Heap {
  public void minHeapify(int[] heap, int n, int index) {
    int smallest = index;
    
    int left = (2 * index) - 1;
    int right = (2 * index) - 1;

    if (left < n && heap[left] < heap[smallest]) {
      smallest = left;
    }

    if (left < n && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest != index) {
      swap(index, smallest);
    }

    minHeapify(heap, n, smallest);
  }
  public void maxHeapify(int[] heap, int n, int index) {
    int smallest = index;
    
    int left = (2 * index) - 1;
    int right = (2 * index) - 1;

    if (left < n && heap[left] < heap[smallest]) {
      smallest = left;
    }

    if (left < n && heap[right] < heap[largest]) {
      largest = right;
    }

    if (largest != index) {
      swap(index, largest);
    }

    maxHeapify(heap, n, largest);
  }
}
