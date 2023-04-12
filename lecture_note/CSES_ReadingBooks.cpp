#include <iostream>

typedef long long int lld;
using namespace std;

int main() {
  //long long int 타입 책의 개수 입력 받기
	lld n;
	cin >> n;
	int m = 0, sum = 0;
	int x;
	while (n -- ) {
    // 책의 걸리는 시간 입력받고
		cin >> x;
    // 기존 맥스값과 비교하여 가장 큰 책값 업뎃하기
		m = max(m, x);
    // 모든 책 읽는데 걸리는 시간 구하기
		sum += x;
	}
  //m의 맥스값 s 이 나머지 책 읽는 값이라고 할 때 둘 다 모든 책을 읽어야하므로 lower bound 는 m+s 이다.
  //하지만 만약 m>s 라면 가장 오랜시간 걸린 책 읽지 않은 사람은 무조건 기다리는 시간이 존재한다
	cout << (sum - m > m ? sum : m * 2) << endl;

	return 0;
}
