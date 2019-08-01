
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

// #define MAX_N (int)1e5

// bool verticesVisit[3 * MAX_N];

using namespace std;

int main()
{
	// int T; cin >> T;
	int T;  cin >> T;
	while (T--) {
//		int n, m; cin >> n >> m;
		int n, m; cin >> n >> m;
//		scanf("%d%d", &n, &m);
//		int* ansSetEdge = new int[m];
		vector<int>verticesVisit(3 * n, 0), ansSetEdge;
		int ansSetEdgeIndex = 0;
//		memset(verticesVisit, false, sizeof verticesVisit);
		for (int i = 0; i < m; i++) {
//			int u, v; cin >> u >> v;
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			if (!verticesVisit[u] && !verticesVisit[v]) {
				verticesVisit[u] = 1;
				verticesVisit[v] = 1;
				ansSetEdge.push_back(i + 1);
			}
		}
		if (ansSetEdge.size() >= n) {
			cout << "Matching" << endl;
			for (int i = 0; i < n; i++) {
				// cout << ansSetEdge[i] << " ";
				printf("%d ", ansSetEdge[i]);
			}
			printf("\n");
		}
		else {
			cout << "IndSet" << endl;
			for (int i = 0, j = 0; i < 3 * n && j < n; i++) {
				if (!verticesVisit[i]) {
					// cout << i + 1 << " ";
					printf("%d ", i + 1);
					j++;
				}
			}
			// cout << endl;
			printf("\n");
		}
		
	}
    return 0;

}
