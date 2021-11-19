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
#define ld long double
#define PI 3.14159265359
/////////////////////////////////////////
///////////////functions/////////////////

ld first(ld every, ld sz){
	ld s = sin(every*PI/180);
	return s*sz;
}

ld second(ld every, ld sz){
	ld s = cos(every*PI/180);
	return s*sz;
}

void solve(){
	int n;
	cin>>n;
	const ld every = (ld)(((ld)n-2)*180)/n;

	const ld s = n/4./tan((180./n)*PI/180);
	
	ld length = 1;
	int cnt = 1;
	ld ans = 0;
	while(true){
		ld gha = first(every/2., length/2)*2;
		ld er = second(every/2., length/2);
		ld all = (gha*er/2)*n;
		all = ((cnt*all*10000.)/s);
		if(all < 1e-7)break;
		ans+=all;
		length = gha;
		cnt++;
	}
	cout<<setprecision(15)<<ans<<endl;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("baklava.in", "r", stdin);
	//freopen("teleport.out", "w", stdout);
	///////////////////////////////////////////////
	tcase solve();
	return 0;
}
