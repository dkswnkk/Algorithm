#include <iostream>
using namespace std;

int R, C, ZR, ZC;
char c[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> ZR >> ZC;
	for (int i = 0; i < R; i++) {
		cin >> c[i];
	}								
	for (int i = 0; i < C; i++) {	 
		for (int j = 0; j < ZC; j++) {
				cout << c[i][j];			
		}
		cout << "\n";
	}

}