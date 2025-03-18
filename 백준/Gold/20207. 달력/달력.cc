#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    // 약간의 속도 향상
    Init();

    int InputSize = 0;
    cin >> InputSize;

    vector<pair<int, int>> Schedules(InputSize);

    for (int i = 0; i < InputSize; i++)
    {
        cin >> Schedules[i].first >> Schedules[i].second;
    }

    vector<int> Days(367);

    for (int i = 0; i < InputSize; i++)
    {
        for (int j = Schedules[i].first; j <= Schedules[i].second; j++)
        {
            Days[j]++;
        }
    }

    int Start = 0;
    int MaxY = 0;
    int Sum = 0;

    for (int i = 1; i <= 366; i++)
    {
        if (Days[i - 1] != 0 && Days[i] == 0)
        {
            Sum += MaxY * (i - Start);
            MaxY = -1;
        }
        else if (Days[i - 1] == 0 && Days[i] != 0)
        {
            Start = i;
        }

        if (Days[i] != 0)
        {
            MaxY = max(MaxY, Days[i]);
        }
    }

    cout << Sum;

    return 0;
}

