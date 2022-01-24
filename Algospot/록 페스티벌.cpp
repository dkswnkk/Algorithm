#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T—){
        int N,L; cin>>N>>L;
        vector<double>v(N);
        for(int i=0; i<N; i++) cin>>v[i];
        
        double ans = 1e9;
        
        for(int i=0; i<N; i++){
            double temp = 0,cnt= 0;
            for(int k=i; k<N; k++){
                cnt++;
                temp+=v[k];
                if(cnt>=L) ans = min(ans,(temp/cnt));
            }
        }
        cout<<fixed;
        cout.precision(8);
        cout<<ans<<'\n';
    }
}
