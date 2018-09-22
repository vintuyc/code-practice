#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	int *table = new int[11];
	table[0] = 1; table[1] = 1; table[2] = 2; table[3] = 5; table[4] =14;

	for (int i = 5; i < 11; ++i)
	{
		int sum = 0;
		for (int j = 0; j < i; ++j)
		{
			sum += table[j]*table[i-1-j];
		}
		table[i] = sum;
	}

	int pair;
	if(cin >> pair) cout << table[pair] << endl;

	while (cin>>pair) {
			cout <<endl << table[pair] << endl;
	}
	return 0;
}