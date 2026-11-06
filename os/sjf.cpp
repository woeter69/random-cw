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
  int is_completed[100] = {0};
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
  int completed = 0;

  while (completed != n) {
    int min_index = -1;
    int min_bt = 999999;

    for (int i = 0; i < n; i++) {
      if (p[i].at <= current_time && is_completed[i] == 0) {
        if (p[i].bt < min_bt) {
          min_bt = p[i].bt;
          min_index = i;
        }
        else if (p[i].bt == min_bt) {
          if (p[i].at < p[min_index].at) {
            min_index = i;
          }
        }
      }
    }

    if (min_index != -1) {
      current_time += p[min_index].bt;
      p[min_index].ct = current_time;
      p[min_index].tat = p[min_index].ct - p[min_index].at;
      p[min_index].wt = p[min_index].tat - p[min_index].bt;
        
      total_wt += p[min_index].wt;
      total_tat += p[min_index].tat;
      is_completed[min_index] = 1;
      completed++;

      cout << "PID: " << p[min_index].id << "\n" << "Arrival Time: " << p[min_index].at << "\n" << "Burst Time: " << p[min_index].bt << "\t" << "Current Time: " << p[min_index].ct << "\n" << "Turn Around Time: " << p[min_index].tat << "\n" << "Waiting Time: " << p[min_index].wt << "\n";
    } 
    else {
      current_time++;
    }
  }  
  cout << "\nAverage TAT: " << total_tat / n << "\n";
  cout << "Average WT: " << total_wt / n << "\n";
  return 0;
}

