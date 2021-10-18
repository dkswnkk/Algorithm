#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llll;
ll square(ll now) {
    return now*now;
}
ll gcd(ll a,ll b) {
    return b?gcd(b,a%b):a;
}
bool cmp(const llll& e1,const llll& e2) {
    return e1.first+e1.second < e2.first+e2.second;
}
int main() {
    set<llll> s;
    for ( ll y = 1 ; y < 500 ; y++ )
        for ( ll x = y+1 ; x < 500 ; x++ ) {
            ll a = 2*x*y,b = x*x-y*y,c = x*x+y*y;
            if ( square(a)+square(b) == square(c) ) {
                vector<ll> v;
                v.push_back(a);v.push_back(b);v.push_back(c);
                sort(v.begin(),v.end());
                ll now = gcd(v[0],gcd(v[1],v[2]));
                for ( int i = 0 ; i < 3; i ++ )
                    v[i] /= now;
                s.insert(llll(v[0],v[1]));
            }
        }
    vector<llll> v;
    for ( set<llll>::iterator it = s.begin();it!=s.end() ; it++ )
        v.push_back(llll(it->first,it->second));
    sort(v.begin(),v.end(),cmp);
    int tc;
    scanf("%d",&tc);
    while ( tc-- ) {
        ll L,ans=0;
        scanf("%lld",&L);
        for ( int i = 0 ; i < v.size() ; i++ ) {
            ll now = 2*(v[i].first+v[i].second);
            if ( L >= now ) {
                L -= now;
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
