#include<iostream>
using namespace std;

int N, arr[10];

int biSearch(int low, int high, int value){
  while(low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == value) return mid;
    if(arr[mid] < value){
      low = mid + 1;
    }else high = mid - 1;
  }
  return -1;
}

int main(){
  cin >> N; for(int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  int value = 3;
  int idx = biSearch(0, N - 1, value);
  cout << idx << endl;
  return 0;
}