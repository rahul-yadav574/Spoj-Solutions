/*
Pretty Kind , Pretty Smart.
*/
#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <climits>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define pii pair<int, int>
#define iin1(a) scanf("%lld", &a)
#define LOOP(s, t, i) for (int i = s; i <= t; i++)
#define iin2(a, b) scanf("%d%d", &a, &b)
#define iin3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define iin4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define pll pair<ll, ll>
typedef long long ll;
ll tc, n;

int main()
{
    iin1(tc);

    while (tc--)
    {
        iin1(n);
        printf("%lld\n", (n * n + n + 2) / 2);
    }

    return 0;
}