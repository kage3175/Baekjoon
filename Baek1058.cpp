#include <iostream>
#include <set>

using namespace std;


int main(){
  int n;
  cin >> n;
  cin.ignore();
  bool friendMatrix[51][51];
  set<int> twoFriends[51];

  for(int i = 0; i < n; i ++){
    string input;
    cin >> input;
    for(int j = 0; j < n;j++){
      if(input[j] == 'N'){
        friendMatrix[i][j] = false;
        friendMatrix[j][i] = false;
      }
      else{
        friendMatrix[i][j] = true;
        friendMatrix[j][i] = true;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(friendMatrix[i][j]){
        twoFriends[i].insert(j);
        twoFriends[j].insert(i);
        for(int k = j+1; k < n; k++){
          if(friendMatrix[i][k]){
            twoFriends[j].insert(k);
            twoFriends[k].insert(j);
          }
        }
      }
    }
  }

  int maxFriends = 0;

  for(int i = 0; i < n; i++){
    if(twoFriends[i].size() > maxFriends) maxFriends = twoFriends[i].size();
  }

  cout << maxFriends << endl;

  return 0;
}