//BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("out.txt", "w", stdout);
	int N;
	while (cin >> N && N) {
		int E;	cin >> E;

		std::vector<vector<int>> edge(N);
		for (int i = 0; i < E; ++i)
		{
			int v1, v2;	cin >> v1 >> v2;
			edge[v1].push_back(v2); edge[v2].push_back(v1);
		}

		std::queue<int> Q;
		short *color = new short[N](); //value 1 is a color, -1 is an another
		bool able = 1;
		color[0] = 1;
		Q.push(0);

		while (!Q.empty() && able) {
			int cur = Q.front(); Q.pop();
			for (int i = 0; i < (int)edge[cur].size(); ++i)
			{
				if ( !color[edge[cur][i]] ) {
					color[edge[cur][i]] = ~color[cur];
					Q.push(edge[cur][i]);
				} else if ( color[cur] == color[edge[cur][i]] ) {
					cout << "NOT BICOLORABLE." << endl;
					able = 0;
					break;
				}
			}
		}
		
		if (able) cout << "BICOLORABLE." << endl;
	}
	return 0;
}