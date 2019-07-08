
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
bitset<1000010> bs;
vi primes;

void sieve(int upperBound)
{
    _sieve_size = upperBound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2 ; i<= _sieve_size ; i++)
    {
        //cout << "yes\n";
        if(bs[i])
        {
            for(ll j = i*i ; j<= _sieve_size ; j += i) bs[j] = 0;
            primes.push_back(int(i));
        }
    }
}

bool isprime(int n)
{
    return bs[n];
}

int main()
{
    //fast();
    sieve(1000000);
    int n, temp, i;
    while(cin >> n)
    {
        i = 0, temp = 0;
        if(n == 0) break;
        while(true)
        {
            temp = n - primes[i];
            if(bs[temp])
            {
                cout << n << " = " << primes[i] << " + " << temp << endl;
                break;
            }
            else i++;
            if(primes[i] >= n)
            {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
        }

    }
    return 0;
}
