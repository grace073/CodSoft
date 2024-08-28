#include <iostream>
#include <string>
#include <map>
#include <limits> // Include this header

using namespace std;

enum TaskState { PENDING, DONE }; // Enum for task states

void addTask(map<int, string> &tasks, map<int, TaskState> &taskStates, int &taskId) {
    int continueAdding;
    string taskDetails;

    do {
        cin.ignore(); 
        cout << "Enter Task Description: ";
        getline(cin, taskDetails);
        tasks[taskId] = taskDetails;
        taskStates[taskId] = PENDING; // Set task state to PENDING
        cout << "Task #" << taskId << " added successfully!\n";
        taskId++;
        cout << "Would you like to add another task? (1 = Yes / 0 = No): ";
        cin >> continueAdding;
    } while (continueAdding);
}

void showTasks(const map<int, string> &tasks, const map<int, TaskState> &taskStates) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\nCurrent Tasks:\n";
    for (const auto& task : tasks) {
        cout << "Task #" << task.first << " : " << task.second << " ---> ["
             << (taskStates.at(task.first) == DONE ? "Done" : "Pending") << "]\n";
    }
}

void deleteTask(map<int, string> &tasks, map<int, TaskState> &taskStates) {
    int removeId;
    cout << "Enter task number to remove: ";
    cin >> removeId;
    
    if (tasks.find(removeId) != tasks.end()) {
        tasks.erase(removeId);
        taskStates.erase(removeId);
        cout << "Task #" << removeId << " was successfully removed!\n";
    } else {
        cout << "Task not found!\n";
    }
}

void completeTask(map<int, string> &tasks, map<int, TaskState> &taskStates) {
    int completeId;
    cout << "Enter task number to mark as done: ";
    cin >> completeId;
    
    if (tasks.find(completeId) != tasks.end()) {
        taskStates[completeId] = DONE;
        cout << "Task #" << completeId << " marked as done!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int getUserOption() {
    int option;
    while (true) {
        cout << "\n------------------ TASK MANAGER ------------------\n";
        cout << "1. Add New Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Complete Task\n";
        cout << "5. Exit Program\n";
        cout << "Enter your selection: ";
        
        if (cin >> option && option >= 1 && option <= 5) {
            return option;
        } else {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Use numeric_limits correctly
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        }
    }
}

int main() {
    int taskId = 1;
    map<int, string> tasks;
    map<int, TaskState> taskStates;

    while (true) {
        int userOption = getUserOption();

        switch (userOption) {
            case 1:
                addTask(tasks, taskStates, taskId);
                break;
            case 2:
                showTasks(tasks, taskStates);
                break;
            case 3:
                deleteTask(tasks, taskStates);
                break;
            case 4:
                completeTask(tasks, taskStates);
                break;
            case 5:
                cout << "Thank you for using Task Manager!\n";
                return 0;
            default:
                cout << "Invalid option, please select again...\n";
                break;
        }
    }

    return 0;
}
