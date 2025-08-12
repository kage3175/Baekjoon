#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  if(n < 100){
    cout << n << endl;
    return 0;
  }
  int cnt = 99;

  for(int i = 111; i <= n; i++){
    int a0 = i % 10;
    int a1 = (i % 100) / 10;
    int a2 = (i - a1 - a0) / 100;
    if(a2 - a1 == a1 - a0){
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}