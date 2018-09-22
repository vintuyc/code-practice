//greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
	int l, r;
	bool operator < (const Pair b) const {
		if (l == b.l) return r > b.r;
		return l < b.l;
	}
};

int main(int argc, char const *argv[])
{
	//freopen("out.txt", "w", stdout);
	int T;	cin >> T;
	while (T--) {
		int M;	cin >> M;

		std::vector<struct Pair> p;
		struct Pair in;	cin >> in.l >> in.r;
		while ( in.l != 0 || in.r != 0) {
			p.push_back(in);
			cin >> in.l >> in.r;
		}

		sort(p.begin(), p.end());

		int r ; r = 0; 
		std::vector<Pair> mini_cover;
		for (int i = 0; i < (int)p.size(); ++i)
		{
			if (mini_cover.empty()) {
				if (p[i].r >= 0 && p[i].l <=0 ) mini_cover.push_back(p[i]);
			} else if (p[i].r > mini_cover.back().r && p[i].l > r && p[i].l <= mini_cover.back().r) {
				r = mini_cover.back().r;
				mini_cover.push_back(p[i]);
			} else if (p[i].r > mini_cover.back().r && p[i].l <= r) {
				mini_cover[mini_cover.size()-1] = p[i];
			}
			if (p[i].r >= M) break;
		}

		if (mini_cover.empty() || mini_cover.back().r < M) cout << 0 << endl;
		else {
			cout << mini_cover.size() << endl;
			for (int i = 0; i < (int)mini_cover.size(); ++i)
				cout << mini_cover[i].l  << " " << mini_cover[i].r << endl; 
		}
		if (T) cout << endl;
	}
	return 0;
}