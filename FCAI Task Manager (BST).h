//https://www.linkedin.com/in/mousa123/

#include <iostream>
#include <string>
using namespace std;

struct TaskItem {
    string text;
    int minutes;
    string group;

    void print() {
        cout << "[" << text << ", " << minutes << ", " << group << "]" << endl;
    }
};

struct TreeNode {
    TaskItem data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(TaskItem t) : data(t), left(nullptr), right(nullptr) {}
};

class TaskBST {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, TaskItem newTask) {
        if (!node) return new TreeNode(newTask);
        
        if (newTask.minutes <= node->data.minutes)
            node->left = insertHelper(node->left, newTask);
        else
            node->right = insertHelper(node->right, newTask);
            
        return node;
    }

    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        node->data.print();
        inOrder(node->right);
    }

    void searchHelper(TreeNode* node, int duration) {
        if (!node) return;
        
        searchHelper(node->left, duration);
        
        if (node->data.minutes == duration) {
            node->data.print();
        }
        
        searchHelper(node->right, duration);
    }

    TreeNode* removeHelper(TreeNode* node, int duration, bool& removed) {
        if (!node) return nullptr;

        if (duration < node->data.minutes) {
            node->left = removeHelper(node->left, duration, removed);
        } 
        else if (duration > node->data.minutes) {
            node->right = removeHelper(node->right, duration, removed);
        }
        else {
            removed = true;
            if (!node->left) return node->right;
            if (!node->right) return node->left;

            TreeNode* minRight = node->right;
            while (minRight->left) minRight = minRight->left;
            node->data = minRight->data;
            node->right = removeHelper(node->right, minRight->data.minutes, removed);
        }
        return node;
    }

    void longerHelper(TreeNode* node, int duration) {
        if (!node) return;
        longerHelper(node->right, duration);
        if (node->data.minutes >= duration) node->data.print();
        longerHelper(node->left, duration);
    }

    void shorterHelper(TreeNode* node, int duration) {
        if (!node) return;
        shorterHelper(node->left, duration);
        if (node->data.minutes <= duration) node->data.print();
        shorterHelper(node->right, duration);
    }

public:
    TaskBST() : root(nullptr) {}

    void addTask(string text, int minutes, string group) {
        root = insertHelper(root, {text, minutes, group});
    }

    void printAll() {
        inOrder(root);
    }

    void findTasks(int duration) {
        searchHelper(root, duration);
    }

    void removeTasks(int duration) {
        bool removed = false;
        root = removeHelper(root, duration, removed);
        cout << (removed ? "Tasks removed\n" : "No tasks found\n");
    }

    void printLonger(int duration) {
        longerHelper(root, duration);
    }

    void printShorter(int duration) {
        shorterHelper(root, duration);
    }

    TreeNode* getRoot() { return root; }

 string toLowerString(string str) const {
        for (char &c : str) c = tolower(c);
        return str;
    }



    bool findAndRemoveTask(int duration, const string& desc, TaskItem& removedTask) {
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (duration < current->data.minutes) {
                parent = current;
                current = current->left;
            } else if (duration > current->data.minutes) {
                parent = current;
                current = current->right;
            }
             else {
                // Convert both strings to lowercase for comparison
                string currentDescLower = toLowerString(current->data.text);
                string searchDescLower = toLowerString(desc);
                
                if (currentDescLower.find(searchDescLower) != string::npos) {
                    // Found matching task
                    removedTask = current->data;
                    
                    // Rest of the removal logic remains the same...
                    if (current->left == nullptr && current->right == nullptr) {
                        if (parent == nullptr) root = nullptr;
                        else if (parent->left == current) parent->left = nullptr;
                        else parent->right = nullptr;
                    } 
                    
                    return true;
                }
                current = current->left;
            }
        }
        return false;
    }
};