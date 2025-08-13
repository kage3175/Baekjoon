#include <iostream>
#include <sstream>

using namespace std;

void convert33(int arr[][50], int row, int col){
  for(int i = row; i < row + 3; i++){
    for(int j = col; j < col + 3; j++){
      if(arr[i][j] == 0) arr[i][j] = 1;
      else arr[i][j] = 0;
    }
  }
}

bool isSame(int arr[][50], int arr2[][50], int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(arr[i][j] != arr2[i][j]) return false;
    }
  }

  return true;
}

int main(){

  int n, m;
  cin >> n >> m;

  cin.ignore();
  int a[50][50];
  int b[50][50];
  stringstream ss;

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m; j++){
      a[i][j] = (int)(s[j] - '0');
    }
  }
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m; j++){
      b[i][j] = (int)(s[j] - '0');
    }
  }

  int cnt = 0;

  for(int i = 0; i < n - 2; i++){
    for(int j = 0; j < m - 2; j++){
      if(a[i][j] != b[i][j]){
        convert33(a, i, j);
        cnt++;
      }
    }
  }

  if(isSame(a, b, n , m)){
    cout << cnt << endl;
  }
  else{
    cout << -1 << endl;
  }

  return 0;
}