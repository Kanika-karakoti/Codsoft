#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TodoTask {
    string task;
    bool completed;
};

vector<TodoTask> todoList;

void addTask() {
    TodoTask task;
    cout << "Enter task: ";
    getline(cin, task.task);
    task.completed = false;
    todoList.push_back(task);
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    cout << "To-Do List:" << endl;
    for (int i = 0; i < todoList.size(); i++) {
        cout << "[" << i + 1 << "] " << todoList[i].task << " - " << (todoList[i].completed ? "Completed" : "Not Completed") << endl;
    }
}

void completeTask() {
    int taskNumber;
    cout << "Enter task number to complete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList[taskNumber - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void deleteTask() {
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList.erase(todoList.begin() + taskNumber - 1);
        cout << "Task deleted successfully." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "To-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Complete Task" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
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
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
