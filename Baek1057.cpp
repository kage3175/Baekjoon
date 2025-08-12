#include <iostream>

using namespace std;

int nextRoundNum(int num){
  if(num % 2 == 0){
    return num/2;
  }
  else{
    return (num+1)/2;
  }
}

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int n, lim, kim;

  cin >> n >> kim >> lim;

  if(kim > lim) swap(kim, lim);

  int cnt = 1;

  while(true){
    if((kim % 2 == 1) && kim + 1 == lim){
      // done
      cout << cnt << endl;
      break;
    }
    else if(kim >= lim){
      cout << -1 << endl;
      break;
    }
    else{
      kim = nextRoundNum(kim);
      lim = nextRoundNum(lim);
      cnt++;
    }
  }

  return 0;
}