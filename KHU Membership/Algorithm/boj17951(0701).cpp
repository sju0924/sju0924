#include <iostream>

using namespace std;

int main()
{
	int num, div;
	cin >> num >> div;
	int* page = new int[num];//배열 설정

	int min = 0, mid, max = 0;//이분 탐색을 위한 변수 설정

	for (int i = 0; i < num; i++) {
		cin >> page[i];
		max += page[i];
	}
	mid = (min + max) / 2;
	
	int tmp = 0, cur = 0;

	while (min <= max) {
		//모든 그룹이 mid 이상이 되는지 확인하는 이진탐색

		for (int i = 0; i < num; i++) {
			tmp += page[i];
			if (tmp >= mid) {
				cur++;
				tmp = 0;				
			}

			if (cur == div) break;			
		}
		tmp = 0;


		if (cur < div) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}

		mid = (min + max) / 2;
		cur = 0;

	}
	delete[] page;

	cout << mid;
}