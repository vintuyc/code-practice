#include <iostream>
#include <vector>
using namespace std;

int m;
std::vector<int> A, B, C;

void transferAtoB(int disks);
void transferAtoC(int disks);
void transferBtoA(int disks);
void transferBtoC(int disks);
void transferCtoA(int disks);
void transferCtoB(int disks);

void list()
{
	cout << endl;
	cout << "A=>";
	if (!A.empty()) {
		cout << "  ";
		for (int i = 0; i < (int)A.size(); ++i)
			cout << " " << A[i];
	}
	cout << endl;
	cout << "B=>";
	if (!B.empty()) {
		cout << "  ";
		for (int i = 0; i < (int)B.size(); ++i)
			cout << " " << B[i];
	}
	cout << endl;
	cout << "C=>";
	if (!C.empty()) {
		cout << "  ";
		for (int i = 0; i < (int)C.size(); ++i)
			cout << " " << C[i];
	}
	cout << endl;
}


void transferAtoB(int disks)	//move 1~disks from C to B
{
	if (!disks || m<=0) return;
	transferAtoC(disks-1);
	if (m>0) {
		B.push_back(disks);
		A.pop_back();
		m--;
		list();
	}
	transferCtoB(disks-1);
}


void transferAtoC(int disks)	//move 1~disks from A to C
{
	if (!disks || m<=0) return;
	transferAtoB(disks-1);
	if (m>0){
		C.push_back(disks);
		A.pop_back();
		m--;
		list();
	}
	transferBtoC(disks-1);
}

void transferBtoC(int disks)	//move 1~disks from A to C
{
	if (!disks || m<=0) return;
	transferBtoA(disks-1);
	if(m>0){
		C.push_back(disks);
		B.pop_back();
		m--;
		list();
	}
	transferAtoC(disks-1);
}

void transferCtoB(int disks)	//move 1~disks from A to C
{
	if (!disks || m<=0) return;
	transferCtoA(disks-1);
	if (m>0) {
		B.push_back(disks);
		C.pop_back();
		m--;
		list();
	}
	transferAtoB(disks-1);
}

void transferBtoA(int disks)	//move 1~disks from A to C
{
	if (!disks || m<=0) return;
	transferBtoC(disks-1);
	if (m>0) {
		A.push_back(disks);
		B.pop_back();
		m--;
		list();
	}
	transferCtoA(disks-1);
}

void transferCtoA(int disks)	//move 1~disks from A to C
{
	if (!disks || m<=0) return;
	transferCtoB(disks-1);
	if (m>0) {
		A.push_back(disks);
		C.pop_back();
		m--;
		list();
	}
	transferBtoA(disks-1);
}


int main(int argc, char const *argv[])
{
	//freopen("out.txt","w",stdout);
	int disks, T = 1;
	while (cin >> disks) {
		cin >> m;
		if (!disks) break;
		
		for (int i = 0; i < disks; ++i)
			A.push_back(disks-i);
		cout << "Problem #" << T << endl;
		
		list();
		transferAtoC(disks);

		T++;
		A.clear(); B.clear(); C.clear();
		cout << endl;
	}
	return 0;
}