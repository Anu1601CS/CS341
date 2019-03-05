// Name: Anurag
// Roll no: 1601CS05

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("page.txt", "r", stdin);
	int framesSize;

	while (cin >> framesSize)
	{
		int n = 0, h;
		int hits = 0;
		int pageFault = 0;
		int ans[500][500] = {0}, current[500];
		vector<int> arr;

		while (cin >> h)
		{

			if (h == -1)
				break;
			arr.push_back(h);
			++n;
		}

		for (int t = 0; t < 500; t++)
			for (int y = 0; y < 500; y++)
				ans[t][y] = -1;
		int track[500] = {0};

		for (int t = 0; t < 500; t++)
		{
			track[t] = 0;
			current[t] = -2;
		}

		for (int e = 0; e < n; e++)
		{
			int a = arr[e];
			int maxx = -99999999, pos;
			int zz = -1;

			for (int q = 0; q < framesSize; q++)
			{
				if (arr[e] == current[q])
				{
					track[q] = 1;
					zz = 1;
				}
			}

			if (zz == 1)
			{
				++hits;
				continue;
			}

			for (int w = 0; w < framesSize; w++)
			{

				if (track[w] > maxx)
				{

					maxx = track[w];
					pos = w;
				}

				track[w] += 1;
			}

			current[pos] = arr[e];
			++pageFault;
			track[pos] = 0;

			for (int w = 0; w < framesSize; w++)
				ans[w][e] = current[w];
		}

		for (int e = 0; e < framesSize; e++)
		{
			for (int v = 0; v < n; v++)
			{
				if (ans[e][v] == -2)
				{
					ans[e][v] = 0;

					cout << ans[e][v] << " ";
				}
				else if (ans[e][v] == -1)
					cout << "  ";

				else
					cout << ans[e][v] << " ";
			}
			cout << endl;
		}

		cout << endl;
		cout << "NO OF HITS = " << hits;
		cout << endl;
		cout << "NO OF FAULTS = " << pageFault;
		cout << endl
			 << endl;
		cout << "---------------------------" << endl;
		cout << endl;
	}
}
