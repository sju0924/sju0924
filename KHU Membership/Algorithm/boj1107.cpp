#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<char>ban(10);

char getCloseNum(char _to) {
	char res = _to, front = _to-1, rear = _to+1;
	while (ban[res - 48]) {
		//cout << front << " " << rear << "\n";
		if (front>='0' && !ban[front - 48]) {
			res = front;

		}
		else if (rear <='9' && !ban[rear - 48]) {
			res = rear;
		}
		if(front >= '0') front = char(front - 1);
		if (rear <= '9') rear = char(rear + 1);
	}

	//cout << "destination: " << _to << ", numberinput: " << res << "\n";
	return res;

}


string getCloseChannel(string cur) {

}
int digit(int r) {
	int cnt = 1;
	for (int i = 0; i < r; i++) {
		cnt = cnt * 10;
	}
	return cnt;
}
int strToint(string N_copy) {
	int cnt = 0;
	int N_int = 0;
	for (int i = N_copy.size() - 1; i >= 0; i--) {
		N_int += (N_copy[i] - 48) * digit(cnt);
		cnt++;
	}
	return N_int;
}

int abs(int n) {
	if (n > 0) return n;
	else return -n;
}


int main() {	

	string N;
	int input;
	int M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> input;
		ban[input] = 1;
		
	}

	//그냥 위아래로 구할 수 있는 경우(100 근처)
	int N_int = strToint(N);
	int tempres = abs(N_int - 100);

	string des;
	
	int inputNum, res = 0, prev=N.at(0);
	for (int i = 0; i < N.length();i++) {
		inputNum = getCloseNum(N.at(i));
		des += char(inputNum);
	}

	//cout << des<<"\n";

	res = abs(strToint(N) - strToint(des)) + des.size();

	if (tempres < res) res = tempres;
	cout << res;

}