#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int start, vector<bool> (&visited), vector<vector <int>> (&graph));
void dfs(int x, vector<bool> (&visited), vector<vector <int>> (&graph));

int main(void)
{
    int numvertex = 0;
    int numedge = 0;
    int start = 0;
    cin >> numvertex >> numedge >> start;

    int s = 0;
    int f = 0;
    
    vector<bool> visited(numvertex+1, false);
    vector<vector<int>> graph(numvertex+1);
    vector<vector<int>> edge(numedge);

    for(int i=0; i<numedge; i++)
    {
        cin >> s >> f;
        edge[i].push_back(s);
        edge[i].push_back(f);
    }



    for(int i=0; i<numedge; i++)
    {
        s = edge[i][0];
        f = edge[i][1];
        graph[s].push_back(f);
        graph[f].push_back(s);
    }

    for (int i = 0; i < numvertex+1;i++){
        sort(graph[i].begin(), graph[i].end()); // 낮은 숫자부터 탐색.
    }

    dfs(start, visited, graph);
    printf("\n");
    for(int i=0; i<numvertex+1; i++)
    {
        visited[i] = false;
    }
    

    for (auto& row : graph) {
        row.clear();  // 각 행(벡터)을 비웁니다.
    }

    for(int i=0; i<numedge; i++)
    {
        s = edge[i][0];
        f = edge[i][1];
        graph[s].push_back(f);
        graph[f].push_back(s);
    }

    for (int i = 0; i < numvertex+1;i++){
        sort(graph[i].begin(), graph[i].end()); // 낮은 숫자부터 탐색.
    }

    bfs(start, visited, graph);

    return 0;
}

void dfs(int x, vector<bool> (&visited), vector<vector <int>> (&graph))
{
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
	{
		int y = graph[x][i];
		if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            dfs(y, visited, graph); // 재귀적으로 방문
	}
}

// BFS 함수 정의
void bfs(int start, vector<bool> (&visited), vector<vector <int>> (&graph)) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    visited[start] = true; // 첫 노드를 방문 처리
    cout << start << " ";

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        //cout << x << ' ';
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                cout << y << " ";
            }
        }
    }
}


