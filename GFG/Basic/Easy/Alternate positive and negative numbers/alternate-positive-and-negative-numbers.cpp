//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    void rearrange(int arr[], int n) {
        vector<int> P;
        vector<int> N;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                N.push_back(arr[i]);
            } else {
                P.push_back(arr[i]);
            }
        }

        int start = 0;
        int end = 0;
        int k = 0;
        
        while (start < P.size() && end < N.size()) {
            arr[k++] = P[start++];
            arr[k++] = N[end++];
        }

        while (start < P.size()) {
            arr[k++] = P[start++];
        }

        while (end < N.size()) {
            arr[k++] = N[end++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends