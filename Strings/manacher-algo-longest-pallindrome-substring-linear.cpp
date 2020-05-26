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
	cin>>text;

	// create a new string with special char between every two char including start and end
    string manacher_str = "";
    for(int i = 0; i < text.size(); i++){
        manacher_str += '#';
        manacher_str += text[i];
    }
    manacher_str += '#';

    // create lps array to store longest pallindrome substring around every index as center
    vector<int>lps(manacher_str.size());

    int center = 0;
    int right = 0;

    for(int i = 1; i < manacher_str.size() - 1; i++){
        // Find mirror character (other side of center)
        int mirror_char = center - (i - center);

        // Check if the current index within current pallindrome window ( i < right )
        if(right > i){
            // Check if the lps computed at mirror index extends beyond the window
            // If yes, set lps[i] = right - i, (As that is the minimum possible expansion)
            // Else, all within window, copy the lps[mirror_char]
            lps[i] = min(right - i, lps[mirror_char]);
        }

        // Run expansion from the minimum possible value computed above (lps[i])
        int expand_right = i + lps[i] + 1;
        int expand_left = i - lps[i] - 1;

        while((manacher_str[expand_right] == manacher_str[expand_left]) && expand_right < manacher_str.size() && expand_left >= 0){
            expand_left -= 1;
            expand_right += 1;
            lps[i] += 1;
        }

        // Update center and right limit if the length expands beyond current pallindrome (>r)
        if(i + lps[i] > right){
            right = i + lps[i];
            center = i;
        }
    }

    // Find the index with the longest pallindrome substring and the length
    int max_lps = 0;
    int max_lps_center = 0;

    for(int i = 1; i < lps.size() - 1; i++){
        if(lps[i] > max_lps){
            max_lps = lps[i];
            max_lps_center = i;
        }
    }

    // Print length of longest pallindrome substring
    cout << max_lps << endl;

    // Print the longest pallindrome substring from original given text
    cout << text.substr((max_lps_center - max_lps)/2, max_lps) << endl;
	return 0;
}

// Total Comparisons: 2*N
// Time Complexity: O(N)
