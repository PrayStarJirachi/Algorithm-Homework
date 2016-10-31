#include<bits/stdc++.h>
using namespace std;
int u[10] = {1,1,2,2,2,4,4,5,6,4};
int v[10] = {2,3,3,3,3,5,5,6,7,7};
int f[8];
int get(int x){
	return f[x] == x ? x : (f[x] = get(f[x]));
}
int main(){
	int ans = 0;
	for(int mask = 0; mask < (1 << 10); mask++){
		bool flag = 1;
		int num = 0;
		for(int i = 1; i <= 7; i++)
			f[i] = i;
		for(int i = 0; i < 10; i++)
			if(mask & (1 << i)){
				num++;
				if(get(u[i]) == get(v[i])) flag = 0;
					else f[get(u[i])] = get(v[i]);
			}
		if(num == 5 && flag) ans++;
	}
	cout<<ans<<endl;
}
