#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
struct fraction{
	LL x, y;	// x / y
	fraction(LL x = 0, LL y = 1): x(x), y(y){}
	fraction reduction(){
		if(y < 0) x *= -1, y *= -1;
		LL g = __gcd(x, y);
		x /= g; y /= g;
		return *this;
	}
};
fraction operator + (const fraction &a, const fraction &b){
	fraction c(a.x * b.y + a.y * b.x, a.y * b.y);
	return c.reduction();
}
fraction operator - (const fraction &a, const fraction &b){
	fraction c(a.x * b.y - a.y * b.x, a.y * b.y);
	return c.reduction();
}
fraction operator * (const fraction &a, const fraction &b){
	fraction c(a.x * b.x, a.y * b.y);
	return c.reduction();
}
fraction operator / (const fraction &a, const fraction &b){
	fraction c(a.x * b.y, a.y * b.x);
	return c.reduction();
}
fraction H[N], dp[N][N];
int max(int a, int b, int c){
	return max(a,max(b,c));
}
int min(int a, int b, int c){
	return min(a,min(b,c));
}

fraction get_ex8_ans(int n, int k){
	if(n == 1) return fraction(0, 1);
	fraction ans(0, 1);
	if(k == 1 || k == n) ans = ans - fraction(1, 2);
		else ans = ans - fraction(1, 3);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans = ans + fraction(1, max(i,j,k) - min(i,j,k) + 1);
	return ans;
}
fraction get_ex9_ans(int n, int k){
	if(n == 1) return fraction(0, 1);
	fraction ans(2 * n + 5, 1);
	ans = ans + fraction(2 * n + 2, 1) * H[n];
	ans = ans - fraction(2 * n - 2 * k + 5) * H[n - k + 1];
	ans = ans - fraction(2 * k + 3) * H[k];
	if(k == 1 || k == n) ans = ans - fraction(1, 2);
		else ans = ans - fraction(1, 3);
	return ans;
}
void prepare(){
	for(int i = 1; i < N; i++)
		H[i] = H[i - 1] + fraction(1, i);
	dp[1][1] = fraction(0, 1);
	for(int i = 2; i < N; i++)
		for(int j = 1; j <= i; j++){
			fraction sum(0, 1);
			for(int k = 1; k <= i; k++){
				if(k > j) sum = sum + dp[k - 1][j];
				if(k < j) sum = sum + dp[i - k][j - k];
			}
			sum = sum / fraction(i, 1);
			dp[i][j] = sum + fraction(i, 1);
		}
}
int main(){
	prepare();
	
	int n, k;
	cin>>n>>k;
	fraction standed_ans= dp[n][k];
	fraction ex8_ans = get_ex8_ans(n, k);
	fraction ex9_ans = get_ex9_ans(n, k);
	//these three ans are the same
	
	cout<<"E = "<<ex9_ans.x<<" / "<<ex9_ans.y<<endl;
	
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= i; j++){
			//cout<<i<<' '<<j<<endl;
			cout<<dp[i][j].x<<"/"<<dp[i][j].y<<',';
			fraction ex9_ans = get_ex9_ans(i, j);
			fraction ex8_ans = get_ex8_ans(i, j);
			assert(dp[i][j].x == ex9_ans.x && dp[i][j].y == ex9_ans.y);
			assert(dp[i][j].x == ex8_ans.x && dp[i][j].y == ex8_ans.y);
		}
		cout<<endl;
	}
}