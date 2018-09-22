#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	int T;	cin >> T;
	while (T--) {
		int M;	cin >> M;
		short *sum = new short[M];

		int d1, d2;	scanf("%d %d", &d1, &d2);
		sum[0] = d1+d2;
		for (int i = 1; i < M; ++i)
		{
			scanf("%d %d", &d1, &d2);
			sum[i] = d1+d2;
			if ( sum[i] >= 10 ) {
				sum[i] -= 10;
				int j;
				for (j = i - 1; sum[j] == 9 && j >= 1; --j)
					sum[j] = 0;
				sum[j]++;
			}
		}

		for (int i = 0; i < M; ++i)
			printf("%d", sum[i]);
		if (T) printf("\n\n");
		else printf("\n");
	}
	return 0;
}