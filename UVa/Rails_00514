#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> st;
int target[1000];
int main() {
	int t = 0;
  //기차 번호 입력받는다.
	cin >> t;
	while (true) {
  //0이면 종료하기
		if (t == 0)
			break;
		while (true) {
    //target 이라는 배열에다가 해당 만들어야하는 쿼리 입력받기
    //만약 첫 글자 0이면 종료
			cin >> target[0];
			if (target[0] == 0) {
				cout << endl;
				break;
			}
			for (int i = 1; i < t; i++) {
				cin >> target[i];
			}

			//target 인덱스 변수와 스택에 값을 넣기위한 변수 생성
			int target_indx = 0;
			int k = 1;
			while (k<=t) {
      // t만큼 스택에 넣어줄텐데 한 개 씩 넣어야함 target 의 가장 왼쪽 요소가 방금 넣은 수일 수도 있기 때문
				st.push(k);
        // 스택이 비어있지 않고 스택의 탑이 타겟의 가장 왼쪽값과 일치하다면
				while (!st.empty()&&st.top() == target[target_indx]) {
        // 타겟 인덱스 ++ 해서 다음 요소 확인
						target_indx++;
            // 스택에서통과했으므로 pop해줌
						st.pop();
            //만약 타겟 인덱스가 타겟의 size를 넘어가면 break
						if (target_indx >= t) break;
				}
        // 스택에 다음요소를 넣기 위해 k++ 해줌
				k++;
			}
      
      // 모든 게 끝나고 스택에 요소가 남아 있다면 해당 쿼리를 만들 수 없다는 의미이다.
			if (!st.empty())
				cout << "No" << endl;
			else {
				cout << "Yes" << endl;
			}
			
		}

	}


	return 0;
}
