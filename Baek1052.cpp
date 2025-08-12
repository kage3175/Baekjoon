#include <iostream>

using namespace std;

int onesInBinary(long long x){
  long long temp = x;
  int cnt = 0;
  while(temp > 0){
    if(temp%2 == 1){
      cnt++;
    }
    temp = temp >> 1;
  }
  return cnt;
}

long long next_power_of_two(long long x) {
    long long power = 1;
    while (power < x) {
        power *= 2;
    }
    return power;
  }


int main(){
  long long n;
  int k;

  cin >> n >> k;

  if(onesInBinary(n) <= k){
    cout << 0 << endl;
    return 0;
  }

  if(onesInBinary(n+1) == 1){
    // binary form 1111...11 case
    cout << 1 << endl;
    return 0;
  }

  //else, there's at least one 0 in binary form
  int pos = 1;
  long long x = n;
  while(pos < n){
    //cout << "HMM: " << x << " " << pos << endl;
    if((x & pos) == 0){
      // found zero
      x = ((x | pos) & (~(pos - 1)));
      //cout << x << " " << pos << endl;
      if(onesInBinary(x) <= k){
        cout << x - n << endl;
        return 0;
      }
    }

    pos = pos << 1; // 0000010 -> 0000100
  }

  cout << next_power_of_two(n) - n << endl;

  return 0;
}