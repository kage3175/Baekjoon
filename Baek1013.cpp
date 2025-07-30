#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class State{
    private:
      int q;
      bool isFinal_ = false;
      unordered_map<char, shared_ptr<State>> transitions;
    public:
      State(int q, bool isFinal__ = false) : q(q), isFinal_(isFinal__) {}
      shared_ptr<State> transition(char c){
        auto it = transitions.find(c);
        if(it != transitions.end()){
          return it->second;
        }
        return nullptr;
      }
      void addTransition(char c, shared_ptr<State> nextState){
          transitions[c] = nextState;
      }
      bool isFinal(){
        return isFinal_;
      }
      int GetName(){
        return q;
      }
};

int main(){
  int t;
  auto start = make_shared<State>(0);
  auto q1 = make_shared<State>(1);
  auto q2 = make_shared<State>(2);
  auto q3 = make_shared<State>(3);
  auto q4 = make_shared<State>(4, true);
  auto q5 = make_shared<State>(5, true);
  auto q6 = make_shared<State>(6);
  auto q7 = make_shared<State>(7, true);
  auto inf = make_shared<State>(9);
  auto q8 = make_shared<State>(8);
  start->addTransition('1', q1); start->addTransition('0', q6);
  q1->addTransition('0', q2); q1->addTransition('1', inf);
  q2->addTransition('0', q3); q2->addTransition('1', inf);
  q3->addTransition('0', q3); q3->addTransition('1', q4);
  q4->addTransition('0', q6); q4->addTransition('1', q5);
  q5->addTransition('0', q8); q5->addTransition('1', q5);
  q6->addTransition('0', inf); q6->addTransition('1', q7);
  q7->addTransition('0', q6); q7->addTransition('1', q1);
  q8->addTransition('0', q3); q8->addTransition('1', q7);

  cin >> t;
  vector<string> input(t);
  for(int i = 0; i < t; i++){
    cin >> input[i];
  }

  for(int i = 0; i < t; i++){
    int length = input[i].length();
    auto currState = start;
    for(int j = 0; j < length; j++){
      if(currState == inf || currState == nullptr){
        break;
      }
      currState = currState->transition(input[i][j]);
    }
    if(currState != nullptr && currState->isFinal()){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }

  return 0;
}