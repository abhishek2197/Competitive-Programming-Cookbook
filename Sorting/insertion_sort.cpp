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

	// Map integer to correct location
	map <int, int> m; 

	// Read size of input array
	cin >> n;

	// Read input vector
	vector<ll>v(n);

	// Store temp vector
	vector<ll>temp(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
		temp[i] = v[i];
	}

	// For sorting entire array run for n iterations
	for(int i = 0; i < n; i++){
		// Find the correct location for the element at ith index
		int current_val = v[i];
		int j = i;
		while (j > 0 && v[j-1] > current_val){
			v[j] = v[j-1];
			j -= 1;
		}
		v[j] = current_val;
	}

	// Print sorted vector
	for(int i = 0; i < n; i++){
		// Print element
		cout << v[i] << " ";
		
		// Map element to corresponding index
		m[v[i]] = i + 1;
	}
	// cout << endl;

	// Print sorted vector
	for(int i = 0; i < n; i++){
		// Print locations
		cout << m[temp[i]] << " ";
	}
	return 0;
}

// Time Complexity: O(N^2)

