#include <iostream>

using namespace std;

class Fraction{
  public:
    Fraction(){numerator = -1; denominator = 1;}
    Fraction(int num, int den) {
      if(num <= 0){
        numerator = 1;
      }
      else numerator = num;
      if(denominator <= 0) denominator = 1;
      else denominator = den;
      int x = gcd(numerator, denominator);
      numerator = numerator / x;
      denominator = denominator / x;
    }
    int gcd(int a, int b){
      int tmp, n;
      if(a < b){
        tmp = a; a = b; b = tmp;
      }
      while(b != 0){
        n = a%b;
        a = b;
        b = n;
      }
      return a;
    }

    int getNumerator(){
      return numerator;
    }
    int getDenominator(){
      return denominator;
    }

  private:
    int numerator;
    int denominator;
};

int main(){

  int n;
  cin >> n;
  Fraction matrix[11][11];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matrix[i][j] = Fraction();
    }
  }
  
  for(int i = 0; i < n; i++){
    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;
    matrix[a][b] = Fraction(c, d);
    matrix[b][a] = Fraction(d, c);

  }

  Fraction ratio[11];
  ratio[0] = Fraction(1,1);
  for(int i = 1; i < n; i++) ratio[i] = Fraction();

  return 0;
}