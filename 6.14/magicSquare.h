#pragma once

#include <iostream>
#include <vector>

using namespace std;

class MagicSquare
{
private:
	vector<vector<int>> _square;

public:
	MagicSquare(int n = 1)
	{
		_square.resize(n, vector<int>(n, 0));
	}
};