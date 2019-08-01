
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

#define MAX_N 50
char grid[MAX_N][MAX_N];
int ans[MAX_N][MAX_N][MAX_N][MAX_N];

// bool verticesVisit[3 * MAX_N];

using namespace std;

int dfs(int lx, int ly, int rx, int ry) {
	if (ans[lx][ly][rx][ry] != -1) return ans[lx][ly][rx][ry];

	if (rx == lx && ry == ly) {		// unit
		return ans[lx][ly][rx][ry] = (grid[lx][ly] == '#');
	}

	int res = max(rx - lx + 1, ry - ly + 1);
	for (int i = lx + 1; i <= rx; i++) {
		res = min(res, dfs(lx, ly, i - 1, ry) + dfs(i, ly, rx, ry));
	}
	for (int j = ly + 1; j <= ry; j++) {
		res = min(res, dfs(lx, ly, rx, j - 1) + dfs(lx, j, rx, ry));
	}
	return ans[lx][ly][rx][ry] = res;
}


#pragma warning(disable : 4996)
int main()
{
	int n; cin >> n;
	memset(ans, -1, sizeof ans);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", grid[i]);
	}

	cout << dfs(0, 0, n - 1, n - 1) << endl;
	
    return 0;

}
