//http://www.csie.ntnu.edu.tw/~u91029/Prime.html
//linear sieve algorithm
#include <iostream>
#include <vector>
using namespace std;

long long int compute(long long int a, long long int power, long long int N)
{
	if (power==1) return a;
	long long int c = compute(a, power/2, N);
	if (power%2 == 0) 
		return (c*c)%N;
	else
		return (c*((c*a)%N))%N;
}

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	//prime number table
	bool *sieve = new bool[65001];
	for (int i = 0; i < 65001; ++i)
		sieve[i] = 0;

	//linear sieve algorithm : O(n)
	std::vector<int> prime;
	for (int i = 2; i < 65001; ++i)
	{
		if (!sieve[i]) prime.push_back(i);
		for (int j = 0; i*prime[j]<65001 && j <(int)prime.size(); ++j)
		{	
			sieve[i*prime[j]] = 1;
			if(i%prime[j]==0)break; /*notice!!*/
		}
	}

	//carmichael number table

	long long int N;
	while ( cin >> N )
	{
		if (!N) break;
		if (!sieve[N]) { cout << N << " is normal." <<endl; continue; }

		bool cal_num = 1;
		for(long long int a = 2; a < N && cal_num; a++)
			if (a != compute(a, N, N))
				cal_num = 0;
		
		if (cal_num) cout << "The number " << N << " is a Carmichael number." << endl;
		else cout << N << " is normal." << endl;
	}

	return 0;
}