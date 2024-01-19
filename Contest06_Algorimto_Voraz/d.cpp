#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    while (cin >> N && N != 0) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while (N--) {
            int v;
            cin >> v;
            pq.push(v);
        }
        int cost = 0, total = 0;
        while (pq.size() > 1)
        {
            total = pq.top();
            pq.pop();
            total += pq.top();
            pq.pop();
            cost += total;
            pq.push(total);
        }
        cout << cost << endl;
    }
    return 0;
}