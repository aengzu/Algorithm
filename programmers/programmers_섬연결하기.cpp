#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;

public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
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
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
bool cmp(vector<int> arr1, vector<int> arr2) {
	if (arr1[2] == arr2[2]) {
		if (arr1[0] == arr2[0])
			return arr1[1] < arr2[1];
		else return arr1[0] < arr2[0];
	}
	else return arr1[2] < arr2[2];
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	UnionFind u = UnionFind(n);
	sort(costs.begin(), costs.end(), cmp);

	for(auto i: costs){
		if (!u.isSameSet(i[0], i[1])) {
			u.unionSet(i[0], i[1]);
			answer += i[2];
		}
    }
		return answer;
}
