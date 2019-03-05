// Name: Anurag
// Roll no: 1601CS05

#include <bits/stdc++.h>

using namespace std;

bool checkAvailable(int i, vector<int> &v)
{
    for (int j = 0; j < v.size(); ++j)
        if (v[j] == i)
            return true;
    return false;
}

void FIFO(int frameSize, vector<int> &sequences)
{
    int ans[frameSize][sequences.size()];
    memset(ans, 0, sizeof(ans));
    int oldest = 0;
    int pageFault = 0;

    vector<int> pattern;
    cout << "FIFO :" << endl;

    for (int start = 0; start < sequences.size(); start++)
    {
        bool found = false;
        for (int j = 0; j < frameSize; j++)
        {
            if (start == 0)
                break;
            ans[j][start] = ans[j][start - 1];
        }

        for (int j = 0; j < frameSize; j++)
        {
            if (ans[j][start] == sequences[start])
            {
                found = true;
                break;
            }
        }

        if (found == false)
        {
            ans[oldest][start] = sequences[start];
            oldest = (oldest + 1);
            if (oldest + 1 > frameSize)
                oldest = 0;
            pageFault++;
            pattern.push_back(start);
        }
    }

    for (int k = 0; k < frameSize; ++k)
    {
        for (int i = 0; i < sequences.size(); ++i)
        {
            if (checkAvailable(i, pattern))
                cout << ans[k][i] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << "\nUsing " << frameSize << " frames, the reference string yielding :" << endl;
    cout << "Scheme\t\t#faults " << endl;
    cout << "FIFO\t\t" << pageFault << endl;
}

int main()
{
    FILE *fp = fopen("pages.txt", "r");

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

            cout << x << " ";

            sequences.push_back(x);
        }
        cout << endl
             << "---------------------------------------" << endl
             << endl;

        FIFO(frameSize, sequences);
    }
}
