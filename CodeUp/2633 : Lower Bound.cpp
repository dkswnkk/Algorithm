#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n,k; cin>>n>>k;
    vector<int>v;
    
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    
    int start=0, end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid]<k) start=mid+1;
        else end=mid-1;;
    }
    
    cout<<start+1;
}
