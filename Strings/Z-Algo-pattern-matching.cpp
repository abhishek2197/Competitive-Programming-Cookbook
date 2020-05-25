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

void compute_Z_values(vector<int> &Z, string Zstr){
    // First index irrelevant (Put 0)
    Z[0] = 0;

    // Left and right pointers for identifying Z window
    int left = 0;
    int right = 0;

    for(int i = 0; i < Zstr.size(); i++){
        // Check if index is within right to make use of computed values
        if(i > right){
            left = i;
            right = i;
            // Increment right till we find same characters as prefix
            while(right < Zstr.size() && Zstr[right] == Zstr[right - left]){
                right += 1;
            }
            // Store the length of matching prefix as Z value at index i
            Z[i] = right - left;

            // Decrement right by 1 
            right -= 1;

        }else{
            // Now we use the computed Z values and copy them to current window
            int window_start = i - left;
            int window_end = right;
            int window_len = window_end - i + 1;
        
            // If the Z value at index less than window length, copy as it is,
            // Else start calculating the Z value as done above for the window that exceeds
            // the right bound (window length).

            if (Z[window_start] < window_len){
                Z[i] = Z[window_start];
            }else{
                left = i;
                // Increment right till we find same characters as prefix
                while(right < Zstr.size() && Zstr[right] == Zstr[right - left]){
                    right += 1;
                }
                // Store the length of matching prefix as Z value at index i
                Z[i] = right - left;

                // Decrement right by 1 
                right -= 1;
            }
        }
    }

}

int main() {
	// your code goes here
	fastio;
	string pattern,text;
	cin >> pattern >> text;

    // Create a new Z string of form (pattern + special_char + text)
    string Zstr = "";

    // Add pattern to Z string
    for(int i = 0; i < pattern.size(); i++){
        Zstr += pattern[i];
    }

    // Add special character not present in pattern or text
    Zstr += '$';

    // Add text to Z string
    for(int i = 0; i < text.size(); i++){
        Zstr += text[i];
    }

	// For each index in z array store the largest substring
    // starting from the index that matches the prefix
	vector<int>Z(pattern.size()+text.size()+1);

    // Compute Z values
    compute_Z_values(Z, Zstr);
    
    // Find number of indexes with matching length of pattern
    // which is equivalent to the occurences of pattern in text

    // For counting occurences of pattern in text
    int count = 0;

    for(int i = 0; i < Z.size(); i++){
        // Match found
        if(Z[i] == pattern.size()){
            count += 1;
        }
    }

    // Print count of occurences
	cout<<count<<endl;

	return 0;
}

// Time Complexity: O(N+M)
// Space Complexity: O(N+M)
