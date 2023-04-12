#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
    bool operator()(pii a, pii b)
    {
        return a.first > b.first;
    }
};

int platforms(vector<pii> trains)
{
    int count = 1;
    int n = trains.size();
    priority_queue<pii, vector<pii>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(trains[i]);
    }
    for (int i = 0; i < n; i++)
    {
        trains[i] = pq.top();
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> p;
    p.push(trains[0].second);
    for (int i = 1; i < n; i++)
    {
        if (p.top() >= trains[i].first)
        {
            count++;
        }
        else
        {
            p.pop();
        }
        p.push(trains[i].second);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<pii> trains;
    for (int i = 0; i < n; i++)
    {
        int arr, dep;
        cin >> arr >> dep;
        trains.push_back({arr, dep});
    }
    cout << platforms(trains);
    return 0;
}