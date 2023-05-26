#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string name;
    int start;
    int end;

    Task(const string& n, int s, int e) : name(n), start(s), end(e) {}
};

bool compareTasks(const Task& t1, const Task& t2) {
    return t1.end < t2.end;
}

vector<Task> schedule(vector<Task>& tasks) {
    vector<Task> scheduledTasks;

    sort(tasks.begin(), tasks.end(), compareTasks);

    if (!tasks.empty()) {
        scheduledTasks.push_back(tasks[0]);
        int lastEndTime = tasks[0].end;

        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i].start >= lastEndTime) {
                scheduledTasks.push_back(tasks[i]);
                lastEndTime = tasks[i].end;
            }
        }
    }

    return scheduledTasks;
}

int main() {
    int numTasks;
    cout << "Nhap so luong cong viec: ";
    cin >> numTasks;
    cout << "\n";

    vector<Task> tasks;
    for (int i = 0; i < numTasks; i++) {
        string name;
        int start, end;

        cout << "Nhap ten cong viec " << i + 1 << ": ";
        cin >> name;
        cout << "\n";

        cout << "Nhap thoi gian bat dau cong viec " << i + 1 << ": ";
        cin >> start;
        cout << "\n";

        cout << "Nhap thoi gian ket thuc cong viec " << i + 1 << ": ";
        cin >> end;
        cout << "\n";

        tasks.push_back(Task(name, start, end));
    }

    vector<Task> scheduledTasks = schedule(tasks);

    if (scheduledTasks.empty()) {
        cout << "Khong co cong viec nao duoc sap xep." << "\n";
    }
    else {
        cout << "Cac cong viec da sap xep:" << "\n";
        for (const auto& task : scheduledTasks) {
            cout << "Ten cong viec: " << task.name << ", Bat dau: " << task.start << ", Ket thuc: " << task.end << "\n";
        }
    }

    return 0;
}
