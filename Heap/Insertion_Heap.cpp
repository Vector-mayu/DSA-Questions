#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    // Helper function to get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Swap values at two indices
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    // Insert a new value into the heap
    void insert(int val) {
        heap.push_back(val); // Step 1: Add at the end
        int i = heap.size() - 1;

        // Step 2: Bubble up (heapify up)
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Print heap elements
    void printHeap() {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Max Heap after insertions: ";
    h.printHeap();

    return 0;
}
