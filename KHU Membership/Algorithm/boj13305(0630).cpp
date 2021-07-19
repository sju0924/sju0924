#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	long long int* price = new long long int[N];
	long long int* distance = new long long int[N - 1];

	for (int i = 0; i < N - 1; i++) {
			cin >> distance[i];
		}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	

	long long int CurPrice;
	long long int res = 0;

	CurPrice = price[0];
	for (int i = 0; i < N-1; i++) {
		 if(price[i]<CurPrice) {
			CurPrice = price[i];			
		}
		 res += CurPrice * distance[i];
	}
	cout << res;
}