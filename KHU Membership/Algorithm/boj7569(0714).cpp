// 토마토.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<queue>

using namespace std;

struct loc {
	int floor;
	int row;
	int col;
	loc(){}
	loc(int f, int r, int c) {
		floor = f;
		row = r;
		col = c;
	}
};
int box[101][101][101]; //층, 행, 열
queue<loc>rotten;

void print(int H, int M, int N) {
	for (int i = 0; i < H;i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout<< box[i][j][k]<<" ";

			}
			cout << "\n";
		}
	}
}

int main()
{
	int M, N, H;
	loc input;
	cin >> M >> N >> H;

	for (int i = 0; i < H;i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {					
					input.floor = i;
					input.row = j;
					input.col = k;
					rotten.push(input);
				}
			}
		}
	}

	int day = 0, count = 0,x,y,z,is_rot=false;
	loc cur;
	
	while (!rotten.empty()) {
		count = rotten.size();
		//cout<<count<<"\n";
		for (int i = 0; i < count; i++) {
			cur = rotten.front();
			rotten.pop();

			for (int next = -1;next <= 1;next+=2) {
				if (cur.floor+next < H && cur.floor + next >= 0&& box[cur.floor + next][cur.row][cur.col] == 0) {
					box[cur.floor + next][cur.row][cur.col] = 1;
					rotten.push(loc(cur.floor + next, cur.row, cur.col));
					is_rot = 1;
				}
				if (cur.row+next <N  && cur.row + next >= 0&&box[cur.floor][cur.row + next][cur.col] == 0) {
					box[cur.floor][cur.row+next][cur.col] = 1;
					rotten.push(loc(cur.floor , cur.row+next, cur.col));
					is_rot = 1;
				}
				if (cur.col+next < M && cur.col + next >= 0 && box[cur.floor][cur.row][cur.col + next] == 0) {
					box[cur.floor][cur.row][cur.col+next] = 1;
					rotten.push(loc(cur.floor , cur.row, cur.col+next));
					is_rot = 1;
				}
			}
		}

		//print(H, M, N);

		if (!is_rot) break;
		day += is_rot;
		is_rot = 0;

	}


	for (int i = 0; i < H;i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day;

    
}

