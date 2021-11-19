#include <bits/stdc++.h>
#define pi pair<int,int>
#define F first
#define S second

using namespace std;

bool cmp(pi a, pi b){
	return a.S < b.S;
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,int>> points(k);
	set<pi> spoints;
	for(int i=0;i<k;i++) {
		cin>>points[i].F>>points[i].S;
		spoints.insert(points[i]);
	}

	map<int,int> compx,compy,morex,morey;
	vector<pair<int,int>> a=points, b=points;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),cmp);
	pi prevx = {0,0};
	for(int i=0;i<(int)a.size();i++){
		if(a[i].F > prevx.F) prevx.F = a[i].F, prevx.S++;
		compx[prevx.F] = prevx.S;
		morex[prevx.S] = prevx.F;
	}
	pi prevy = {0,0};
	for(int i=0;i<(int)b.size();i++){
		if(b[i].S > prevy.F) prevy.F = b[i].S, prevy.S++;
		compy[prevy.F] = prevy.S;
		morey[prevy.S] = prevy.F;
	}

	vector<vector<int>> nums(prevx.S+1, vector<int>(prevy.S+1,0));

	long long ans = 0;

	for(int i=0;i<=prevx.S;i++){
		for(int j=0;j<=prevy.S;j++){
			if(spoints.count({morex[i],morey[j]})) nums[i][j] ++;
			if(i>0)nums[i][j] += nums[i-1][j];
			if(j>0)nums[i][j] += ((nums[i][j-1] - (i==0?0:nums[i-1][j-1])));
			if(nums[i][j]&1){
				long long current = ( (long long)(i==prevx.S?n+1:morex[i+1])-morex[i])*((long long)(j==prevy.S?m+1:morey[j+1])-morey[j]);
				ans += current;
			}
		}
	}
	cout<<ans<<" "<<((long long)n*m - ans)<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("dull.in", "r", stdin);
	
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
