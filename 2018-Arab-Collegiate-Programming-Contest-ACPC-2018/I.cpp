#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//////////////////////////////////////////
#define endl '\n'
#define pb push_back
#define gg exit(0)
#define inf 2147483647
#define linf 9223372036854775807LL
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ti tuple<int,int,int>
#define mp make_pair
#define mt make_tuple
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pi>
#define vpll vector<pll>
#define vll vector<ll>
#define vti  vector<ti>
#define vvi vector<vi>
#define F first
#define S second
#define tcase int tttttt;cin>>tttttt;while(tttttt--)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define mod ((int)1e9+7)

#define int long long
/////////////////////////////////////////
///////////////functions/////////////////


void solve(){
	int n,m;
	cin>>n>>m;
	vpi nums(n);
	for(int i=0;i<n;i++) cin>>nums[i].F;
	for(int i=0;i<n;i++){
		cin>>nums[i].S;
		nums[i].S = -nums[i].S;
	}
	sort(all(nums));
	int ans=-inf, cnt=0;
	int idx=-1;
	for(int i=0;i<m;i++){
		if(ans<nums[i].F)idx=i;
		ans = max(nums[i].F, ans);
	}
	for(int i=idx;i<n;i++){
		if(nums[i].F!=ans)break;
		else idx=i;
	}
	vi values;
	for(int i=idx;i>=0;i--)values.pb(-nums[i].S);
	sort(allr(values));
	for(int i=0;i<m;i++)cnt+=values[i];
	cout<<ans<<" "<<cnt<<endl;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("icecream.in", "r", stdin);
	//freopen("teleport.out", "w", stdout);
	///////////////////////////////////////////////
	tcase solve();
	return 0;
}
