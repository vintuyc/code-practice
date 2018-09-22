//uva997
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

long long int *compute(long long int *S, long long int m, char op, int N)
{
	long long int *V = new long long int[N];
	if (op == '+'){
		V[0] = m;
		for (int i = 1; i < N; ++i)
			V[i] = V[i-1] + S[i-1];
	} else if (op == '*') {
		V[0] = m * S[0];
		for (int i = 1; i < N; ++i)
			V[i] = V[i-1] * S[i];
	}

	delete [] S;
	return V;
}

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	char input[1024];
	while (cin.getline(input, 1024)) {
		std::vector<char*> codification;
		char *pch = strtok(input, " []");
		while (pch!=NULL) {
			codification.push_back(pch);
			pch = strtok(NULL, " []");
		}

		int N = atoi(codification[codification.size()-1]);

		long long int *S = new long long int[N];
		for (int i = 0; i < N; ++i)
			S[i] = atoi(codification[codification.size()-2]);

		for (int i = codification.size()-3; i > -1 ; --i)
		{
			long long int num; char sym; char *p;
			for (p = codification[i]; (*p)!='\0'; p += sizeof(char));
			sym = *(p-sizeof(char)); 
			*(p-sizeof(char)) = '\0';
			num = atoi(codification[i]);
			//cout << num << "/" << sym << endl;
			//for (int i = 0; i < N; ++i) cout << S[i] << " ";
			//cout << endl;

			S = compute(S, num, sym, N);
		}

		for (int i = 0; i < N-1; ++i) cout << S[i] << " ";
		cout << S[N-1];
		cout << endl;
	}
	return 0;
}