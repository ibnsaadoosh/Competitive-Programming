
///notes : Prime Numbers.

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>   ///for funtion<>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define ld              long double
#define rep(i,n)       for(int i=0 ; i<n ; ++i)
#define loop(i, x, n)   for(int i=x ; i<=n ; ++i)

typedef vector<int> vi;
typedef deque<int> de;
typedef map<int, int> imap;
typedef map<char, int> cmap;
typedef map<string, int> strmap;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int _sieve_size;
bitset<1010> bs;
vi primes;

void sieve(int upperbound)
{
    int _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = 0;
    primes.push_back(1);
    for(int i = 2 ; i<_sieve_size ; i++)
    {
        if(bs[i])
        {
            for(int j = i*i ; j <= _sieve_size ; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

int main()
{
    //fast();
    int c, N, End = 0, index = 0;
    while(cin >> N >> c)
    {
        sieve(N);
        if(sz(primes) % 2 == 0)  End = 2*c;
        else                End = 2*c -1;
        if(End > sz(primes)) End = sz(primes);
        index = (sz(primes) - End) / 2;
        cout << N << " " << c << ": ";
        while(End--)
        {
            if(End == 0) cout << primes[index++];
            else cout << primes[index++] << " ";

        }
        cout << endl << endl;
        primes.clear();
        End = 0 , index = 0;
    }
    return 0;
}
