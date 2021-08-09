#include <iostream>
#include<vector>
using namespace std;

vector<int> A;
vector<int> B;
int C, D, d;
int cost[101][101][2][2];
int Min(int a, int b) {
	if (a <= b)return a;
	else return b;
}
void cost_clear() {
	for (int i = 0; i <= A.size();i++) {
		for (int j = 0; j <= B.size();j++) {
			//cout << "clear" << i << ", " << j << "\n";
			cost[i][j][0][0] = 0;
			cost[i][j][1][0] = 0;
			cost[i][j][1][1] = 0;
			cost[i][j][0][1] = 0;
		}
	}
	//cout << "clear\n";
}

int getCost(int a, int b, int ha, int hb) {
	if (a == A.size() && b == B.size()) return 0;
	if (cost[a][b][ha][hb]) {
		//cout << cost[a][b][ha][hb] << "를 리턴\n";
		return cost[a][b][ha][hb];
	}
	int res = 999999999;
	
	//두 팀 모두 경기를 치를경우
	if (a < A.size() && b < B.size()) {
		if (A[a] == B[b]) res = Min(res, getCost(a + 1, b + 1, 0, 0) + C);
		else res = Min(res, getCost(a + 1, b + 1, 0, 0) + 2 * C);
	}
	//cout << "1차 res " << res << "\n";
	
	//A팀만 경기를 치룰경우
	if (a < A.size()) {
		//cout << "cost: " <<  C + d << "\n";
		if(hb) res = Min(res, getCost(a + 1, b, 0, 1) + C+d);
		else res = Min(res, getCost(a + 1, b, 0, 1) + C+D+d);
	}
	//cout << "2차 res " << res << "\n";
	 //B팀만 경기를 치룰경우
	if (b < B.size()) {
		if (ha) res = Min(res, getCost(a, b + 1, 1, 0) + C + d);
		else res = Min(res, getCost(a, b + 1, 1, 0) + C + D + d);
	}
	//cout << res << " 를 "<<a<<" "<<b<<" "<<ha<<" "<<hb<<" 로 설정" << "\n";
	cost[a][b][ha][hb] = res;
	return res;
}

int main()
{
	int T;
	int input;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> C >> D >> d;
		input = 1;
		while (true) { //A 입력
			cin >> input;
			if (input == 0) break;
			
			else {
				A.push_back(input);
			}
		}
		while (true) {//B 입력
			cin >> input;
			if (input == 0) break;
			else {
				B.push_back(input);
			}
		}
		cout << getCost(0, 0, 0, 0)<<"\n";
		
		//cout << "cost: " << cost[0][0][0][0] << "\n";
		cost_clear();
		//cout << "cost: " << cost[0][0][0][0] << "\n";
		A.clear();
		B.clear();
		

	}
}

