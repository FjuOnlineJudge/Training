int main(){
	string s;
	int i, n, t, tc = 1;
	cin >> t;
	while (t--){
		cin >> n >> s;
		int nc = 0;
		for (i = 0; i < n; i++)
			if (s[i] == '.')i += 2, nc++;
		cout << "Case " << tc++ << ": " << nc << endl;
	}
}