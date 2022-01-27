#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector < vector<int> > matrix;
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		vector <int> tmp;
		for (int j = 0; j < n; j++)
		{
			tmp.push_back((i + 1) * (j + 1));
		}
		matrix.push_back(tmp);
	}

	for (int k = 0; k < n; k++)
	{
		for (int m = 0; m < n; m++)
		{
			int elem = matrix[k][m];
			if(elem > 9)
				cout << elem << " ";
			else
				cout << elem << "  ";
		}
		cout << endl;
	}
	return 0;
}