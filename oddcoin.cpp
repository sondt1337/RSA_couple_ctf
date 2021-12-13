/* Quốc gia "Sondz" có các đồng xu mệnh giá sau: 1, 3, 5, 10, 30, 50, 100, 300, 500, 
1000, 3000, 5000, 10 000, 30 000 và 50 000 đồng. 
Ngân hàng ban hành thêm một loại xu mới với mệnh giá x đồng. 
Để trả đúng t đồng, cần tối thiểu bao nhiêu đồng xu? */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdio>
#include <bitset>

#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 3e9;
ll x, t;
set<int> s;
inline void FastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void ReadInput() { cin >> x >> t; }
void Prepair()
{
    int cnt = 0;
    for (int i = 1; i <= 50000;)
    {
        s.insert(i);
        if (cnt % 3 == 0)
            i *= 3;
        if (cnt % 3 == 1)
            i = i * 2 - pow(10, cnt / 3);
        if (cnt % 3 == 2)
            i *= 2;
        cnt++;
    }
    s.insert(oo);
}
void Solve()
{
    ll res1 = 0, res2 = oo;
    ll m = t;
    while (t != 0)
    {
        auto it = s.upper_bound(t);
        it--;
        t -= *it;
        res1++;
    }
    for (int i = 1; i <= 200; i++)
    {
        ll t1 = m;
        if (x * i > t1)
            break;
        ll sum = i;
        t1 -= x * i;
        while (t1 != 0)
        {
            auto it = s.upper_bound(t1);
            it--;
            t1 -= *it;
            sum++;
        }
        res2 = min(res2, sum);
    }
    for (int i = 1000; i <= 2000; i++)
    {
        ll t1 = m;
        if (x * i > t1)
            break;
        ll sum = i;
        t1 -= x * i;
        while (t1 != 0)
        {
            auto it = s.upper_bound(t1);
            it--;
            t1 -= *it;
            sum++;
        }
        res2 = min(res2, sum);
    }
    cout << min(res1, res2) << '\n';
}
int main()
{
    FastInput();
    Prepair();
    int test;
    cin >> test;
    while (test--)
    {
        ReadInput();
        Solve();
    }
}
//code by Son
