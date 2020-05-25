// Author: Abhishek Ananthakrishnan 

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
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
	string pattern,text;
	cin>>pattern>>text;

	// For storing information about the largest suffix which is also the prefix in pattern
	// Helps to iterate the text in one pass without stepping back
	vector<int>kmp(pattern.size());
	kmp[0] = 0;

	// Fill kmp vector with values
	int j=0;
	int i=1;

	// O(M) complexity (M: pattern length)
	while(i < pattern.size()){

		// Match between text and pattern char
		if(pattern[i] == pattern[j]){
			kmp[i] = j + 1;
			i++;
			j++;
		}else{
			// Find the index that matches to the length of prefix
			// Start comparison from the next index (after the end of prefix)
			while(j > 0 && pattern[i] != pattern[j]){
				j = kmp[j-1];
			}
			if(j == 0){
				kmp[i] = 0;
				i++;
			}else{
				kmp[i] = j + 1;
				i++;
				j++;
			}
		}
	}
	
	i = 0;
	j = 0;

	// For counting number of matches
	int count=0;

	// Iterate over to text to find patterns
	// O(N) Complexity (Run over text, N: Text length)
	while(i < text.size()){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			if(j >= 1){
				if(text[i] == pattern[kmp[j-1]]){
					i++;
					j++;
				}else{
					i++;
					j=0;
				}
			}else{
				i++;
			}
			
		}
		// If counting required, set j as follows. If not, return true for following block
		// indicating match found in text.
		if(j == pattern.size()){
			count += 1;
			j = kmp[j-1];
		}
	}
	// Print count of occurences of pattern in text
	cout<<count<<endl;
	return 0;
}

