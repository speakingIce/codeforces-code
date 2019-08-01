 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
 
typedef long long LL;
 
using namespace std;
 
int main()
{
	int n, I; 
	cin >> n >> I;
	int* soundFile = new int[n];
 
	for (int i = 0; i < n; i++) {
		cin >> soundFile[i];
	}
 
	sort(soundFile, soundFile + n);
 
	int distinct = 0;
	int prev = -1;
	int res = n + 1;
	int leftInd = 0;
	int leftPrev = soundFile[0];
 
	for (int i = 0; i < n; i++) {
		if (prev != soundFile[i]) {
			prev = soundFile[i];
			distinct++;
		}
		int k = ceil(log2(distinct));
		if (n * k > I * 8) {
			while (leftInd < n - 1 && soundFile[++leftInd] == leftPrev);
			leftPrev = soundFile[leftInd];
			distinct--;
		}
		res = min(res, n - (i - leftInd + 1));
	}
	cout << res << endl;
    return 0;
 
}
