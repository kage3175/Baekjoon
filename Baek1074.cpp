#include <iostream>

using namespace std;

int relativePosInNSquare(int n, int r1, int c1){
  int datum = 1LL << (n - 1);
  if(r1 < datum){
    if(c1 < datum) return 0;
    else return 1;
  }
  else{
    if(c1 < datum) return 2;
    else return 3;
  }
}

int calculateR(int n, int r, int relative){
  if(relative <= 1) return r;
  else return r - (1LL << (n - 1));
}

int calculateC(int n, int c, int relative){
  if(relative % 2 == 0) return c;
  else return c - (1LL << (n - 1));
}
int main(){

  int n, r, c;
  cin >> n >> r >> c;

  long long toAdd = 0;
  int nowN = n;

  while(nowN >= 1){
    int x = relativePosInNSquare(nowN, r, c);
    toAdd += (1LL << (2 * nowN - 2)) * x;
    r = calculateR(nowN, r, x); c = calculateC(nowN, c, x);
    nowN--;
  }

  cout << toAdd << endl;


  return 0;
}