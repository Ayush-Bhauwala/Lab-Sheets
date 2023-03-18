#include <iostream>
#define ll long long
using namespace std;

class MinStack
{
public:
    ll top;
    ll topMin;
    ll *arr;
    ll *min;
    MinStack()
    {
        arr = (ll *)malloc(sizeof(ll) * 1000);
        min = (ll *)malloc(sizeof(ll) * 1000);
        top = -1;
        topMin = -1;
    }
    void push(ll val)
    {
        top += 1;
        arr[top] = val;
        if (topMin == -1 || val < min[topMin])
        {
            topMin += 1;
            min[topMin] = val;
        }
    }
    void pop()
    {
        if (arr[top] == min[topMin])
        {
            topMin -= 1;
        };
        top -= 1;
    }
    ll returnTop() { return arr[top]; }
    ll getMin() { return min[topMin]; }
};

int main()
{
    ll n;
    cin >> n;
    MinStack stack;
    for (ll i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        stack.push(val);
    }
    ll m;
    cin >> m;
    for (ll i = 0; i < 8; i++)
    {
        ll op;
        cin >> op;
        switch (op)
        {
        case 1:
            ll val;
            cin >> val;
            stack.push(val);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << stack.returnTop() << "<--";
            cout << "\n";
            break;
        case 4:
            cout << stack.getMin() << "<--";
            cout << "\n";
            break;
        default:
            break;
        }
    }
    return 0;
}