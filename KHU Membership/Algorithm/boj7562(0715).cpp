// 나이트의 이동.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<queue>
int visit[300][300];

void clear(int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			visit[i][j] = 0;
		}
	}
}

using namespace std;

int main()
{
	int N, l;
	int start[2];
	int end[2];
	int res = 0;
	int next[8][2] = { {2,1},{1,2},{-1,2},{1,-2},{-2,1},{2,-1},{-2,-1},{-1,-2} };
	
	int it;
	int nextX, nextY;
	bool found = false;
	pair<int, int>cur;
	queue<pair<int, int>> q;
	cin >> N;
	for (int i = 0; i < N;i++) {
		
		cin >> l;
		cin >> start[0] >> start[1];
		cin >> end[0] >> end[1];

		clear(l);
		q.push(make_pair(start[0], start[1]));

		while (!found) {
			it = q.size();
			if (!it) break;
			for (int j = 0; j < it;j++) {
				cur = q.front();
				q.pop();
				//cout << cur.first << " " << cur.second << "\n";

				if (cur.first == end[0] && cur.second == end[1]) {
					found = 1;
					break;
				}

				
				for (int k = 0; k < 8; k++) {
					if (cur.first + next[k][0] >= 0 && cur.first + next[k][0] < l
						&& cur.second + next[k][1] >= 0 && cur.second + next[k][1] < l&&
						!visit[cur.first + next[k][0]][cur.second + next[k][1]]) {
						q.push(make_pair(cur.first + next[k][0], cur.second + next[k][1]));
						visit[cur.first + next[k][0]][cur.second + next[k][1]] = 1;
						//cout << "push\n";
					}
				}
				

			}
			res++;
			
		}
		res--;
		cout << res << "\n";
		while (!q.empty()) q.pop();

		res = 0;
		found = 0;


	}
}