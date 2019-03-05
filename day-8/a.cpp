#include <bits/stdc++.h>

using namespace std;

bool checkAvailable(int i, int frameSize, vector<int> v)
{
    for (int j = 0; j < frameSize; ++j)
        if (v[j] == i)
            return true;
    return false;
}

int findPos(int pos, vector<int> sequences, vector<int> v)
{
    int min = 99999;

    for (auto vval : v)
    {
        for (int i = pos; i >= 0; i--)
        {
            if (sequences[i] == vval)
            {
                if (min > i)
                    min = i;
                break;
            }
        }
    }

    return min;
}

int fun(int frameSize, vector<int> v)
{
    for (int j = 0; j < frameSize; ++j)
        if (v[j] == 0)
            return j;

    return frameSize;
}

void LRU(int frameSize, vector<int> &sequences)
{
    vector<int> ans[sequences.size()];

    int pos = 0;
    int pageFault = 0;

    ans[0].assign(frameSize, 0);

    for (auto si : sequences)
    {
        if (pos == 0)
        {
            ++pageFault;
            ans[0][0] = si;
            ++pos;
            continue;
        }

        for (int i = 0; i < frameSize; i++)
        {
            ans[pos] = ans[pos - 1];

            if (!checkAvailable(si, frameSize, ans[pos - 1]))
            {
                ++pageFault;

                if (ans[pos][frameSize - 1] != 0)
                {
                    int asp = fun(frameSize, ans[pos - 1]);

                    if (asp != frameSize)
                    {
                        ans[pos][asp] = si;
                    }
                    else
                    {
                        int replacePos = findPos(pos, sequences, ans[pos - 1]);
                        ans[pos][replacePos] = si;
                    }
                }
                else
                {
                    int replacePos = findPos(pos, sequences, ans[pos - 1]);
                    ans[pos][replacePos] = si;
                }
            }
        }
        ++pos;
    }

    cout << pageFault << " ";
    // for (int i = 0; i < sequences.size(); i++)
    // {
    //     for (auto i : ans[i])
    //         cout << i << "\n";
    //     cout << " ";
    // }
}

int main()
{
    FILE *fp = fopen("page.txt", "r");

    int frameSize;

    while (fscanf(fp, "%d", &frameSize) != EOF)
    {
        vector<int> sequences;
        int x;

        cout << endl;

        while (fscanf(fp, "%d", &x) != EOF)
        {
            if (x == -1)
                break;

            // cout << x << " ";

            sequences.push_back(x);
        }
        cout << endl
             << "---------------------------------------" << endl
             << endl;

        LRU(frameSize, sequences);
    }
}
