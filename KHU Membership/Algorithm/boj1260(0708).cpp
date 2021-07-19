#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int node, edge, start;//정점, 간선, 시작점
int dept, arv; // 간선 연결
int cursor;//커서. 노드현재위치


stack <int>  s1;
queue <int> q1;


int main()
{
	cin >> node; cin >> edge; cin >> start;
	vector <vector <int> > graph(node+1, vector<int>(0));
	bool *is_visited = new bool[node+1];

	for (int i = 0; i < node + 1;i++) {
		is_visited[i] = false;
	}
	
	for (int i = 1 ; i <= edge;i++) {
		cin >> dept; cin >> arv;
		graph[dept].push_back(arv);
		graph[arv].push_back(dept);
	}

	s1.push(start);



	while (!s1.empty()) {
		cursor = s1.top();
		s1.pop();

		if (is_visited[cursor]) continue;
		sort(graph[cursor].begin(),graph[cursor].end());

		for (int i = graph[cursor].size() - 1; i >= 0; i--) {
			s1.push(graph[cursor][i]);
		}
		is_visited[cursor] = true;
		cout << cursor << " ";
	}
	
	cout << endl;

	for (int i = 0; i < node + 1;i++) {
		is_visited[i] = false;
	}

	q1.push(start);

	while (!q1.empty()) {
		cursor = q1.front();
		q1.pop();

		if (is_visited[cursor]) continue;

		sort(graph[cursor].begin(), graph[cursor].end());

		for (int i = 0 ; i < graph[cursor].size(); i++) {
			q1.push(graph[cursor][i]);
		}
		is_visited[cursor] = true;
		cout << cursor << " ";
	}

	cout << endl;

	delete[] is_visited;
}