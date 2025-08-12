#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int l, n;

  cin >> l;
  int* s = new int[l];

  for(int i = 0 ; i < l; i++){
    int value;
    cin >> value;
    s[i] = value;
  }

  sort(s, s+l);

  cin >> n;

  int lb = 1, hb = s[l-1];

  if(s[0] > n){
    lb = 0;
    hb = s[0];
  }
  else{
    for(int i = 0; i < l; i++){
      if(s[i] == n){
        cout << 0 << endl;
        return 0;
      }
      else if(s[i] < n){
        lb = s[i];
      }
      else{
        hb = s[i];
        break;
      }
    }
  }

  

  int cnt = (hb - n) * (n - lb) - 1;
  if(cnt < 0) cnt = 0;
  //cout << hb << " " << lb << endl;
  cout << cnt << endl;

  return 0;
}