#include <iostream>
#include <cmath>
#include<cstdio>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int white[1001], black[1001];
int arr[1001][16][16];
int idx;
int search(int w, int b, int cur)
{
	//cout << "w: " << w << ", b: " << b << " cur: " << cur << "\n";
	if (arr[cur][w][b]) return arr[cur][w][b];
	int res = 0;

	if (cur == idx || w==0&& b==0)
		return 0;

	if (w > 0)
		res = max(res, search(w - 1, b, cur + 1) + white[cur]);

	if (b > 0)
		res = max(res, search(w, b - 1, cur + 1) + black[cur]);

	res = max(res, search(w, b, cur + 1));
	arr[cur][w][b] = res;

	return res;
}
int main()
{

	int w, b;
	int input;
	while (scanf("%d %d", &w, &b) == 2)
	{
		white[idx] = w;
		black[idx] = b;
		idx++;
		//cout << idx << "\n";
	}
	cout << search(15, 15, 0) << endl;
	return 0;
}
