#include <bits/stdc++.h>
using namespace std;
int main()
{

	freopen("page.txt", "r", stdin);
	int frames;
	while (cin >> frames)
	{
		int n = 0, h;
		vector<int> arr;
		while (cin >> h)
		{

			if (h == -1)
				break;
			arr.push_back(h);
			++n;
		}
		int uu = 0;
		int uu2 = 0;
		int house[500][500] = {0}, current[500];
		for (int t = 0; t < 500; t++)
			for (int y = 0; y < 500; y++)
				house[t][y] = -1;
		int time[500] = {0};
		for (int t = 0; t < 500; t++)
		{
			time[t] = 0;
			current[t] = -2;
		}
		for (int e = 0; e < n; e++)
		{
			int a = arr[e];
			int maxx = -99999999, pos;
			int zz = -1;

			for (int q = 0; q < frames; q++)
			{
				if (arr[e] == current[q])
				{
					time[q] = 1;
					zz = 1;
				}
			}

			if (zz == 1)
			{
				++uu;
				continue;
			}

			for (int w = 0; w < frames; w++)
			{

				if (time[w] > maxx)
				{

					maxx = time[w];
					pos = w;
				}

				time[w] += 1;
			}
			current[pos] = arr[e];
			++uu2;
			time[pos] = 0;
			for (int w = 0; w < frames; w++)
				house[w][e] = current[w];
		}

		for (int e = 0; e < frames; e++)
		{
			for (int v = 0; v < n; v++)
			{
				if (house[e][v] == -2)
				{
					house[e][v] = 0;

					cout << house[e][v] << " ";
				}
				else if (house[e][v] == -1)
					cout << "  ";

				else
					cout << house[e][v] << " ";
			}
			cout << endl;
		}
		cout << "NO OF HITS=" << uu;
		cout << endl;
		cout << "NO OF FAULTS=" << uu2;
		cout << endl;
	}
}
