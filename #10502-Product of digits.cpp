#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long int in; cin >> in;
		if (in==0){ cout << 0 << endl; continue; }

		std::vector<int> out;
		int div = 9;
		while (div > 1) {
			if (in == 1) break;
			if ( in%div == 0 ) {
				in /= div;
				out.push_back(div);
			} else { div--; }
		}

		if (in!=1) { cout << -1 << endl; }
		else if (in==1 && (int)out.size()==0){ cout << 1 << endl; }
		else {
			for (int j = (int)out.size()-1; j > -1; --j)
			{
				cout << out[j];
			}
			cout << endl;
		} 
	}
	return 0;
}