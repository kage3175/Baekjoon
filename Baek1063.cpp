#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Position{ // zero base 0~7
  public:
    Position(string s){
      row = s[1] - '1';
      column = s[0] - 'A';
    }
    Position(int r, int c): row(r), column(c) {}
    int getRow(){return row;}
    int getColumn(){return column;}
    void move(vector<int> co){
      int rowMove = co[0];
      int colMove = co[1];
      row += rowMove;
      column += colMove;
      if(row < 0) row = 0;
      if(row > 7) row = 7;
      if(column < 0) column = 0;
      if(column > 7) column = 7; 
    }
    bool isValidMove(vector<int> co){
      int rowMove = co[0];
      int colMove = co[1];
      int newRow = row + rowMove;
      int newColumn = column + colMove;
      return ((newRow <= 7 && newRow >= 0) && (newColumn <= 7 && newColumn >= 0));
    }
    bool isRockThere(Position* rockPos, vector<int> co){
      int rowMove = co[0];
      int colMove = co[1];
      int newRow = row + rowMove;
      int newCol = column + colMove;
      if(rockPos->getRow() == newRow && rockPos->getColumn() == newCol) return true;
      return false;
    }
    void print(){
      //cout << "Debug: " << column << endl;
      cout << char('A' + column) << row + 1 << endl;
    }
  private:
    int row;
    int column;
};

vector<int> makeMoveVector(string s){
  vector<int> v;
  if(s == "R"){
    return {0, 1};
  }
  else if(s == "L"){
    return {0, -1};
  }
  else if(s == "B"){
    return {-1, 0};
  }
  else if(s == "T"){
    return {1, 0};
  }
  else if(s == "RT"){
    return {1,1};
  }
  else if(s == "LT"){
    return {1,-1};
  }
  else if(s == "RB"){
    return {-1,1};
  }
  else return {-1,-1};
}

int main(){
  string kingposs, rockposs;
  int n;  

  cin >> kingposs >> rockposs >> n;

  Position kingPos(kingposs);
  Position rockPos(rockposs);
  cin.ignore();

  for(int i = 0; i < n; i++){
    string moveInfo;
    cin >> moveInfo;
    vector<int> v = makeMoveVector(moveInfo);

    if(kingPos.isRockThere(&rockPos, v)){
      // 그곳에 돌이 있는 경우
      if(rockPos.isValidMove(v) && kingPos.isValidMove(v)){
        // 돌이 이동할 수 있는 경우
        kingPos.move(v);
        rockPos.move(v);
      }
      else{
        continue;
      }
    }
    else{
      if(kingPos.isValidMove(v)){
        kingPos.move(v);
      }
      else{continue;}
    }

  }

  kingPos.print();
  rockPos.print();

  return 0;
}