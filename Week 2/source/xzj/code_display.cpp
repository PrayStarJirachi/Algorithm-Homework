void prepare() {
	for(int i = 1; i < N; i++) // Calculate the harmonic sequence
		H[i] = H[i - 1] + fraction(1, i);
	
	dp[1][1] = fraction(0, 1); // Calculate dp[i][j]
	for(int i = 2; i < N; i++)
		for(int j = 1; j <= i; j++){
			fraction sum(0, 1);
			for(int k = 1; k <= i; k++){
				if (k > j) sum = sum + dp[k - 1][j];
				if (k < j) sum = sum + dp[i - k][j - k];
			}
			sum = sum / fraction(i, 1);
			dp[i][j] = sum + fraction(i, 1);
		}
}
fraction get_ex8_ans(int n, int k) { // Calculate answer using the formular in ex8
	if (n == 1) return fraction(0, 1);
	fraction ans(0, 1);
	if (k == 1 || k == n) ans = ans - fraction(1, 2);
	else ans = ans - fraction(1, 3);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans = ans + fraction(1, max(i,j,k) - min(i,j,k) + 1);
	return ans;
}
fraction get_ex9_ans(int n, int k) { // Calculate answer using the formular in ex9
	if(n == 1) return fraction(0, 1);
	fraction ans(2 * n + 5, 1);
	ans = ans + fraction(2 * n + 2, 1) * H[n];
	ans = ans - fraction(2 * n - 2 * k + 5) * H[n - k + 1];
	ans = ans - fraction(2 * k + 3) * H[k];
	if(k == 1 || k == n) ans = ans - fraction(1, 2);
	else ans = ans - fraction(1, 3);
	return ans;
}
int main() {
	prepare();
	int n, k;
	cin >> n >> k;
	fraction standed_ans= dp[n][k];
	fraction ex8_ans = get_ex8_ans(n, k);
	fraction ex9_ans = get_ex9_ans(n, k);
	//these three ans are the same
	cout << "E = " << ex9_ans.x << " / " << ex9_ans.y << endl;
}
