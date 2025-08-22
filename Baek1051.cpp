#include <iostream>

using namespace std;

int main(){

  int n, m;
  int arr[50][50];
  cin >> n >> m;
  cin.ignore();

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m; j++){
      arr[i][j] = s[j] - '0';
    }
  }
  
  int x = n > m ? m : n;
  bool found = false;
  for(int size = x; size >= 2; size--){
    for(int i = 0; i <= n - size; i++){
      for(int j = 0; j <= m - size; j++){
        if((arr[i][j] == arr[i][j+size-1] && arr[i][j] == arr[i+size-1][j]) && arr[i][j] == arr[i+size-1][j+size-1]){
          found = true;
          cout << size * size << endl;
          break;
        }
      }
      if(found) break;
    }
    if(found) break;
  }

  if(!found){
    cout << 1 << endl;
  }

  return 0;
}