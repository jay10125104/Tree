#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define for0(i,n) for(long long int i=0;i<n;i++)
#define vi vector<long long int>
#define pb push_back
#define sz(x) sizeof(x)
#define vec(n,x) vector<long long int>v(n,x)
const ll INF = 1e18;
const ll MOD = 1000000007;
#define hi  ll tests; cin>>tests; while(tests--)
#define all(x) x.begin(),x.end()
#define readv(vec) for(auto &x:vec){cin>>x;}
#define PHI M_PI
#define graph long long int V;cin>>V;vector<long long int>adj[V];long long int e;for(long long int i=0;i<e;i++){long long int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
#define printv(vec) for(auto x:vec){cout<<x<<' ';}cout<<endl;
#define sortasc(vec) sort(all(vec));
#define sortdes(vec) sort(vec.rbegin(),vec.rend());
#define  setpre(x)   cout<<fixed<<setprecision(10)<<x<<endl
#define kick cout <<'C'<<'a'<<'s'<<'e'<<' '<<'#'<< k << ':'<<' '
vector<ll> sieve(long long int n) {long long int*arr = new long long int[n + 1](); vector<ll> vect; for (long long int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (long long int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool pal(string s){long long int i = 0;long long int j = s.size() - 1;while (i < j){if (s[i] != s[j]){return false;}i++;j--;}return true;}
ll op1(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll op2(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll op3(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
long long int powerexpo(long long int x,long long int y,long long int p){long long int res = 1;x = x % p; if (x == 0) return 0;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1;x = (x*x) % p;}return res;}
ll C(ll a , ll b) { return (a+b-1)/b ;}
ll crt(ll n){ll start=1;ll end = 8000000;ll sol = -1;while(start<=end){ll mid = (start+end)/2;ll k = mid*mid*mid;if(k<=n){start=mid+1;sol = mid;}else{end = mid-1;}}return sol;}
struct unionfind{
long long int n;
vector<long long int>rank;
vector<long long int>parent;
unionfind(long long int n){
rank.resize(n);
fill(rank.begin(),rank.end(),0);
parent.resize(n);
for(long long int i=0;i<n;i++){
parent[i]=i;
}}
long long int find(long long int node){if(node==parent[node]){return node;}else{return parent[node] = find(parent[node]);}}
bool Union(long long int u,long long int v){u = find(u);v = find(v);if(u==v){return false;}if(rank[u]<rank[v]){parent[u] = v;}else if(rank[u]>rank[v]){parent[v]=u;}else{parent[v]=u;rank[u]++;}return true;}};
//code by CasioFx-69
long long int timer=0;
long long int start[200001];
long long int ending[200001];
long long int linear[200004];
struct seg
{
    vector<long long int> tree;
    vector<long long int> lazy;
    vector<long long int>v;
    seg(vector<long long int>&vii)
    {
        v=vii;
        long long int n=v.size();
        vector<long long int> dummy1(4 * n);
        vector<long long int> dummy2(4 * n);
        tree = dummy1;
        lazy = dummy2;
    }
    void build(long long int node,long long int start,long long int end){
        if(start==end){
            tree[node]=v[start];
        }
        else{
            long long int mid=(start+end)/2;
            build(node*2,start,mid);
            build(node*2+1,mid+1,end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void propogate(long long int node, long long int start, long long int end)
    {
        if (start == end)
        {
            tree[node] += lazy[node];
            lazy[node] = 0;
        }
        else
        {
            tree[node] += ((end - start + 1) * lazy[node]);
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void update(long long int node, long long int start, long long int end, long long int l, long long int r, long long int x)
    {
        propogate(node, start, end);
        if (start > r || end < l)
        {
            return;
        }
        if (start == end)
        {
            tree[node] += x;
        }
        else if (l <= start && end <= r)
        {
            lazy[node] += x;
            propogate(node, start, end);
        }
        else
        {
            long long int mid = (start + end) / 2;
            update(node * 2, start, mid, l, r, x);
            update(node * 2 + 1, mid + 1, end, l, r, x);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    long long int query(long long int node, long long int start, long long int end, long long int l, long long int r)
    {
        if (start > r || end < l)
        {
            return 0;
        }
        propogate(node,start,end);
        if (start == end)
        {
            return tree[node];
        }
        else if (start >= l && end <= r)
        {
            return tree[node];
        }
        else
        {
            long long int mid = (start + end) / 2;
            long long int left = query(node * 2, start, mid, l, r);
            long long int right = query(node * 2 + 1, mid + 1, end, l, r);
            return left + right;
        }
    }
};
void dfs(vector<long long int>adj[],long long int src,long long int parent){
    start[src] = ++timer;
    for(auto &it:adj[src]){
        if(it!=parent){
            dfs(adj,it,src);
        }
    }
    ending[src] = timer;
    // linear[timer++]=v[src];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    long long int q;
    cin>>q;
    vector<long long int>v(n);
    readv(v);
    vector<long long int>adj[n];
    timer=-1;
    memset(start,0,sizeof(start));
    memset(ending,0,sizeof(ending));
    memset(linear,0,sizeof(linear));
    for(long long int i=0;i<n-1;i++){
        long long int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,0,-1);
    vector<long long int>t(timer+1);
    for(long long int i=0;i<n;i++){
        t[start[i]]=v[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<start[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<ending[i]<<" ";
    // }
    seg s=seg(t);
    n=t.size();
    s.build(1,0,n-1);
    while(q--){
        long long int x,y;
        cin>>x;
        if(x==1){
            long long int node,value;
            cin>>node>>value;
            node--;
            s.update(1,0,n-1,start[node],start[node],-v[node]+value);
            // s.update(1,0,n-1,ending[node],ending[node],-v[node]+value);
            v[node]=value;
        }
        else{
            long long int x;
            cin>>x;
            x--;
            cout<<s.query(1,0,n-1,start[x],ending[x])<<endl;
        }
    }
     return 0;
}
