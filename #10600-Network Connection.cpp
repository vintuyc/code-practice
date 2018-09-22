//uva793
#include <iostream>
using namespace std;

int find(int *C, int x)
{
	return x == C[x] ? x : find(C, C[x]);
}

void Union(int *C, int com1, int com2)
{
	int p1 = find(C, com1), p2 = find(C, com2);
	C[p2] = p1;
}

bool is_connect(int *C , int com1, int com2)
{
	return (find(C, com1) == find (C, com2));
}

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	int T;	cin >> T;
	int N;
	while (cin >> N) {
		T--;
		int *com = new int[N+1];
		for (int i = 0; i < N+1; ++i) com[i] = i;

		char in; int success = 0; int unsucess = 0;
		while (cin >> in) {
			if ( in!='c' && in!='q' ) { cin.putback(in); break; }

			int com1, com2; cin >> com1 >> com2;
			if (in == 'c') Union(com, com1, com2);
			else if (in == 'q') {if ( is_connect(com, com1, com2) ) success++; else unsucess++;}
		}

		cout << success <<","<< unsucess << endl;
		if (!T) break; else cout << endl;
	}
	return 0;
}