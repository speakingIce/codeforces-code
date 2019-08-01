// CF-Code.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#pragma warning(disable : 4996)
int main()
{
	int q; cin >> q;
	while (q--) {
		int b, w; cin >> b >> w;
		int smallerNumColorRequired = min(b, w), biggerNumColorRequired = max(b, w);
		if (biggerNumColorRequired > 3 * smallerNumColorRequired + 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int centerLineLeftX = 2, centerLineLeftY = 2;
		int ceterLineRightX, centerLineRightY;
		if (b <= w) {
			centerLineLeftX++;
		}
		int outputX = centerLineLeftX, outputY = centerLineLeftY;

		while (smallerNumColorRequired--) {
			cout << outputX << " " << outputY << endl;
			outputY += 2;
		}
		outputY -= 2;
		ceterLineRightX = outputX;
		centerLineRightY = outputY;
		outputY = centerLineLeftY + 1;

		if (centerLineRightY != centerLineLeftY) {
			while (outputY < centerLineRightY) {
				cout << outputX << " " << outputY << endl;
				outputY += 2;
				biggerNumColorRequired--;
			}
		}
		
		
		outputY = 1;
		cout << outputX << " " << outputY << endl;
		biggerNumColorRequired--;

		if (!biggerNumColorRequired) continue;
		
		outputY = centerLineRightY + 1;
		cout << outputX << " " << outputY << endl;
		biggerNumColorRequired--;
		
		if (!biggerNumColorRequired) continue;
		
		outputX = outputX - 1;
		outputY = centerLineLeftY;
		while (biggerNumColorRequired && outputY <= centerLineRightY) {
			cout << outputX << " " << outputY << endl;
			biggerNumColorRequired--;
			outputY += 2;
		}
		if (!biggerNumColorRequired) continue;
		outputX += 2;
		outputY = centerLineLeftY;
		while (biggerNumColorRequired && outputY <= centerLineRightY) {
			cout << outputX << " " << outputY << endl;
			biggerNumColorRequired--;
			outputY += 2;
		}
	}
    return 0;

}
