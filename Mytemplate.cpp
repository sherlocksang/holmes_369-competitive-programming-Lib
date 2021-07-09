
#include <bits/stdc++.h>

#define ll long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair<int,int>

#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define dump(x)  cerr << #x << " = " << (x) << endl
#define ALL(t) (t).begin(),(t).end()
#define ALLR(t) (t).rbegin(),(t).rend()



using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {-1, 1, 0, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

#define MOD 1000000007


namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) {
	  if (n <= 1) return false;
	  if (n <= 3) return true;

	  if (n % 2 == 0 || n % 3 == 0) return false;

	  for (ll i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i+2) == 0)
		  return false;

	  return true;
	}

	bool prime[15000105];
	void sieve(int n) {
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
		  for (ll i = p * p; i <= n; i += p)
			prime[i] = false;
		}
	  }
	  prime[1] = prime[0] = 0;
	}

	vector<ll> primelist;
	bool __primes_generated__ = 0;

	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}

	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;

	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  sort(facs.begin(), facs.end());
	  return facs;
	}

	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}

using namespace number_theory;
///////////////////////////////////////

//////////////////////////////////////////


void test_case(){
  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	//init();
	int t;cin>>t;
	while (t--)
	{
		test_case();
	}
	return 0;
}
