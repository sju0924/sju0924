#include <iostream>
using namespace std;

int n[2002];
int res[2002][2002];

int getP(int S, int E) {


	int ret;
	if (res[S][E] != -1) return res[S][E];
	else {
		ret = getP(S + 1, E - 1) && (n[S] == n[E]);
		res[S][E] = ret;
		return ret;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M,S, E;
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		for (int j = 0; j <= i;j++) {
			res[i][j] = 1;
		}
		for (int j = i + 1;j <= N;j++) {
			res[i][j] = -1;
		}
	}

	cin >> M;
	for (int i = 0; i < M;i++) {
		cin >> S >> E;
		cout << getP(S,E)<<"\n";
	}
}