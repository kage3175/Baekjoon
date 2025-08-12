#include <iostream>

using namespace std;

int main(){

  int n, m;
  cin >> n >> m;
  int lowest6 = 1001; int lowest1 = 1001;
  int a, b;

  for(int i = 0; i < m; i++){
    cin >> a >> b;  
    if(lowest6 > a) lowest6 = a;
    if(lowest1 > b) lowest1 = b;
  }

  if(lowest1 * 6 <= lowest6){
    cout << lowest1 * n << endl;
  }
  else{
    int tobuy6 = n / 6;
    int temp_result = tobuy6 * lowest6 + (n - tobuy6 * 6) * lowest1;
    if(temp_result > (tobuy6 + 1) * lowest6) temp_result = (tobuy6 + 1) * lowest6;
    cout << temp_result << endl;
  }

  

  return 0;
}