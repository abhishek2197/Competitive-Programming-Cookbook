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
	ll n, k;

	// Read size of input array and iteration number
	// Goal here is to check the state of array after k iterations and also sort the array
	cin >> n >> k;

	// Read input vector
	vector<ll>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	// For sorting entire array run for n - 1 iterations
	for(int i = 0; i < n - 1; i++){
		// Find the index with minimum value in the array
		int min_index = i;
		for(int j = i + 1; j < n; j++){
			if(v[j] < v[min_index]){
				min_index = j;
			}
		}
		// Swap minimum value to the current index (front)
		int temp = v[min_index];
		v[min_index] = v[i];
		v[i] = temp;

		// Print state of vector after k iterations
		if((i+1) == k){
			for(int i = 0; i < n; i++){
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
	// Print sorted vector
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

// Time Complexity: O(N^2)
