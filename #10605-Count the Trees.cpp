//卡特蘭數:Cn = 2(2n-1)*Cn-1/(n+1) = n個node的二叉樹形狀個數
#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
 
int C[305][2005] = {0};
 
int main()
{
	C[1][0] = 1;
	for (int i = 2 ; i < 301 ; ++ i) {
		for (int j = 0 ; j < 2000 ; ++ j)
			C[i][j] += C[i-1][j]*(4*i-2);
		for (int j = 0 ; j < 2000 ; ++ j) {
			C[i][j+1] += C[i][j]/10;
			C[i][j] %= 10;
		}
		for (int j = 1999 ; j >= 0 ; -- j) {
			C[i][j-1] += C[i][j]%(i+1)*10;
			C[i][j] /= (i+1);
		}
		
		for (int j = 0 ; j < 2000 ; ++ j)
			C[i][j] *= i;
		for (int j = 0 ; j < 2000 ; ++ j) {
			C[i][j+1] += C[i][j]/10;
			C[i][j] %= 10;
		}
	}
		
	int n;
	while (cin >> n && n) {
		int end = 1999;
		while (!C[n][end]) -- end;
		while (end >= 0) printf("%d",C[n][end --]);
		printf("\n");
	}
	return 0;
}
