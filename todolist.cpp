#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    string dueDate;
};

vector<Task> todoList;

void addTask() {
    Task t;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, t.name);

    cout << "Enter due date (DD/MM/YYYY): ";
    getline(cin, t.dueDate);

    todoList.push_back(t);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks in the to-do list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < todoList.size(); i++) {
        cout << i + 1 << ". Task: " << todoList[i].name
             << ", Due Date: " << todoList[i].dueDate << endl;
    }
}

void removeTask() {
    if (todoList.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    todoList.erase(todoList.begin() + index - 1);
    cout << "Task removed successfully!\n";
}

// Main menu
void menu() {
    int choice;
    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            removeTask();
            break;
        case 4:
            cout << "Exiting To-Do List...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

// Main function
int main() {
    menu();
    return 0;
}
