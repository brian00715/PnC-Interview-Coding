#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Get the max steal object
 *
 * @param rooms
 * @return int max stealing value
 */
int get_max_steal(vector<int> rooms)
{
    int n = rooms.size();
    vector<int> dp(n + 1, 0);
    dp[0] = rooms[0];
    dp[1] = max(rooms[0], rooms[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + rooms[i]);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> rooms={2,7,9,3,1};
    int max_value = get_max_steal(rooms);
    cout<<max_value;
}