#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
int r, c, k;
bool comp(const P& a, const P& b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first and a.second < b.second) return true;
	else return false;
}
int main() {
	cin >> r >> c >> k;
	int n = 3, m = 3;
	vector<vector<int>> A(100, vector<int>(100, 0));
	vector<P> cntLst;
	vector<int> cnt(101);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int t = 0;
	while (t < 100) {
		if (A[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}
		if (n >= m) {
			//R ����
			int max_r = 0;
			for (int i = 0; i < n ; i++) {
				fill(cnt.begin(), cnt.end(), 0);
				for (int j = 0; j < m; j++) cnt[A[i][j]]++;
				
				for (int j = 1; j < cnt.size(); j++) {
					if (cnt[j] != 0) cntLst.push_back({ j, cnt[j] });
				}
				
				sort(cntLst.begin(), cntLst.end(), comp);
				int idx = 0;
				for (P cnt : cntLst) {
					A[i][idx++] = cnt.second;
					A[i][idx++] = cnt.first;
				}
				for (int j = idx; j < 100; j++) A[i][j] = 0;
				
				if (max_r < cntLst.size() * 2) max_r = cntLst.size() * 2;
				cntLst.clear();
			}
			m = max_r;
		}
		else {
			//C ����
			int max_c = 0;
			for (int j = 0; j < m; j++) {
				fill(cnt.begin(), cnt.end(), 0);
				for (int i = 0; i < n; i++) cnt[A[i][j]]++;

				for (int i = 1; i < cnt.size(); i++) {
					if (cnt[i] != 0) cntLst.push_back({ i, cnt[i] });
				}

				sort(cntLst.begin(), cntLst.end(), comp);
				int idx = 0;
				for (P cnt : cntLst) {
					A[idx++][j] = cnt.second;
					A[idx++][j] = cnt.first;
				}
				for (int i = idx; i < 100; i++) A[i][j] = 0;

				if (max_c < cntLst.size() * 2) max_c = cntLst.size() * 2;
				cntLst.clear();
			}
			n = max_c;
		}
		t++;

	}
	
	cout << -1;
	return 0;
}