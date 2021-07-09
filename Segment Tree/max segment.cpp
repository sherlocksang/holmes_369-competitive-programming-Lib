
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



//-----------------------------------------------
//////////////////////////////////////////
//---------Date: 10-07-21 ---------------

struct item
{
	ll  seg ;
	ll  pref ;
	ll  suf ;
	ll  sum ;
};

struct segtree
{
	ll  sz ;
	std::vector<item> arr;


	item NEUTRAL_ELEMENT = {0 , 0 , 0 , 0};
	void init(int n){
		sz = 1;
		while (sz < n)
		{
			sz *= 2;
		}

		arr.assign(2*sz  , NEUTRAL_ELEMENT);
	}
	item single(int val){
		if(val > 0 ){
			return {val , val , val , val};
		}
		else return {0 , 0  , 0 , val};

		//because we want max seg max suf max pref
	}

	item merge(item a , item b){
		return {
			max(a.seg , max(b.seg , a.suf + b.pref)),
			max(a.pref , a.sum + b.pref),
			max(b.suf , b.sum + a.suf),
			a.sum + b.sum
		};
	}

	void build_recc(std::vector<ll>& v , int x , int lx , int rx ){
		if(rx - lx == 1){
			if(lx < (int)v.size()){
				arr[x]  = single(v[lx]);
			}
			return ;
		}

		int m = (lx  + rx)/2;

		build_recc(v , 2*x+1 , lx , m);
		build_recc(v , 2*x+2 , m , rx);

		arr[x] = merge(arr[2*x + 1] , arr[2*x + 2]);
	}
	void build(std::vector<ll>& v){
		build_recc(v , 0 , 0 , sz);
	}
	void set_recc(int i , int val , int x,int lx,int rx){
		if(rx - lx == 1){
			arr[x] = single(val);
			return ;
		}

		int m = (lx+rx)/2;

		if(i < m)set_recc( i , val, 2*x+1, lx , m);
		else set_recc( i , val, 2*x+2, m , rx);

		arr[x] = merge(arr[2*x+1], arr[2*x+2]);
	}
	void setValue(int i , int val){
		set_recc(i , val , 0 , 0 ,sz);
	}
	item max_seg_recc(int l , int r , int x , int lx , int rx){
		if(rx <= l || r <= lx){
			return NEUTRAL_ELEMENT;
		}

		if(rx <= r && lx >= l){
			return arr[x];
		}
		int m = (lx+rx)/2;
		item s1 = max_seg_recc(l , r , 2*x+1 , lx , m);
		item s2 = max_seg_recc(l , r , 2*x+2 , m , rx);

		return merge(s1 , s2);
	}

	item max_seg(int l , int r){
		return max_seg_recc(l , r , 0 ,0,sz);
	}
};

void test_case(){
	int n,q;cin>>n>>q;
	std::vector<ll> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	segtree st;
	st.init(n);

	st.build(v);
	cout<<st.max_seg(0,n).seg<<"\n";
	while (q--)
	{
		int idx,val;cin>>idx>>val;
		st.setValue(idx , val);

		cout<<st.max_seg(0 , n).seg<<"\n";
	}

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	//init();

	//genprimes(1e6);
	int t=1;//;cin>>t;
	while (t--)
	{
		test_case();
	}
	return 0;
}
