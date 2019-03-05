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
		vector<int> arr;
		int freq[1111] = {0};
		int pageFault = 0;
		int hits = 0;
		int ans[100][100] = {0}, current[100];

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

		int track[100] = {0};

		for (int t = 0; t < 100; t++)
		{
			track[t] = 0;
			current[t] = -2;
		}

		for (int e = 0; e < n; e++)
		{
			int a = arr[e];
			int maxx = -999999, pos;
			int zz = -1;

			for (int q = 0; q < framesSize; q++)
			{
				if (a == current[q])
					zz = 1;
			}

			if (zz == 1)
			{
				++hits;

				freq[a] += 1;
				continue;
			}

			int mint = 999999;

			for (int ev = 0; ev < framesSize; ev++)
			{
				if (current[ev] == -2)
				{
					pos = ev;
					break;
				}

				if (freq[current[ev]] < mint)
				{
					mint = freq[current[ev]];
					pos = ev;
					maxx = track[ev];
				}
				else if (freq[current[ev]] == mint)
				{

					if (track[ev] > maxx)
					{

						maxx = track[ev];
						pos = ev;
					}
				}

				track[ev] += 1;
			}

			int t = current[pos];
			current[pos] = arr[e];
			++pageFault;
			track[pos] = 0;

			for (int w = 0; w < framesSize; w++)
				ans[w][e] = current[w];

			freq[a] += 1;
			if (t != -2)
				freq[t] = 0;
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
