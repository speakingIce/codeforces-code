#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_N (int)(2*1e5)
char str[MAX_N];
 
 
inline char nxtChar(char curr) {
	if (curr == 'R') return 'G';
	if (curr == 'G') return 'B';
	if (curr == 'B') return 'R';
	return '\0'; // not gonna happen
}
 
#pragma warning(disable : 4996)
int main()
{
	char charArr[3] = { 'R', 'G', 'B' };
	int changeNeed[MAX_N];
	int q; cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		scanf("%s", str);
		int finalCharChange = MAX_N;
		for (int charInd = 0; charInd < 3; charInd++) {
			char startChar = charArr[charInd];
			for (int i = 0; i < n; i++) {
				if (startChar != str[i]) {
					changeNeed[i] = 1;
				}
				else {
					changeNeed[i] = 0;
				}
				startChar = nxtChar(startChar);
			}
			int minCharChange = 0;
			for (int i = 0; i < k; i++) {
				minCharChange += changeNeed[i];
			}
			finalCharChange = min(finalCharChange, minCharChange);
			for (int i = 0; i + k - 1 < n; i++) {
				int lb = i, rb = i + k - 1;
				lb++, rb++;
				if (rb < n) {
					minCharChange += changeNeed[rb];
					minCharChange -= changeNeed[lb - 1];
				}
				finalCharChange = min(finalCharChange, minCharChange);
			}
		}
		cout << finalCharChange << endl;
		
	}
    return 0;
 
}
