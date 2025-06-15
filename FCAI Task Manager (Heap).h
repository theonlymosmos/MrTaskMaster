//https://www.linkedin.com/in/mousa123/


#include <iostream>
#include <string>
using namespace std;

struct DoneTask {
    string text;
    int minutes;
    string group;

    void print() {
        cout << "[" << text << ", " << minutes << ", " << group << "]" << endl;
    }
};

class TaskMinHeap {
private:
    DoneTask* heap;
    int size;
    int capacity;

    void resizeHeap() {
        capacity *= 2;
        DoneTask* newHeap = new DoneTask[capacity];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].minutes >= heap[parent].minutes) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void bubbleDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left].minutes < heap[smallest].minutes)
                smallest = left;
            if (right < size && heap[right].minutes < heap[smallest].minutes)
                smallest = right;
            if (smallest == index) break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    TaskMinHeap() : size(0), capacity(10) {
        heap = new DoneTask[capacity];
    }

    ~TaskMinHeap() {
        delete[] heap;
    }

    void addDoneTask(string text, int minutes, string group) {
        if (size == capacity) resizeHeap();
        heap[size] = {text, minutes, group};
        bubbleUp(size);
        size++;
    }

    void printDoneTasks() {
        TaskMinHeap tempHeap;
        for (int i = 0; i < size; i++) {
            tempHeap.addDoneTask(heap[i].text, heap[i].minutes, heap[i].group);
        }
        
        while (tempHeap.size > 0) {
            tempHeap.heap[0].print();
            tempHeap.heap[0] = tempHeap.heap[tempHeap.size - 1];
            tempHeap.size--;
            tempHeap.bubbleDown(0);
        }
    }

    void printCategoryCounts() {
        int edu = 0, health = 0, self = 0, food = 0, other = 0;
        for (int i = 0; i < size; i++) {
            if (heap[i].group == "Educational") edu++;
            else if (heap[i].group == "Health") health++;
            else if (heap[i].group == "Self development") self++;
            else if (heap[i].group == "Food") food++;
            else other++;
        }
        cout << "Educational = " << edu << endl;
        cout << "Health = " << health << endl;
        cout << "Self development = " << self << endl;
        cout << "Food = " << food << endl;
        cout << "Other = " << other << endl;
    }
};