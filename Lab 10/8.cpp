#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int A[n];
    int B[m];

    unordered_map<int, int> mp; // stores frequency of each element in array
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mp[A[i]]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        mp[B[i]] *= -1; // frequency is made positive if it's in array B
    }

    int A_sorted[n];        // fully sorted array
    priority_queue<int> pq; // just for sorting
    for (int i = 0; i < n; i++)
    {
        pq.push(A[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        A_sorted[i] = pq.top();
        pq.pop();
    }

    for (int i = 0; i < m; i++) // printing out elements of A that are in B
    {
        for (int j = 0; j < mp[B[i]]; j++)
        {
            cout << B[i] << " ";
        }
        mp[B[i]] = 0;
    }

    // cout << "\n";
    for (int i = 0; i < n; i++) // printing out elements not in B
    {
        // cout << A_sorted[i] << " " << mp[A_sorted[i]] << "\n";
        for (int j = mp[A_sorted[i]]; j < 0; j++) // Element has frequency negative when it is not in B
        {
            cout << A_sorted[i] << " ";
        }
        mp[A_sorted[i]] = 0; // Frequency made 0 to avoid duplicate printing
    }

    return 0;
}