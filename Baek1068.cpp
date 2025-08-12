#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node{
  public:
    Node(Node* p): parent(p), isroot(false) {}
    Node(): parent(nullptr), isroot(false) {}
    void addChild(Node* c){
      childs.push_back(c);
    }
    void setRoot(){
      isroot = true;
    }
    size_t getChildNum(){
      return childs.size();
    }
    void setParent(Node* p){
      parent = p;
    }
    Node* getParent(){
      return parent;
    }
    bool isRoot(){
      return isroot;
    }
    const vector<Node*>& getChildList() const { return childs; }
    void deleteChild(Node* child){
      for(auto it = childs.begin(); it != childs.end();){
        if(*it == child){
          it = childs.erase(it);
        }
        else{
          ++it;
        }
      }
    }
  private:
    Node* parent;
    vector<Node*> childs;
    bool isroot;
};

int main(){

  int n;
  cin >> n;
  vector<Node> nodeList;
  nodeList.reserve(n);
  for (int i = 0; i < n; ++i) {
    nodeList.emplace_back(); // 또는 nodeList.push_back(Node{});
  }

  for(int i = 0; i < n; i++){
    int value;
    cin >> value;
    if(value == -1){
      nodeList[i].setParent(nullptr);
      nodeList[i].setRoot();
    }
    else{
      nodeList[i].setParent(&(nodeList[value]));
      nodeList[value].addChild(&(nodeList[i]));
    }
  }

  int toErase;
  cin >> toErase;

  if(nodeList[toErase].isRoot()){
    // erasing the root
    cout << 0 << endl;
    return 0;
  }

  nodeList[toErase].getParent()->deleteChild(&(nodeList[toErase]));
  nodeList[toErase].setParent(nullptr);

  Node* root = nullptr;

  for(Node& x: nodeList){
    if(x.isRoot()){
      root = &x;
      break;
    }
  }

  int cnt = 0;  

  stack<Node*> nodeStack;
  nodeStack.push(root);

  while(!nodeStack.empty()){
    Node* currNode = nodeStack.top();
    nodeStack.pop();
    if(currNode->getChildNum() == 0){
      cnt++;
      continue;
    }
    else{
      // has child
      vector<Node*> childList = currNode->getChildList();
      for(Node* c: childList){
        nodeStack.push(c);
      }
    }
  }

  cout << cnt << endl;

  return 0;
}