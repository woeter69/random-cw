#include <iostream>

using namespace std;

struct Process {
  int id;
  int at;
  int bt;
  int rt;
  int ct;
  int tat;
  int wt;
};

void swap(Process &a, Process &b) {
  Process temp = a;
  a = b;
  b = temp;
}

int main() {
  int n, run_time;
  float total_tat = 0;
  float total_wt = 0;

  Process p[100];
  int queue[1000];
  int front = 0;
  int rear = 0;

  int in_queue[100] = {0};

  cout << "Enter number of Processes: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    p[i].id = i + 1;
    cout << "Enter AT time for P" << i + 1 << ": ";
    cin >> p[i].at;
    cout << "Enter BT time for P" << i + 1 << ": ";
    cin >> p[i].bt;
    p[i].rt = p[i].bt;
  }
  
  cout << "Enter Running time: ";
  cin >> run_time;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (p[j].at > p[j + 1].at) {
        swap(p[j], p[j + 1]);
      }
    }
  }

  int current_time = 0;
  int completed = 0;

  while (completed != n) {
    for (int i = 0; i < n; i++) {
      if (p[i].at <= current_time && in_queue[i] == 0 && p[i].rt > 0) {
        queue[rear++] = i;
        in_queue[i] = 1;
      }
    }

    if (front == rear) {
      current_time++;
    }
    else {
      int index = queue[front++];
      if (p[index].rt > run_time) {
        current_time += run_time;
        p[index].rt = p[index].rt - run_time;
        for (int i = 0; i < n; i++) {
          if (p[i].at <= current_time && in_queue[i] == 0 && p[i].rt > 0) {
            queue[rear++] = i;
            in_queue[i] = 1;
          }
        }
        queue[rear++] = index;
      }
      else {
        completed++;
        current_time += p[index].rt;
        p[index].ct = current_time;
        p[index].tat = p[index].ct - p[index].at;
        p[index].wt = p[index].tat - p[index].bt;

        total_wt += p[index].wt;
        total_tat += p[index].tat;
        cout << "PID: " << p[index].id << "\n" << "Arrival Time: " << p[index].at << "\n" << "Burst Time: " << p[index].bt << "\t" << "Current Time: " << p[index].ct << "\n" << "Turn Around Time: " << p[index].tat << "\n" << "Waiting Time: " << p[index].wt << "\n";

        for (int i = 0; i < n; i++) {
          if (p[i].at <= current_time && in_queue[i] == 0 && p[i].rt > 0) {
            queue[rear++] = i;
            in_queue[i] = 1;
          }
        }
      }
    }
  }
  cout << "\nAverage TAT: " << total_tat / n << "\n";
  cout << "Average WT: " << total_wt / n << "\n";

  return 0;
}
