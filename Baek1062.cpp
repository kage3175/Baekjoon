#include <iostream>

using namespace std;

class Word{
  public:
    Word(string s_) : s(s_){
    }
    Word(){
      s="antci";
    }
    bool isPossible(bool* sample){
      int len = s.length();
      for(int i = 0; i < len; i++){
        if(!sample[s[i] - 'a']){
          return false;
        }
      }
      return true;
    }

  private:
    string s;
};

int main(){
  bool alphabets[26];
  for(int i = 0; i < 26; i++){
    alphabets[i] = false;
  }
  alphabets[0] = true; alphabets['c' - 'a'] = true; alphabets['n' - 'a'] = true;
  alphabets['t' - 'a'] = true; alphabets['i' - 'a'] = true;

  int n, k;
  Word words[50];

  cin >> n >> k;
  cin.ignore();

  if(k < 5){
    cout << 0 << endl;
    return 0;
  }
  if(k >= 26){
    cout << n << endl;
    return 0;
  }

  for(int i = 0; i < n; i++){
    string input;
    cin >> input;
    words[i] = Word(input);
  }


  return 0;
}