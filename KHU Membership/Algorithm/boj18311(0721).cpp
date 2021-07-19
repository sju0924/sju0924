#include <iostream>

using namespace std;

long long int N[100003] = { 0,0, }; // n번 코스의 시작점을 N[n]에 저장
int main() {	

	int n;//인덱스 다룸
	long long int k, len=0; //길이 다룸
	int res=0;//인덱스 다룸
	cin >> n >> k;
	for (int i = 2; i <= n+1; i++) {
		cin >> N[i];
		len += N[i];
		if (k < len) {
			res = i-1;
			break;
		}
			
	
		
	}

	if (!res) {
		for (int i = n+1; i >0; i--) {
			len += N[i];
			if (k < len) {
				res = i-1;
				break;
			}

		}
	}
	

	cout << res;
}