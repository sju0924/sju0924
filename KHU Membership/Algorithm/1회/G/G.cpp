#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int, int>>> g;
int n, m, s, t, T;
int cur;
bool compair(pair<int, int>a, pair<int, int> b) {
	if (a.second > b.second) return true;
	else return false;
}
int Min(int a, int b) {
	if (a <= b) return a;
	else return b;
}
int Max(int a, int b) {
	if (a >= b)return a;
	else return b;
}
int searchPath(int node,vector<int> pth,int smallest_width) {
	if (node == t) {
		cur = smallest_width;
		return smallest_width;
	}
	//cout << "node: " << node <<"width: "<<smallest_width<< "cur "<<cur<<"\n";

	int temp=-1;
	int wid = smallest_width;
	for (auto item : g[node]) {
		if (find(pth.begin(), pth.end(), item.first) != pth.end()) {
			continue;
		}
		if (cur > item.second) {
			continue;
		}
		wid = Min(smallest_width,item.second);
		pth.push_back(item.first);
		temp = Max(temp,searchPath(item.first,pth,wid));	
		pth.pop_back();
	}

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	int start, end, width;
	vector<int>blank;
	
	for (int i = 0; i < T; i++) {
		cin >> n >> m >> s >> t;
		g = vector<vector<pair<int,int>>>(n + 1);
		for (int j = 0; j < m; j++) {
			cin >> start >> end >> width;
			g[start].push_back(make_pair(end,width));
			g[end].push_back(make_pair(start, width));
		}
		
		cur = 0;
		cout<<searchPath(s, blank, 2100000000)<<"\n";

		g.clear();
		blank.clear();
	}


}
