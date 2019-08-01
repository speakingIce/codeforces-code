#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
 
	int* rainAmount = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> rainAmount[i];
	}
 
	for (int i = 0; i < n; i++) {
		bool found = true;
		for (int j = max(0, i - x); j <= min(n - 1, i + y); j++) {
			if (i == j) continue;
			if (rainAmount[i] >= rainAmount[j]) found = false;
		}
		if (found) {
			cout << i + 1 << endl;
			break;
		}
	}
 
    return 0;
 
}
