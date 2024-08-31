#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }

    void markTaskCompleted(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task " << taskNumber << " marked as completed." << endl;
    }

    void removeTask(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task " << taskNumber << " removed from the list." << endl;
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    int taskNumber;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;

            case 2:
                todoList.viewTasks();
                break;

            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;

            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
