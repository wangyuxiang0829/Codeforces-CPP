#include <vector>
#include <climits>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                int tmp = prices[i] - min;
                if (tmp > ans)
                {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
};
