//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
public:
    
    int doUnion(int a[], int n, int b[], int m)  {
       unordered_set<int> Hash;
        
        for(int i=0;i<n;i++){
            Hash.insert(a[i]);
        }
         for(int i=0;i<m;i++){
            Hash.insert(b[i]);
        }
        return Hash.size();
        
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends