#include <bits/stdc++.h>

using namespace std;

const int N = 320;
const int K = 320;
int nums[N][N];

double dp[K][2][N][N];

long long all = 0;
int n,k;

double p(int i, int j){
	return (((double)(i+1)*(j+1)*(n-i)*(n-j))/all);
}

void solve(){
	for(int i=0;i<N;i++)for(int j=0;j<2;j++) for(int a=0;a<N;a++) for(int b=0;b<N;b++) dp[i][j][a][b] = 0;
	all = 0;
	cin>>n>>k;

	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		cin>>nums[i][j];
		if(nums[i][j]) dp[0][1][i][j]++;
		else dp[0][0][i][j]++;
	}

	for(int i=0;i<n;i++)for(int j=0;j<n;j++) all += ((n-i)*(n-j));
	
	for(int s=1;s<=k;s++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int state=0;state<=1;state++){
		double currentP = p(i,j);
		dp[s][state][i][j] += (currentP*dp[s-1][1-state][i][j]+(1-currentP)*dp[s-1][state][i][j]);
	}

	double ans = 0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) ans+=(dp[k][1][i][j]);
	cout<<setprecision(15)<<fixed<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("fetiera.in", "r", stdin);

	int t;
	cin>>t;
	while(t--)
	solve();


	return 0;
}
