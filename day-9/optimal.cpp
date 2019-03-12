// Name: Anurag
// Roll no: 1601CS05

#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("test.txt", "r", stdin);
	int frames;

	while (cin >> frames)
	{
		int n = 0, h;
		vector<int> arr;

		int hits = 0;
		int pageFault = 0;
		int ans[100][100] = {0}, current[100];
		int time[100] = {0};

		while (cin >> h)
		{

			if (h == -1)
				break;
			arr.push_back(h);
			++n;
		}

		for (int t = 0; t < 100; t++)
			for (int y = 0; y < 100; y++)
				ans[t][y] = -1;

		for (int t = 0; t < 100; t++)
		{
			time[t] = 0;
			current[t] = -2;
		}

		for (int e = 0; e < n; e++)
		{
			int a = arr[e];
			int max = -999999, pos;
			int zz = -1;

			for (int q = 0; q < frames; q++)
			{
				if (arr[e] == current[q])
					zz = 1;
			}

			if (zz == 1)
			{
				++hits;
				continue;
			}

			int check[9999] = {0};

			for (int p = 0; p < frames; p++)
			{
				int earl = 999999;
				int tz = current[p];

				if (tz == -2)
				{
					pos = p;
					break;
				}

				for (int rt = e + 1; rt < n; rt++)
				{
					if (tz == arr[rt])
					{
						earl = rt;
						break;
					}
				}

				if (earl > max)
				{
					max = earl;
					pos = p;
				}
			}

			current[pos] = arr[e];
			++pageFault;

			for (int w = 0; w < frames; w++)
				ans[w][e] = current[w];
		}

		for (int e = 0; e < frames; e++)
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
