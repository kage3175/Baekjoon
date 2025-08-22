#include <iostream>

using namespace std;

void swap(int* arr, int a, int b){
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int findMaxPos(int* arr, int from, int to){
  int x = 0;
  int pos = from;
  for(int i = from; i <= to; i++){
    if(arr[i] > x){
      x = arr[i];
      pos = i;
    }
  }

  return pos;
}

int main(){
  int n,s;
  cin >> n;
  int arr[51];

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> s;

  int left = s;
  int currPos = 0;

  while(left >= 0 && currPos < n - 1){
    int rightBound = currPos + left <= n - 1 ? currPos + left : n - 1;
    int maxPos = findMaxPos(arr, currPos, rightBound);
    for(int i = maxPos; i > currPos; i--){
      //sort from back side
      swap(arr, i, i - 1);
      left--;
    }
    currPos++;
  }

  for(int i = 0; i < n; i++){
    cout << arr[i];
    if(i != n - 1) cout << " ";
  }

  cout << endl;

  return 0;
}