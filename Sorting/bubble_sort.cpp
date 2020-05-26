// Author: Abhishek Ananthakrishnan

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>


#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pll pair<long long,long long>
#define PI 3.14159
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
	// your code goes here
	fastio;
	ll n;
	// Read size of input array
	cin>>n;

	// Read input vector
	vector<ll>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	// For counting total swaps performed
	int count_no_swaps = 0;
	for(int i = 0; i < n - 1; i++){
		// Run second loop N - i - 1 times as last i elements already sorted 
		for(int j = 0; j < n - i - 1; j++){
			if(v[j] > v[j+1]){
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				count_no_swaps++;
			}
		}
	}
	// Print sorted vector
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;

	// Print total swaps
	cout << count_no_swaps << endl;
	return 0;
}

// Time Complexity: O(N^2)
