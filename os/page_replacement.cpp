#include <iostream>

using namespace std;

int find_page(int memory[], int capacity, int page) {
    for (int i = 0; i < capacity; i++) {
        if (memory[i] == page) {
            return i;
        }
    }
    return -1;
}

int fifo_page_replacement(int pages[], int n, int capacity) {
    int* memory = new int[capacity];
    for (int i = 0; i < capacity; i++) memory[i] = -1;
    
    int page_faults = 0, replace_index = 0;

    for (int i = 0; i < n; i++) {
        if (find_page(memory, capacity, pages[i]) == -1) {
            memory[replace_index] = pages[i];
            replace_index = (replace_index + 1) % capacity;
            page_faults++;
        }
    }
    
    return page_faults;
}

int lifo_page_replacement(int pages[], int n, int capacity) {
    int* memory = new int[capacity];
    for (int i = 0; i < capacity; i++) memory[i] = -1;
    
    int page_faults = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (find_page(memory, capacity, pages[i]) == -1) {
            page_faults++;
            if (count < capacity) {
                memory[count] = pages[i];
                count++;
            } else {
                memory[capacity - 1] = pages[i];
            }
        }
    }
    
    return page_faults;
}

int lru_page_replacement(int pages[], int n, int capacity) {
    int* memory = new int[capacity];
    int* last_used = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        memory[i] = -1;
        last_used[i] = 0;
    }
    
    int page_faults = 0, time = 0;

    for (int i = 0; i < n; i++) {
        time++;
        int page_index = find_page(memory, capacity, pages[i]);
        
        if (page_index == -1) {
            page_faults++;
            int lru_index = 0;
            int min_time = last_used[0];
            
            for (int j = 1; j < capacity; j++) {
                if (memory[j] == -1) { 
                    lru_index = j;
                    break;
                }
                if (last_used[j] < min_time) {
                    min_time = last_used[j];
                    lru_index = j;
                }
            }
            memory[lru_index] = pages[i];
            last_used[lru_index] = time;
        } else {
            last_used[page_index] = time;
        }
    }
    
    return page_faults;
}

int mru_page_replacement(int pages[], int n, int capacity) {
    int* memory = new int[capacity];
    int* last_used = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        memory[i] = -1;
        last_used[i] = 0;
    }
    
    int page_faults = 0, time = 0;

    for (int i = 0; i < n; i++) {
        time++;
        int page_index = find_page(memory, capacity, pages[i]);
        
        if (page_index == -1) {
            page_faults++;
            int mru_index = 0;
            bool has_empty = false;
            
            for (int j = 0; j < capacity; j++) {
                if (memory[j] == -1) {
                    mru_index = j;
                    has_empty = true;
                    break;
                }
            }
            
            if (!has_empty) {
                int max_time = last_used[0];
                for (int j = 1; j < capacity; j++) {
                    if (last_used[j] > max_time) {
                        max_time = last_used[j];
                        mru_index = j;
                    }
                }
            }
            
            memory[mru_index] = pages[i];
            last_used[mru_index] = time;
        } else {
            last_used[page_index] = time;
        }
    }
    
    return page_faults;
}

int main() {
    int reference_array[100];
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
      cout << "Enter run time for P" << i + 1 << ": ";
      cin >> reference_array[i];
    }
    
    int cache_capacity;
    cout << "Enter Cache Capacity: ";
    cin >> cache_capacity;

    cout << "Reference String Length: " << n << "\n";
    cout << "Cache Capacity: " << cache_capacity << "\n\n";

    cout << "FIFO Page Faults: " << fifo_page_replacement(reference_array, n, cache_capacity) << "\n";
    cout << "LIFO Page Faults: " << lifo_page_replacement(reference_array, n, cache_capacity) << "\n";
    cout << "LRU Page Faults: "  << lru_page_replacement(reference_array, n, cache_capacity) << "\n";
    cout << "MRU Page Faults: "  << mru_page_replacement(reference_array, n, cache_capacity) << "\n";

    return 0;
}
