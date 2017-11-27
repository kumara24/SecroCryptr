#pragma once
#include <iostream>
#include <cmath>
using namespace std;

void matrixmult(int arr[3][3], int f, int arr2[], int ans[])
{
	int r, c, counter = 0, checker = 0;
	int num = f / 3; 
	while (num>0) {
		for (r = 0; r < 3; ++r) {
			for (c = 0; c < 3; ++c) {
				ans[counter] += arr[r][c] * arr2[checker];
				++checker;
			}
			++counter;
			checker = checker - 3;
		}
		checker += 3;
		--num;
	}
}

int determinant(int arr[3][3])
{
	int deter = 0;
	deter = (arr[0][0] * (arr[1][1] * arr[2][2] - arr[2][1] * arr[1][2])) - (arr[0][1] * (arr[1][0] * arr[2][2] - arr[2][0] * arr[1][2])) + (arr[0][2] * (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]));
	return deter;
}

void minor(int arr[3][3], int arr2[3][3])
{
	arr2[0][0] = arr[1][1] * arr[2][2] - arr[2][1] * arr[1][2];
	arr2[0][1] = arr[1][0] * arr[2][2] - arr[2][0] * arr[1][2];
	arr2[0][2] = arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1];
	arr2[1][0] = arr[0][1] * arr[2][2] - arr[2][1] * arr[0][2];
	arr2[1][1] = arr[0][0] * arr[2][2] - arr[2][0] * arr[0][2];
	arr2[1][2] = arr[0][0] * arr[2][1] - arr[2][0] * arr[0][1];
	arr2[2][0] = arr[0][1] * arr[1][2] - arr[1][1] * arr[0][2];
	arr2[2][1] = arr[0][0] * arr[1][2] - arr[1][0] * arr[0][2];
	arr2[2][2] = arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
}

void transpose(int arr[3][3], int arr2[3][3])
{
	int i, j;
	for (i = 0; i<3; ++i)
		for (j = 0; j<3; ++j)
			arr2[j][i] = arr[i][j];

}
void invert(int arr[3][3], int arr2[3][3])
{
	int cof[3][3] = { 0 };
	int determ = determinant(arr);
	minor(arr, cof);

	
	cof[1][0] *= -1;
	cof[0][1] *= -1;
	cof[2][1] *= -1;
	cof[1][2] *= -1;

	transpose(cof, arr2);
}

void lettertonum(string x, int arr[], int length)
{
	int b;
	for (b = 0; b < length; ++b) {  
		arr[b] = pow((int(x[b]) + 16), 2) - 10000;
	}
}

void numtoletter(int arr[], char ans[], int length)
{
	for (int d = 0; d < length; ++d) {
		if (arr[d] == 1)
			ans[d] = ' ';
		else
			ans[d] = sqrt(arr[d] + 10000) - 16;

	}
}
void addFiller(int arr[], int &length)
{
	if (length % 3 == 2) 
	{
		arr[length] = 1;
		++length; 
	}
	else if (length % 3 == 1) 
	{
		arr[length] = 1;
		arr[length + 1] = 1;
		length = length + 2; 
	}
}