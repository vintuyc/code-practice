/*
兩相鄰事件a(Ta,Fa),b(Tb,Bb)無論排成ab或是ba，其他部分的罰金是固定的所以差異在於ab(Ta*Fb)還是ba(Tb*Fa)的損失較小

假如是ab較小，則
(Ta*Fb)<(Tb*Fa) 
=> (Fa/Ta)>(Fb/Tb) 
a的(罰金/時間)比較大

因此本題解法是將每個工作(Fi/Ti)由大到小排序
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct J
{
	double ratio;
	int index;

	bool operator < (const J a) const {
		return ratio > a.ratio;
	}
};

int main(int argc, char const *argv[])
{	
	//freopen("out.txt","w",stdout);
	int C;
	cin >> C;

	while(C--) {
		int job;
		cin >> job;

		struct J *S = new struct J[job];
		double T, F;
		for (int i = 0; i < job; ++i)
		{
			cin >> T >> F;
			S[i].ratio = F/T;
			S[i].index = i+1;
		}

		sort(S, S+job);
		for (int i = 0; i < job-1; ++i) cout << S[i].index << " ";
		cout  << S[job-1] .index << endl;
		if (C) cout << endl;
	}
	return 0;
}