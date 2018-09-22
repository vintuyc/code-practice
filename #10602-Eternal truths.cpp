//https://belbesy.wordpress.com/2011/06/08/uva-%E2%80%93-928-eternal-truths/
//hint: BFS and the point should not be walked twice with the same move; 
#include <iostream>
#include <queue>
using namespace std;

struct maze_point
{
	char sym;
	bool m[3];
};

struct Point
{
	int row, col;
	int m;
	int step;
};

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	int case_num; cin >> case_num;
	for (int t = 0; t < case_num; ++t)
	{
		int rows, cols;	cin >> rows >> cols;

		struct maze_point **maze = new struct maze_point*[rows];
		for (int i = 0; i < rows; ++i)
			maze[i] = new struct maze_point[cols];

		struct Point S; 
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j)
			{
				cin >> maze[i][j].sym;
				if (maze[i][j].sym == 'S') {
					S.row = i; S.col = j;
					S.m = 1;
					S.step = 0;
				}

				if (maze[i][j].sym=='#') {
					maze[i][j].m[0] = 0;
					maze[i][j].m[1] = 0;
					maze[i][j].m[2] = 0;
				} else {
					maze[i][j].m[0] = 1;
					maze[i][j].m[1] = 1;
					maze[i][j].m[2] = 1;
				}
			}
		}

		int dirx[4]={-1, 0, 0, 1};
		int diry[4]={0, -1, 1, 0};
		bool found = 0;
		std::queue <struct Point> Q;
		Q.push(S);

		while (!Q.empty()) {
			struct Point cur = Q.front(); Q.pop();
			if(maze[cur.row][cur.col].sym == 'E') {
				cout << cur.step << endl;
				found = 1;
				break;
			}

			struct Point next;
			for (int dir = 0; dir < 4; ++dir)
			{
				next.row = cur.row + dirx[dir]*cur.m;
				next.col = cur.col + diry[dir]*cur.m;
				next.m = cur.m%3 + 1;
				next.step = cur.step + 1;
				if ((-1 < next.row && next.row < rows)&&(-1 < next.col && next.col < cols)&&maze[next.row][next.col].m[next.m-1]) {
					bool block = 0;
					for (int i = 1; i < cur.m; ++i)
						if (maze[cur.row+dirx[dir]*i][cur.col+diry[dir]*i].sym == '#') block = 1;

					if (!block) {
						Q.push(next);
						maze[next.row][next.col].m[next.m-1] = 0;
					} 
				}
			}
		}
		if (!found) cout << "NO" << endl;
	}	
	return 0;
}