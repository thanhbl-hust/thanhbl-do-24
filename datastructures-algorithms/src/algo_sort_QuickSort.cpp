#include<iostream>
using namespace std;

int n, arr[10];

int getpivot(int low, int high){
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j < high; j++){
    if(arr[j] < pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int low, int high){
  if(low < high){
    int pi = getpivot(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  quickSort(0, n - 1);
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}