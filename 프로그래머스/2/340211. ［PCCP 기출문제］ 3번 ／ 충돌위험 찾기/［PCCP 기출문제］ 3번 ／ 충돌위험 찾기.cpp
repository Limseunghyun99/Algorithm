#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;

    // x : 로봇의 수
    int x = routes.size();
    // move_cnt : 포인트 이동 횟수
    int move_cnt = routes[0].size();

    map<int, vector<pair<int, int>>> route;

    // x개의 로봇이 돌아다님
    for (int i = 0;i < x;i++)
    {
        // i+1번째 로봇의 이동 경로
        vector<int> r = routes[i];

        vector<pair<int, int>> rtmp;
        // r : {4,2}
        for (int z = 0;z < r.size() - 1;z++)
        {
            int before_x = points[r[z] - 1][0];
            int before_y = points[r[z] - 1][1];
            int next_x = points[r[z + 1] - 1][0];
            int next_y = points[r[z + 1] - 1][1];
            // 처음에만 시작 위치 포함
            if (z == 0)
                rtmp.push_back({ before_x,before_y });
            int k = before_x;
            int l = before_y;
            if (before_x < next_x)             // 아래로
            {
                k += 1;
                for (;k <= next_x;k++)
                    rtmp.push_back({ k,before_y });
            }
            else if (before_x > next_x)        // 위로
            {
                k -= 1;
                for (;k >= next_x;k--)
                    rtmp.push_back({ k,before_y });
            }

            if (before_y < next_y)             // 우로만
            {
                l += 1;
                for (;l <= next_y;l++)
                    rtmp.push_back({ next_x,l });
            }
            else if (before_y > next_y)        // 좌로만
            {
                l -= 1;
                for (;l >= next_y;l--)
                    rtmp.push_back({ next_x,l });
            }

        }
        route[i + 1] = rtmp;
    }

	int max_len = 0;
    for (int i = 0;i < x;i++)
        if (max_len < route[i + 1].size())
            max_len = route[i + 1].size();
    
    // 최대 좌표 이동 횟수
    for (int k = 0;k < max_len;k++)
    {
        // 로봇의 수 (좌표 출현 갯수) -> second(int)의 값이>1인 경우 answer++;
        map<pair<int, int>, int> loc_cnt;
        for (int a = 0;a < x;a++)
            if (route[a + 1].size() > k)
                loc_cnt[{route[a + 1][k].first, route[a + 1][k].second}]++;
        for (auto iter = loc_cnt.begin();iter != loc_cnt.end();iter++)
            if (iter->second > 1) answer++;
    }



    return answer;
}