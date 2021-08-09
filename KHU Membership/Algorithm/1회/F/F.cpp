#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>nums;
int Abs(int n) {
	if (n > 0) return n;
	else return -n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, K, input, distance, res,sum;
	int front, rear;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> K;

		//값 초기화
		front = 0;
		rear = n-1;
		distance = 200000001;
		res = 0;

		for (int j = 0; j < n; j++) {
			cin >> input;
			nums.push_back(input);
		}
		sort(nums.begin(), nums.end());

		while (front < rear) {
			sum = nums[front] + nums[rear];
			if (Abs(sum - K) < distance) {
				res = 1;
				distance = Abs(sum - K);
			}
			else if (Abs(sum - K) == distance) {
				//cout << nums[front] << " + " << nums[rear] << " 이 " << Abs(sum - K) << " 차이 \n";
				res++;
			}

			if (sum < K) {
				front++;
			}
			else if (sum > K) {
				rear--;
			}
			else {
				rear--;
				front++;
			}
		}

		//cout << "distance: " << distance << "\n";
		cout << res << "\n";

		nums.clear();
	}
	
}
