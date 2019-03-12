#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a;

  int process, resources;

  cout << "Enter number of process : ";
  cin >> process;
  cout << "Enter number of resources : ";
  cin >> resources;

  int allocation_matrix[process][resources];
  int max_need[process][resources];
  int avaliable[process][resources];
  int remaining_need[process][resources];
  vector<int> sequence;

  cout << "Enter allocation matrix : " << endl;

  // Allocation Matrix
  for (int i = 0; i < process; i++)
    for (int j = 0; j < resources; j++)
      cin >> allocation_matrix[i][j];

  cout << "Enter max need : " << endl;

  // Max need
  for (int i = 0; i < process; i++)
    for (int j = 0; j < resources; j++)
      cin >> max_need[i][j];

  cout << "Enter avaliable need : " << endl;

  // Avaliable need
  for (int i = 0; i < resources; i++)
    cin >> avaliable[0][i];

  cout << "Remaning matrix needed : " << endl;

  // Remaning need
  for (int i = 0; i < process; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      remaining_need[i][j] = max_need[i][j] - allocation_matrix[i][j];
      cout << remaining_need[i][j] << "\t";
    }
    cout << "\n";
  }

  int pState = 0;
  int aState = 0;
  int breakState = 0;

  while (1)
  {
    int checkCount = 0;

    if (sequence.size() == process || breakState > process)
      break;

    if (find(sequence.begin(), sequence.end(), pState) == sequence.end())
    {
      for (int i = 0; i < resources; i++)
        if (avaliable[aState][i] >= remaining_need[pState][i])
          ++checkCount;

      if (checkCount == resources)
      {
        breakState = 0;
        ++aState;

        for (int i = 0; i < resources; i++)
          avaliable[aState][i] = avaliable[aState - 1][i] + remaining_need[pState][i];

        sequence.push_back(pState);
      }
      else
      {
        ++breakState;

        if (pState < process - 1)
          ++pState;
        else
          pState = 0;
      }
    }
    else
    {
      ++pState;
    }
  }

  if (sequence.size() == process)
  {
    cout << "The system is in a safe state" << endl;

    int pid, r;
    cout << "Enter process id : ";
    cin >> pid;
    cout << "Enter requests : ";

    vector<int> sequence1;
    int tmp[resources];

    for (int i = 0; i < resources; i++)
      tmp[i] = avaliable[0][i];

    memset(avaliable, 0, sizeof(avaliable));

    for (int i = 0; i < resources; i++)
      avaliable[0][i] = tmp[i];

    for (int i = 0; i < resources; i++)
    {
      cin >> r;
      avaliable[0][i] = avaliable[0][i] - r;
      allocation_matrix[pid][i] = allocation_matrix[pid][i] + r;
      remaining_need[pid][i] = remaining_need[pid][i] - r;
    }

    pState = 0;
    aState = 0;
    breakState = 0;

    while (1)
    {
      int checkCount = 0;

      if (sequence1.size() == process || breakState > process)
        break;

      if (find(sequence.begin(), sequence.end(), pState) == sequence.end())
      {
        for (int i = 0; i < resources; i++)
          if (avaliable[aState][i] >= remaining_need[pState][i])
            ++checkCount;

        if (checkCount == resources)
        {
          breakState = 0;
          ++aState;

          for (int i = 0; i < resources; i++)
            avaliable[aState][i] = avaliable[aState - 1][i] + remaining_need[pState][i];

          sequence1.push_back(pState);
        }
        else
        {
          ++breakState;

          if (pState < process - 1)
            ++pState;
          else
            pState = 0;
        }
      }
      else
      {
        ++pState;
      }
    }

    if (sequence1.size() == process)
      cout << "The request will be granted immediately as system will be in safe state after accepting the request." << endl;
    else
      cout << "The request can't be granted immediately." << endl;
  }
  else
    cout << "The system is not in safe state" << endl;

  return 0;
}
