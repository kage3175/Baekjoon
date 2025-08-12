#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

  int x, y, d, t;

  cin >> x >> y >> d >> t;

  double time = 0;
  double distance = sqrt(pow(x, 2) + pow(y, 2));
  double distanceSaved = distance;

  while(distance >= d){
    distance -= d;
    time += t;
  } // 일단 안 넘어가는 선에서 최대한 점프로 이동

  // 남은 거리는 무조건 점프거리보다 짧다
  // case1: 점프로 넘어갔다가 돌아오기
  // case2: 그냥 정속주행하기
  // case3: 총 거리를 점프로만 적절히 가기
  // case4: 점프 없이 가기(d/t가 1보다 작은 경우)

  double time1 = (d - distance) + t + time;
  double time2 = time + distance;
  double time3 = max(2.0, ceil(distanceSaved / d)) * t;
  double time4 = distanceSaved;

  cout << fixed << setprecision(12) << min(min(time1, time4), min(time2, time3)) << endl;

  return 0;
}