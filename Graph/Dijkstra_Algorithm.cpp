// **check t = number of test_case
//Dijkstra **********
const int nax = 1e5+7;
const long long INF = 1e18;
 
std::vector<vector<pair<int , int > > >vv;
int n , m;
vector<long long >dist;
std::vector<int> par;
void Dijkstra(int s){
	dist[s] = 0;
	using pii = pair<ll,ll>;
	priority_queue<pii , vector<pii>, greater<pii> > pq;
	pq.push({ 0 , s});
	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		ll d = p.F;
		ll d_v = p.S;
		if(d != dist[d_v]) continue; // we can do d > dist[d_v] but we know there no condition d < dist[d_v]
		for (auto x : vv[d_v])
		{
			ll to = x.F;
			ll len = x.S;
			//error(to , len , dist[to]);
			if(d + len < dist[to]){
				dist[to] = d + len;
				pq.push({dist[to] , to});
				par[to] = d_v;
				//error(d_v , par[to]);
			}
		}
	}
 
}
void test_case(){
 
	cin>>n>>m;
	vv.resize(n+1);
	dist.assign(n+1 , INF);
	par.assign(n+1 , -1);
	 for (int i = 0; i < m; ++i)
	 {
	 	int a,b,w;cin>>a>>b>>w;
		a--;b--;
		vv[a].push_back({b,w});
		vv[b].push_back({a,w});
	 }
	 Dijkstra(0);
	 if(dist[n-1] == INF)cout<<"-1\n";
	 else {
		 std::vector<int> path;
		 int parent = n-1;
		 par[0] = 0;
		 while (parent != -1 && parent != par[parent])
		 {
		 	path.push_back(parent);
			//error(parent , par[parent]);
			parent = par[parent]; 
			if(parent == -1){
				cout<<"-1";
				return;
			}
		 }
		 path.push_back(0);
		// for (int v = n-1; v != 0; v = par[v])
        // 	path.push_back(v);
		//
    	// path.push_back(0);
		//
    	// reverse(path.begin(), path.end());
		 for (int i = path.size()-1; i >= 0; --i)
		 {
		 	cout<<path[i]+1<<" ";
		 }
		 // for (int var : path)
		 // {
		 // 	std::cout << var+1 << " ";
		 // }
	 }
}
