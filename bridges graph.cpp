//*********************************************
//************** BRIDGES *******************//
///********************************************

//*******Q.Bertown-house(Codeforces)*****************


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
