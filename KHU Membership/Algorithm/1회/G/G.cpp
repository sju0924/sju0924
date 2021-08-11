#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int d[1001];
int P[1001][1001];
bool searched[1001];
int n, m, s, t, T;
int cur;
vector<vector<int>>g;
void cleard() {
	for (int i = 0; i <= 1000;i++) {
		d[i] = -1;
		searched[i] = 0;
		for (int j = 0; j <= 1000;j++) {
			P[i][j] = 0;
		}
	}
}
void printd() {
	cout << "=====현재 거리=====\n";
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	cout << "\n";
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
		d[s] = 0;
		g = vector<vector<int>>(n + 1);
		//cout << "g size: " << g.size() << "\n";
		//cout << "g size: " << g[1].size() << "\n";
		for (int j = 0; j < m; j++) {
			cin >> start >> end >> width;
			
			g[start].push_back(end);
			g[end].push_back(start);
			P[start][end] = width;
			P[end][start] = width;
			if (start == s) {
				d[end] = width;
			}
			else if (end == s) {
				d[start] = width;
			}
		}
		int curNode = s, nextNode = 0;
		
		for (int src = 0; src < n; src++) {
			searched[curNode] = 1;
				
			for (int n = 0; n < g[curNode].size();n++) { //next node 구하기
				//cout << "curnode: " << curNode << ", n: " << n << ", near Node:";
				//cout<< g[curNode][n] << " , size: " << P[curNode][g[curNode][n]] << "\n";
		
				if (g[curNode][n] == s) continue;
				if (d[curNode] < P[curNode][g[curNode][n]]) {
					if (d[g[curNode][n]] < d[curNode]) {
						d[g[curNode][n]] = d[curNode];
					}
				}
				else if (d[curNode] >= P[curNode][g[curNode][n]]) {
					if(d[g[curNode][n]] < P[curNode][g[curNode][n]]) {
						d[g[curNode][n]] = P[curNode][g[curNode][n]];
					}
				}
					
				//printd();
			}//cout << "ddd\n";
			
			nextNode = 1;
			while (searched[nextNode]) {
				nextNode++;
			}

			for (int next = nextNode; next <= n; next++) {
				if (searched[next] || d[nextNode] > d[next]) continue;
				nextNode = next;
			}
			//cout << "curNode: " << curNode;
			curNode = nextNode;
			//cout<<", nextNode : " << nextNode << "\n";
				
		}

		cout << d[t] << "\n";
		g.clear();
		cleard();
		}
		
		
}



