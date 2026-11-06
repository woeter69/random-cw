#include <iostream>

using namespace std;

struct Process {
  int id;
  int at;
  int bt;

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
  int n;
  float total_tat = 0;
  float total_wt = 0;

  Process p[100];

  cout << "Enter number of process: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    p[i].id = i + 1;
    cout << "Enter AT time for P" << i + 1 << ": ";
    cin >> p[i].at;
    cout << "Enter BT time for P" << i + 1 << ": ";
    cin >> p[i].bt;
  }
  
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (p[j].at > p[j+1].at) {
        swap(p[j], p[j+1]);
      }
    }
  }
  int current_time = 0;
  for (int i = 0; i < n; i++) {
    if (current_time < p[i].at) {
      current_time = p[i].at;
    }
    current_time += p[i].bt;
    p[i].ct = current_time;
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
    total_wt += p[i].wt;
    total_tat += p[i].tat;

    cout << "PID: " << p[i].id << "\n" << "Arrival Time: " << p[i].at << "\n" << "Burst Time: " << p[i].bt << "\n" << "Completion Time: " << p[i].ct << "\n" << "Turn Around Time: " << p[i].tat << "\n" << "Waiting Time: " << p[i].wt << "\n";
  }
  cout << "\nAverage TAT: " << total_tat / n << "\n";
  cout << "Average WT: " << total_wt / n << "\n";
  
  return 0;
}
