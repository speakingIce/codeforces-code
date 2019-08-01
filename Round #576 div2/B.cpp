#include <iostream>
#include <cstdio>
#include <algorithm>
 
typedef long long LL;
 
using namespace std;
 
int main()
{
	int H, L;
	cin >> H >> L;
	// (x - H)^2 + L^2 = x^2
	// -2xH + H^2 + L^2 = 0
	// x = (H^2 + L^2) / 2H
	// cout << 1.0 * (H * 1LL * H + L * 1LL * L) / (2 * 1.0 * H) - H << endl;
	printf("%.6lf\n", (H*1LL*H + L*1LL*L) / (2.0*H) - H);
    return 0;
 
}
