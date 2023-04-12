#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int prefix_sum = 0;
    int count;
    vector<int> prefix;
    vector<pii> neg_happiness;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        if (ele >= 0)
        {
            sum += ele;
            prefix_sum += ele;
            count++;
        }
        else
        {
            neg_happiness.push_back({i, ele});
        }
        prefix.push_back(prefix_sum);
    }

    priority_queue<pii> pq(neg_happiness.begin(), neg_happiness.end());
    while (!pq.empty() && sum >= 0)
    {
        if (sum + pq.top().second >= 0)
        {
            if (prefix.at(pq.top().first) + pq.top().second >= 0)
            {
                count++;
                sum += pq.top().second;
            }
        }
        pq.pop();
    }
    cout << count;
    return 0;
}