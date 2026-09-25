#include <iostream>

using namespace std;

void count_sightings(int arr[], int n, int size) {
  int *count= new int[size];

  for(int i = 0; i < size; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count[arr[i]]++; 
  }

  for (int i = 0; i < size; i++) {
    if (count[i] > 0) {
      cout << "Type " << i << " has :" << count[i] << " sightings " <<endl;
    }
  }
  delete[] count;
}
int main() {
  int max_id, num_birds;
  
  cout << "Enter total of birds seen: ";
  cin >> num_birds;

  cout << "Enter Maximum Id: ";
  cin >> max_id;
  
  int array_size = max_id+1;
  int sightings[num_birds];
  
  cout << "Enter the sightings";
  for (int i = 0; i < num_birds; i++) {
    cin >> sightings[i];
  }
  
  count_sightings(sightings,num_birds,array_size);

  return 0;
}
