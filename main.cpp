//https://www.linkedin.com/in/mousa123/

#include "BST.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string toLower(string str) {
    for (char &c : str) c = tolower(c);
    return str;
}

bool matchesDesc(string taskDesc, string search) {
    return toLower(taskDesc).find(toLower(search)) != string::npos;
}

int main() {
    TaskBST activeTasks;
    TaskMinHeap completedTasks;

    // Read from file
    ifstream file("input.txt");
    if (file) {
        int count;
        file >> count;
        file.ignore(); // skip newline after count

        for (int i = 0; i < count; i++) {
            string desc, cat;
            int dur;

            getline(file, desc);   // task description
            file >> dur;           // task duration
            file.ignore();         // skip newline
            getline(file, cat);    // task category

            activeTasks.addTask(desc, dur, cat);
        }

        file.close();
    } else {
        cout << "Failed to open input.txt\n";
    }

    int choice;
    do {
        cout << "\nFCAI Task Manager\n";
        cout << "1. Insert a task (using BST Class)\n";
        cout << "2. Display all tasks (using BST Class)\n";
        cout << "3. Search for a task (using BST Class)\n";
        cout << "4. Remove a task (using BST Class)\n";
        cout << "5. Display tasks with duration >= (using BST Class)\n";
        cout << "6. Display tasks with duration <= (using BST Class)\n";
        cout << "7. Mark a task as completed (using Heap Class)\n";
        cout << "8. Display completed tasks and category report (using Heap Class)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                string text, group;
                int minutes;
                cout << "Enter task description: ";
                getline(cin, text);
                cout << "Enter duration: ";
                cin >> minutes;
                cin.ignore();
                cout << "Enter category: ";
                getline(cin, group);
                activeTasks.addTask(text, minutes, group);
                cout << "Task added successfully.\n";
                break;
            }
            case 2:
                activeTasks.printAll();
                break;
            case 3: {
                int minutes;
                cout << "Enter duration to search: ";
                cin >> minutes;
                activeTasks.findTasks(minutes);
                break;
            }
            case 4: {
                int minutes;
                cout << "Enter duration to remove: ";
                cin >> minutes;
                activeTasks.removeTasks(minutes);
                break;
            }
            case 5: {
                int minutes;
                cout << "Enter minimum duration: ";
                cin >> minutes;
                activeTasks.printLonger(minutes);
                break;
            }
            case 6: {
                int minutes;
                cout << "Enter maximum duration: ";
                cin >> minutes;
                activeTasks.printShorter(minutes);
                break;
            }
            case 7: {
                int minutes;
                string desc;
                cout << "Enter task duration: ";
                cin >> minutes;
                cin.ignore();
                cout << "Enter part of description: ";
                getline(cin, desc);
                
                TaskItem completedTask;
                if (activeTasks.findAndRemoveTask(minutes, desc, completedTask)) {
                    cout << "Task found and marked as completed:\n";
                    completedTask.print();
                    completedTasks.addDoneTask(completedTask.text, completedTask.minutes, completedTask.group);
                    cout << "Task removed from active tasks and added to completed tasks.\n";
                } else {
                    cout << "No matching task found.\n";
                }
                break;
            }

            case 8:
                cout << "Completed tasks:\n";
                completedTasks.printDoneTasks();
                cout << "\nCategory report:\n";
                completedTasks.printCategoryCounts();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}