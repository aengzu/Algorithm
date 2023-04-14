#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// UnionFind 클래스 정의
// Disjoint Set(서로소 집합) 자료구조를 구현한 클래스

typedef vector<int> vi;

class UnionFind {
private:
  // p: 각 노드의 부모를 저장하는 배열, 초기에는 자기 자신을 가리킴
  // rank: 각 노드의 깊이(트리의 높이)를 저장하는 배열
  // setSize: 각 집합의 크기를 저장하는 배열
	vi p, rank, setSize;
  // numSets: 현재 집합의 개수를 저장하는 변수
	int numSets;

public:
  // UnionFind(N): N개의 노드를 가지는 집합을 초기화하는 생성자
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
  // findSet(i): i가 속한 집합의 대표를 반환하며, 경로 압축(Path Compression) 기법을 사용하여 부모를 갱신함
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  // isSameSet(i, j): i와 j가 같은 집합에 속해있는지 여부를 반환함
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  // unionSet(i, j): i와 j가 속한 두 집합을 합치며, Union-by-Rank 기법을 사용하여 균형을 유지함
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
  // numDisjointSets(): 현재 서로소인 집합의 개수를 반환함
	int numDisjointSets() { return numSets; }
  // sizeOfSet(i): i가 속한 집합의 크기를 반환함
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
