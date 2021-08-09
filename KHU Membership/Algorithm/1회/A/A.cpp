#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> t(1001);
int score[201];
int last_runner[201];
int complete_runner[201];
int reserve[201];
int main()
{
	int N,T,maxTeam,scoreCount;
	int winner;
	cin >> T;
	for (int Case = 0; Case < T; Case++) {
		cin >> N;
		maxTeam = 0;
		scoreCount = 1;
		for (int i = 0; i < N; i++) { //팀 번호 입력
			cin >> t[i];
			if (maxTeam < t[i]) maxTeam = t[i];
		}

		//실격인지 아닌지 알아봄
		for (int i = 1; i <= maxTeam; i++) {
			if (count(t.begin(), t.begin()+N, i) == 6) {
				reserve[i] = 1;
			}
			else{reserve[i] = 0;}
		}
		for (int i = 0; i < N; i++) { //점수 계산
			if (!reserve[t[i]])continue;
			if (complete_runner[t[i]]<4) {
				score[t[i]] += scoreCount;	
			}
			else if (complete_runner[t[i]] == 4) {
				last_runner[t[i]] = scoreCount;
				
			}
			complete_runner[t[i]]++;
			scoreCount++;

			
		}

		winner = 1;
		for (int i = 1; i <= maxTeam; i++) {
			if (reserve[i]) winner = i;
		}

		
		for (int i = 1; i <= maxTeam;i++) { //우승팀 산정
			//cout << "score[" << i << "] : " << score[i] <<", last runner: "<<last_runner[i]<< "\n";
		
			if (score[winner] > score[i] && score[i] ) {
				winner = i;
			}
			else if (score[winner] == score[i]) {
				if (last_runner[winner] > last_runner[i]) {
					winner = i;
				}
			}

			//reserve 청소
			
		}

		cout << winner << "\n";

		//score 청소
		for (int i = 1; i <= maxTeam;i++) {
			score[i] = 0;
			complete_runner[i] = 0;
			reserve[i] = 0;
			last_runner[i] = 0;
		}
		

	}
	
}
