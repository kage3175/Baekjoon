#include <iostream>
#include <cmath>

using namespace std;

bool check(int target){


}

int calculateZ(long long x, long long y){
  return static_cast<int>((y * 100) / x);
}

int main(){

  long long x, y;

  cin >> x >> y;

  const int init = calculateZ(x, y);

  if(init >= 99){
    cout << -1 << endl;
    return 0;
  }
  if(x == 1){
    if(y == 0){
      cout << 1 << endl;
      return 0;
    }
  }

  long long left = 1; long long right = x;
  long long mid;

  while(left < right){
    mid = left + (right - left) / 2;
    //cout << "mid: " << mid << endl;
    //cout << calculateZ(x + mid, y + mid) << endl;
    if(calculateZ(x + mid, y + mid) >= init + 1){
      right = mid;
    }
    else{
      left = mid;
    }

    if(left + 1 >= right){
      if(calculateZ(x + left, y + left) >= init + 1){
        cout << left << endl;
        break;
      }
      else{
        cout << left + 1 << endl;
        break;
      }
    }
  }

  return 0;
}