#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>


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
bool cmp(pair<pair<int, int>, int> arr1, pair<pair<int, int>, int> arr2) {
	if (arr1.second == arr2.second) {
		if (arr1.first.first == arr2.first.first)
			return arr1.first.second < arr2.first.second;
		else return arr1.first.first < arr2.first.first;
	}
	else return arr1.second > arr2.second;


}

int main() {
	int c, m, n;
	
		cin >> c;
		while(c--){
			int answer = 0;
			cin >> n >> m;
			UnionFind u = UnionFind(n+1);
			vector<pair<pair<int, int>, int>> v;
		
			int sum = 0;
			for (int i = 0; i < m; i++) {
				int u, k, w;
				cin >> u >> k >> w;
				v.push_back(make_pair(make_pair(u, k), w));
			}

			sort(v.begin(), v.end(), cmp);

			for (auto i : v) {
				if (!u.isSameSet(i.first.first, i.first.second)) {
					u.unionSet(i.first.first, i.first.second);
				}
				else {
					answer += i.second;
				}
			}

			cout << answer << endl;
	}

	return 0;
}
