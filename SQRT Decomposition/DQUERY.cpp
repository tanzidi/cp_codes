// https://www.spoj.com/problems/DQUERY/en/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;

const int K = 55;

struct st {
	int l, r, idx;
};

bool cmp(st &a, st &b) {
	int block_a = a.l / K;
	int block_b = b.l / K;
	if (block_a == block_b) return a.r < b.r;
	else return block_a < block_b;
}
int freq[1000005];
int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;
    int ara[n];
    for (int i = 0; i < n; i++) {
    	cin >> ara[i];
    }
    int q; cin >> q;
    vector<st> qri;
    for (int i = 0; i < q; i++) {
    	int x, y; cin >> x >> y;
    	st tmp;
    	tmp.l = x;
    	tmp.r = y;
    	tmp.idx = i;
    	qri.push_back(tmp);
    }
    sort(qri.begin(), qri.end(), cmp);
    int ans[q];
    int L = 0, R = 0;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
    	int l = qri[i].l;
    	l--;
    	int r = qri[i].r;
    	r--;
    	if (r > R) {
    		while(1) {
	    		if (freq[ara[R]] == 0) cnt++;
	    		freq[ara[R]]++;
	    		R++;
	    		if (R > r) break;
	    	}
    	}
    	else if (r < R) {
    		while(1) {
    			R--;
    			if (freq[ara[R]] == 1) cnt--;
    			freq[ara[R]]--;
    		}
    	}
    	ans[qri[i].idx] = cnt;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << "\n";

}