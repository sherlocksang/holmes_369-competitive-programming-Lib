
#include <bits/stdc++.h>

#define ll long long
#define PB push_back
#define MP make_pair
#define PI pair<int,int>
#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a

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

//****hacker Earth problem(connnected component )***
//*****method 1 by DFS ***************

/*
std::vector<std::vector<int> > vv;
std::vector<bool> vis;

void dfs(int s) {
	vis[s] = true;
	for (int i = 0; i < vv[s].size(); ++i)
	{
		int next = vv[s][i];
		if(!vis[next]){
			 dfs(next);
		 }
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    int n,e;cin>>n>>e;
	vv.assign(n , std::vector<int>());
	vis.resize(n);
	for (int i = 0; i < e; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	ll cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	std::cout << cnt << "\n";
	return 0;
}

*/
****SPOJ - BUGLIFE problem ********************
********method 1 DFS , method 2 union find , method3 BFS****
****based on Bipartite graph or 2 color **********
/*
const int nax = 2005;
std::vector<std::vector<int> > vv;
std::vector<int> vis;
int col[nax];
bool dfs(int sr , int c){
	vis[sr] = 1;
	col[sr] = c;
	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int next = vv[sr][i];
		if(!vis[next]){
			if(dfs(next , c^1) == true) return true;
		}
		else{
			if(col[sr] == col[next]) return true;
		}
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int t;std::cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		vv.clear();
		vis.clear();
		int n,e;cin>>n>>e;
		vv.assign(n,std::vector<int>());
		vis.resize(n);
		REP(i,n)col[i] = -1;
		for (int i = 0; i < e; ++i)
		{
			int  a,b;cin>>a>>b;
			a--;
			b--;
			vv[a].push_back(b);
			vv[b].push_back(a);
		}
		bool ans = false;
		for(int i =0 ;i<n;i++){
			if(vis[i] != 1){
		      	ans = dfs(i , 0);
				if(ans == true) break;
			}
		}
		if(ans == true){
			std::cout << "Scenario #"<<tt<<":" << "\n";
			std::cout << "Suspicious bugs found!" << "\n";
		}
		else{
			std::cout << "Scenario #"<<tt<<":" << "\n";
			std::cout << "No suspicious bugs found!" << "\n";
		}
	}
	return 0;
}
*/

******** Codeforces - (E. Tree Queries) ******
**Not able to solve , solve later*******
/*
const int nax = 200005;
std::vector<int> vv[nax];
std::vector<int> vis(nax),in(nax),out(nax);
int parent[nax];
int cnt = 1;
void dfs(int sr , int p){
	vis[sr] = 1;
	parent[sr] = p;
	in[sr] = cnt;
	cnt++;
	//dump(c)
	for (int i = 0; i < vv[sr].size(); ++i)
	{

		int next = vv[sr][i];
		if(!vis[next]){
			dfs(next , sr);
		}
	}
	out[sr] = cnt;
	cnt++;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n,m;cin>>n>>m;
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]) dfs(i , -1);
	}
	// REP(i,n) cout<<in[i]<<" ";
	// std::cout << "\n";
	// REP(i,n) std::cout << out[i] << " ";
	while (m--)
	{
		int k;cin>>k;
		std::vector<int> v(k);
		REP(i,k) {
			cin>>v[i];
			v[i]--;
		}
		sort(ALL(v));
		int c_cnt =1 , c_cnt_voil = 0;
		int voil ;
		for (int i = 0; i < k-1; ++i)
		{
			if(in[i] < in[i+1] && out[i] > out[i+1]){
				c_cnt++;
			}
			else{
				c_cnt_voil++;
				voil = i;
			}
		}
		if(c_cnt ==k)std::cout << "YES" << "\n";
		else if(c_cnt_voil >= 2) cout<<"NO\n";
		else if(c_cnt_voil == 1){
			int f =0;
			for(int i =0 ;i<n;i++){
				if(parent[voil] == parent[i] && voil != i){
					cout<<"YES\n";
					f = 1;
					break;
				}
			}
			if(f == 0) cout<<"NO\n";
		}

	}
	return 0;
}

*/
/*
//const int nax =  1e5+7;
std::vector<vector<int> > vv;
std::vector<int> vis;
int c_sz = 0;
void dfs(int sr){
	vis[sr] = 1;
	c_sz++;
	//cout<<sr<<" ";
	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int next = vv[sr][i];
		if(vis[next] == 0){
			dfs(next);
			//c_sz++;
		}
	}

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	while (t--)
	{
		vv.clear();
		vis.clear();
		int n,m;cin>>n>>m;
		vv.assign(n , std::vector<int>());
		vis.resize(n);
		REP(i,n)vis[i] = 0;
		for (int i = 0; i < m; ++i)
		{
			int a,b;cin>>a>>b;
			a--;
			b--;
			vv[a].push_back(b);
			vv[b].push_back(a);

		}
		int cc_cnt = 0;
		c_sz = 0;
		ll way = 1,prev = 0;
		//std::vector<int> sz;
		for (int i = 0; i < n; ++i)
		{
			if(vis[i] == 0){
				prev = c_sz;
				dfs(i);
				//cout<<"\n";
				cc_cnt++;
				way = (ll)way*(c_sz - prev);
			}
		}
		cout<<cc_cnt<<" "<<way<<"\n";

	}
	return 0;
}
/*
1
6 3
1 2
3 4
5 6
*/


//****************************************************
************* SPOJ - longest path Tree *************
//****************************************************
/*
const int nax = 1e4+7;
std::vector<int> vv[nax];
std::vector<bool> vis(nax);

int x , d=0;
void dfs(int sr , int l){
	vis[sr] = true;
	if(d < l){
		x = sr;
		d = l;
	}

	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int next = vv[sr][i];
		if(!vis[next]){
			dfs(next , l+1);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);

	}
	REP(i,n)vis[i] = false;
	dfs(0,0);//(source , length)

	//int sec = x;
	d = 0;
	//vis.clear();
	REP(i,n)vis[i] = false;
	dfs(x,0);
	cout<<d<<"\n";
	return 0;
}
*/
*****size of sub Tree***************
/*
const int nax = 1e4+7;
std::vector<int> vv[nax];
std::vector<bool> vis(nax);
int sz[nax];


int dfs(int sr ){
	vis[sr] = true;
 	int cnt = 1;

	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int next = vv[sr][i];
		if(!vis[next]){
			cnt += dfs(next );
		}
	}
	sz[sr] += cnt;
	return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);

	}
	REP(i,n){
		vis[i] = false;
		sz[i] = 0;
	}
	dfs(0);//(source , length)

	REP(i,n)cout<<sz[i]<<" ";
	return 0;
}
*/

//****************************************************
************* SPOJ - Prime Path *************
//****************************************************
/*
const int nax= 1e5+7;
std::vector<std::vector<int> > vv(nax);
int vis[nax];

int dist[nax];
vector<int> ed;
bool is_prime(int n){
	for (int i = 2; i*i <= n; ++i)
	{
		if(n%i == 0) return false;
	}
	return true;
}
bool is_valid(int a,int b){
	int cnt = 0;
	while (a>0 && b>0)
	{
		int r1 = a%10;
		int r2 = b%10;
		a /= 10;
		b /= 10;
		if(r1 != r2)cnt++;

	}
	if(cnt == 1) return true;
	return false;
}
void All_Edge() {
	for (int i = 1000; i < 10000; ++i)
	{
		if(is_prime(i) == true) ed.push_back(i);
	}
	for (int i = 0; i < ed.size(); ++i)
	{
		for (int j = i+1; j < ed.size(); ++j)
		{
			if( is_valid(ed[i],ed[j])){
				vv[ed[i]].push_back(ed[j]);
				vv[ed[j]].push_back(ed[i]);
				//std::cout << ed[i]<<"->"<<ed[j] << "\n";
			}
		}
	}
}


void bfs(int sr  ,int dis){
	vis[sr] = 1;
	//if(sr == ds) return dis;
	std::queue<int> q;
	q.push(sr );
	dist[sr] = dis;
	//sum++;
	while (!q.empty())
	{
		int nxt = q.front();
		q.pop();
		//summ++;

		for (int i = 0; i < vv[nxt].size(); ++i)
		{
			int curr = vv[nxt][i];
			if(!vis[curr]){
				q.push(curr );
				vis[curr] = 1;
				//if(curr == ds) return (nxt.second + 1);
				dist[curr] = dist[nxt]+1;
			}

		}
	}
	//return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	//is_prime();
	All_Edge();
	//error(ed.size());
	while (t--)
	{
		int sr , ds;
		cin>>sr>>ds;

		//vis.clear();
		for (int i = 1000; i < 10000; ++i)
		{
			vis[i] = 0;
			dist[i] = -1;
		}
		 bfs(sr,0);
		if(dist[ds] != -1)cout<<dist[ds]<<"\n";
		else cout<<"Impossible.\n";
	}
	return 0;
}
*/
//****2nd method
/*

const int nax= 1e5+7;
std::vector<std::vector<int> > vv(nax);
int vis[nax];
bool prime[nax];
int dist[nax];
vector<int> ed;
void is_prime(){
	for (int i = 0; i < nax; ++i)
	{
		prime[i] = true;
	}
	prime[1] = prime[0] = false;
	for (int i = 2; i*i <= nax; ++i)
	{
		if(prime[i]){
			for (int j = 2*i; j < nax; j += i)
			{
				prime[j] = false;
			}
		}
	}

}
bool is_valid(int a,int b){
	int cnt = 0;
	while (a>0 && b>0)
	{
		int r1 = a%10;
		int r2 = b%10;
		a /= 10;
		b /= 10;
		if(r1 != r2)cnt++;

	}
	if(cnt == 1) return true;
	return false;
}
void All_Edge() {
	for (int i = 1000; i < 10000; ++i)
	{
		if(prime[i] == true) ed.push_back(i);
	}
	for (int i = 0; i < ed.size(); ++i)
	{
		for (int j = i+1; j < ed.size(); ++j)
		{
			if( is_valid(ed[i],ed[j])){
				vv[ed[i]].push_back(ed[j]);
				vv[ed[j]].push_back(ed[i]);
				//std::cout << ed[i]<<"->"<<ed[j] << "\n";
			}
		}
	}
}


int bfs(int sr,int dst  ,int dis){
	vis[sr] = 1;
	if(sr == dst) return dis;
	std::queue<pair<int ,int > > q;
	q.push({sr,dis} );
	//dist[sr] = dis;
	//sum++;
	while (!q.empty())
	{
		PI nxt = q.front();
		q.pop();
		//summ++;

		for (int i = 0; i < vv[nxt.first].size(); ++i)
		{
			int curr = vv[nxt.first][i];
			if(!vis[curr]){
				q.push({curr, nxt.second + 1});
				vis[curr] = 1;
				if(curr == dst) return (nxt.second + 1);
				//dist[curr] = dist[nxt]+1;
			}

		}
	}
	return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	is_prime();
	All_Edge();
	//error(ed.size());
	while (t--)
	{
		int sr , ds;
		cin>>sr>>ds;

		//vis.clear();
		for (int i = 1000; i < 10000; ++i)
		{
			vis[i] = 0;
			//dist[i] = -1;
		}
		int ans = bfs(sr,ds,0);
		if(ans != -1)cout<<ans<<"\n";
		else cout<<"Impossible\n";
	}
	return 0;
}
*/
//*********************************************
************** BRIDGES *******************//
///********************************************

*******Q.Bertown-house(Codeforces)*****************

/*
const int nax = 1e5+7;
int vis[nax];
std::vector<vector<int> > vv(nax);
int in[nax];
int low[nax];
std::vector<pair<int,int> > vp;
int timer = 0;
bool bridges = false;
void dfs(int sr , int p ){
	vis[sr] = 1;
	in[sr] = low[sr] = timer;
	timer++;
	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int child = vv[sr][i];

		if(child == p) continue;

		if(vis[child] == 1){

			low[sr] = min(low[sr] , in[child]);
			//vp.push_back({sr,child});
			if(in[sr] > in[child])
				   vp.push_back({sr,child});
		}
		else{
			//vp.push_back({sr,child});
			dfs(child , sr);
			low[sr] = min(low[sr] , low[child]);
			// becuse ak pure circle me koi bridges nhi hoga
			// agar low ko min nhi karte hai toh circle me bridges
			// aa skata hai so its important to do
			// low[child] < in[sr] = back Edge
			// only forward edges can be BRIDGES
			 if(low[child] > in[sr]){
				 bridges = true;
				 return ;
			 }
			 vp.push_back({sr,child});
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n,m;cin>>n>>m;
	REP(i,n) vis[i] = 0,in[i] = -1,low[i] = -1;
	for (int i = 0; i < m; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);

	}
	dfs(0,-1);
	if(bridges == true)cout<<"0"<<"\n";
	else{
		for(int i = 0;i<vp.size();i++){
			cout<<vp[i].first+1<<" "<<vp[i].second+1<<"\n";
		}
 	}
	return 0;
}
*/
const int nax =1e5+7;
std::vector<std::vector<int> > vv;
int in[nax];
int low[nax];
int vis[nax];
int timer = 0;
std::set<int> ans;
int n,m;
void dfs(int sr,int p = -1) {
	vis[sr] = 1;
	in[sr] = low[sr] = timer++;
	int degree = 0;
	for (int i = 0; i < vv[sr].size(); ++i)
	{
		int child = vv[sr][i];
		if(child == sr) continue;

		if(vis[child]){
			low[sr] = min(low[sr] , in[child]);
		}
		else{
			dfs(child , sr);
			low[sr] = min(low[sr], low[child]);

			if(low[child] >= in[sr] && p != -1){
				ans.insert(sr);
			}
			degree++;
		}
	}

	if(degree >=2 && p==-1){
	ans.insert(sr);
	}

}

void test_case(int n,int m){
	//int n,m;cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		vv[a].push_back(b);
		vv[b].push_back(a);

	}
	dfs(0);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	while (n != 0 && m !=0)
	{
		vv.clear();
		ans.clear();
		vv.resize(n);
		for (int i = 0; i < n; ++i)
		{
			vis[i] = 0;
			in[i] = low[i] = -1;
		}
		test_case(n,m);
		cout<<ans.size()<<"\n";
		cin>>n>>m;
	}
	return 0;
}
