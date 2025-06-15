Year 2 - Sem 2 - Data Structures  

### **Project Name: "Task Master"**  
*(Reflecting the seamless flow of tasks between BST and Heap structures while managing task completion workflows)*  

---

### **Project Overview**  
A **C++ Task Management System** implementing:  
1. **Binary Search Tree (BST)** for active tasks sorted by duration  
2. **Min-Heap** for completed tasks prioritized by shortest duration  
3. Comprehensive operations meeting all assignment requirements  

---

### **Complete Feature Implementation**  

#### **Task 1: BST Implementation (Active Tasks)**  
```cpp
class TaskBST {
    // 1. Insert tasks (left for equal durations)
    void addTask(string text, int minutes, string group) {
        root = insertHelper(root, {text, minutes, group});
    }
    
    // 2. In-order display
    void printAll() { inOrder(root); }
    
    // 3. Duration search
    void findTasks(int duration) { searchHelper(root, duration); }
    
    // 4. Remove by duration  
    void removeTasks(int duration) {
        root = removeHelper(root, duration, removed);
    }
    
    // 5. Display ≥ duration (reverse in-order)
    void printLonger(int duration) { longerHelper(root, duration); }
    
    // 6. Display ≤ duration (in-order)  
    void printShorter(int duration) { shorterHelper(root, duration); }
};
```

#### **Task 2: Min-Heap Implementation (Completed Tasks)**  
```cpp
class TaskMinHeap {
    // 1. Mark tasks complete (BST → Heap transfer)
    void addDoneTask(string text, int minutes, string group) {
        if (size == capacity) resizeHeap();
        heap[size] = {text, minutes, group};
        bubbleUp(size++);
    }
    
    // 2. Display sorted completed tasks + category report
    void printDoneTasks() {
        // Temp heap for sorted output
        while (tempHeap.size > 0) {
            tempHeap.heap[0].print();
            // ... heap extraction logic ...
        }
    }
    void printCategoryCounts() {
        // Counts per category (Educational, Health, etc.)
    }
};
```

---

### **Key Technical Achievements**  

1. **BST Operations**  
   - **Custom Insertion**: Left-child priority for equal durations  
   - **Range Queries**: Efficient ≥/≤ duration displays using tailored traversals  
   - **Case-Insensitive Search**: `toLowerString()` enables partial description matching  

2. **Heap Management**  
   - **Dynamic Resizing**: `resizeHeap()` doubles capacity when full  
   - **Proper Heapify**: `bubbleUp()`/`bubbleDown()` maintain min-heap property  
   - **Sorted Output**: Temporary heap enables O(n log n) display without modifying original  

3. **System Integration**  
   - **BST→Heap Transfer**: `findAndRemoveTask()` safely moves tasks between structures  
   - **File I/O**: Robust parsing of multi-line task input format  
   - **User Interface**: Comprehensive menu matching assignment specs  

---

### **Assignment Requirements Fully Met**  

| **Requirement**               | **Implementation Location**          | **Key Challenge Solved**               |
|--------------------------------|---------------------------------------|----------------------------------------|
| BST Insert (left for equals)   | `insertHelper()`                      | Pointer management during insertion    |
| Duration-based Search          | `searchHelper()`                      | Multiple matches handling              |
| Complex Removal                | `removeHelper()`                      | Three deletion cases (0/1/2 children)  |
| Range Displays                 | `longerHelper()`/`shorterHelper()`    | Custom traversal logic                 |
| Case-Insensitive Completion    | `findAndRemoveTask()`                 | Partial string matching                |
| Heap Category Reporting        | `printCategoryCounts()`               | Efficient category counting            |

---

### **Learning Outcomes**  
1. **Data Structure Selection**: Recognized BST ideal for active tasks (duration ordering) vs Heap optimal for completed tasks (priority processing)  
2. **Memory Management**: Mastered dynamic resizing in Heap and proper BST node deletion  
3. **Real-World Patterns**: Implemented case-insensitive search matching commercial task managers  
4. **Debugging Skills**: Resolved pointer issues in BST removal and heap bubbling operations  

---

### **Suggested Improvements**  
1. **Undo Functionality**  
   ```cpp 
   stack<UndoAction> history; // Track moves between BST/Heap
   ```
2. **Due Date Integration**  
   ```cpp
   time_t dueDate; // Enable time-based prioritization
   ```
3. **Persistent Storage**  
   ```cpp
   void saveToDatabase(); // SQLite integration
   ```

---

### **Why "Task Master"?**  
- **Clear Purpose**: Immediately communicates task management focus  
- **Technical Accuracy**: "Flow" reflects BST→Heap transition  
- **Professional**: Suitable for academic portfolios  

This implementation demonstrates mastery of both BST and Heap structures while solving real-world task management challenges.  

Contributers: Mousa M Mousa, Mohamed El Sayed (Medo)
