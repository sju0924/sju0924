// H.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
using namespace std;
int fibo[45]; //최대값 44
vector<int>res;

int findFibo() {
	return 0;
}

int main()
{
	
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	int i = 3;
	while (i<45) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		//cout << i << " " << fibo[i] << "\n";
		i++;
	}
	int T;
	int N,temp;
	cin >> T;
	for (int Case = 0; Case < T; Case++) {
		cin >> N;
		temp = N;
		i = 44;
		while (temp > 0) {

			while (temp < fibo[i]) {
				i--;
			}
			temp = temp - fibo[i];
			res.push_back(fibo[i]);
			i -= 2;


		}
		for (int i = res.size() - 1; i >= 0;i--) {
			cout << res[i] << " ";
		}
		cout << "\n";
		res.clear();
	}
	
	
}
