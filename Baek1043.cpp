#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Person{
  public:
    Person(){num = 1; know = false; parent = this;}
    Person(int num_, bool know_) : num(num_), know(know_) {parent = this;}
    Person* find(Person* target){
      if(target == parent){
        return parent;
      }
      else if(parent != nullptr){
        return find(parent);
      }
      else{
        //cout << "OOPS" << endl;
        return nullptr;
      }
    }
    void union_group(Person* target){
      Person* parent1 = find(this);
      Person* parent2 = target->find(target);
      if(parent1 != parent2){
        // should union
        if(parent1->isKnow()){
          parent2->setParent(parent1);
          target->setParent(parent1);
        }
        else{
          parent1->setParent(parent2);
          this->setParent(parent2);
        }
      }
    }
    void setParent(Person* target){
      parent = target;
    }
    bool isKnow(){
      return know;
    }
    void setKnow(bool know_){
      know = know_;
    }
    int getNum(){
      return num;
    }
    Person* getParent(){
      return parent;
    }
  private:
    int num;
    bool know;
    Person* parent;
};

int main(){
  int n, m;
  cin >> n >> m;
  Person** person = new Person*[n + 1];
  vector<Person*> party[50];

  for(int i = 1; i <= n; i++){
    person[i] = new Person(i, false);
  }

  string line;
  cin.ignore();
  int cnt;
  int value;
  getline(cin, line);
  stringstream ss(line);
  
  // 시작부터 true인 친구들
  ss >> cnt;
  for(int i = 0; i < cnt; i++){
    ss >> value;
    person[value]->setKnow(true);
  }
  

  // union
  for(int i = 0; i < m; i++){
    getline(cin, line);
    ss.str(line);
    ss.clear();
    ss >> cnt;
    //cout << "cnt: " << cnt << endl;
    Person* currPerson = nullptr;
    if(cnt <= 1){
      ss >> value;
      party[i].push_back(person[value]);
      continue;
    }

    for(int j = 0; j < cnt; j++){
      ss >> value;
      //cout << value << endl;
      party[i].push_back(person[value]); // 파티에 넣기
      if(j == 0){
        currPerson = person[value];
        continue;
      }
      person[value]->union_group(currPerson);
      //cout << "person " << value << " has unioned with person " << currPerson->getNum() << endl;
      currPerson = person[value];
    }
  }

  // for(int i = 1; i <= n; i++){
  //   cout << "Parent of Person " << i << ": " << person[i] -> getParent() -> getNum() << ", " << person[i]->getParent()->isKnow() << endl;
  // }

  cnt = 0;
  bool flag = false;

  // for(int i = 0; i < m; i++){
  //   cout << party[i].size() << endl;
  // }

  for(int i = 0; i < m; i++){
    flag = false;
    for (Person* x : party[i]){
      if(x->getParent()->isKnow()){
        flag = true;
        //cout << "Party "<<i<<" Not allowed"<<endl;
        break;
      }
    }

    if(!flag){ // nobody new the truth in the party
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}