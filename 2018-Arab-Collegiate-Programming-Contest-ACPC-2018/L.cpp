#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 200;
int nums[N];

bool cmp(int a,int b){
	return nums[a]>nums[b];
}

void solve(){
	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++) cin>>nums[i];

	vector<vector<int>> x(32);
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			if(nums[i]&(1<<j)) x[j].push_back(i);
		}
	}

	for(int i=0;i<32;i++) sort(x[i].begin(), x[i].end(), cmp);

	int ans = 0;
	set<int> s;
	for(int i=31;i>=0;i--){
		if(ans&(1<<i)) continue;
		for(auto current: x[i]){
			if(s.count(current)) continue;
			s.insert(current);
			ans |= nums[current];
			break;
		}
	}

	cout<<ans<<endl;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("looking.in", "r", stdin);

	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
