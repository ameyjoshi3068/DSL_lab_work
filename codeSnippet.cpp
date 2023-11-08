/*author ~ pSydak*/

#include<bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 

  

#include<functional>



using namespace __gnu_pbds;

using namespace std;



#define LOCAL 1



#define pb push_back

#define ppb pop_back

#define ff first

#define ss second

#define scin(s) getline(cin,s)

#define sz(x) int((x).size())

#define all(x) (x).begin(),(x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define endl '\n'

#define pii pair<int,int>

#define plli pair<long long int, long long int>

#define ll long long int 

#define ull unsigned long long int

#define lld long double 

#define pi 3.1415926535897932384626433832795

#define parity(x) __builtin_parityll(x)

#define set_bits(x) __builtin_popcountll(x)

#define trail_z(x) __builtin_ctzll(x)

#define lead_z(x) __builtin_clzll(x)

#define tst unsigned int test=1; scanf("%u", &test); while(test--)

#define fill_v(vect,n) for(int i=0 ; i<n ; i++){cin>>vect[i];}

#define fill_a(arr,n) for(int i=0 ; i<n ; i++){cin>>arr[i];}

#define mk(type,arr,size) auto arr = std::make_unique<type[]>(size)

#define set_pre(num,deci) fixed<<setprecision(deci)<<num 

#define pneumonoultramicroscopicsilicovolcanoconiosis() ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(__null)

#define mx(v) *max_element(all(v))

#define mn(v) *min_element(all(v))

#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())))



// template<typename Key,typename Mapped,typename Cmp_Fn = std::less<Key>,typename Tag = rb_tree_tag,template<typename Const_Node_Iterator,typename Node_Iterator,typename Cmp_Fn_,typename Allocator_>class Node_Update = null_node_update,typename Allocator = std::allocator<char>> class tree;



#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// typedef tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

// typedef tree<ll , null_type, less<ll> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;

// Whenever possible, use a pair<int,int> ordered_set instead of using an ordered_multiset for it to remain highly functional as a PBDS.



#pragma GCC optimize("Ofast,unroll-loops") 

#pragma GCC target("avx,avx2,fma")

const int dx[4] = {-1, 1, 0, 0};

const int dy[4] = {0, 0, -1, 1};

const int XX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

const int YY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const long long int inf = 2e18;

const long long int mdx = 1e9 + 7;

const int N = 6e5;

const int bitscount = 32;



template<class T> void Tmax(T & a, const T & b) { a = max(a, b); } 

template<class T> void Tmin(T & a, const T & b) { a = min(a, b); } 



#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif



void _print(long long t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(long double t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(unsigned long long t) {cerr << t;}



template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



/*Sieve-Of-Eratothenes*/

const long long int _n = 1e6+5;

vector<int> _b(_n+1,1);

vector<ll> _pr; 

vector<plli> primeDivisors(ll n){vector<plli> _pdiv;for(ll i=0 ; 1LL*(_pr[i]*_pr[i])<=n ; i++){if(n%_pr[i]==0){ll k=0;while(n%_pr[i]==0){n/=_pr[i];k+=1;}_pdiv.pb({_pr[i],k});}}if(n!=1)_pdiv.pb({n,1});return _pdiv;}

void sieve(){_b[0]=_b[1]=0; for(ll i=2 ; i<=sqrtl(_n) ; i++) {if(_b[i]==1 && 1LL*(i*i)<=_n){_pr.pb(i); for(ll j=i*i ; j<=_n ; j+=i) {_b[j]=0;}}}}

bool isPrime(ll N){if(N<=_n) return bool(_b[N]); else{for(ll i=0; (_pr[i]*_pr[i])*1LL<=N ; i++){if(N%_pr[i]==0) return false;} return true;}}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

/* mathematics */

bool is_prime(ll n) {if (n == 1) {return false;}ll i = 2;while (i*i <= n) {if (n % i == 0) {return false;}i += 1;}return true;}

ll gcd(ll a, ll b) {return __gcd(a,b);}

ll lcm(ll a, ll b){return ((a*b)/gcd(a,b));}

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendedgcd(ll a, ll b, vector<ll> &v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendedgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll mminv(ll a, ll m) {vector<ll> arr(3); extendedgcd(a, m, arr); return (gcd(a,m)==1 ? (arr[0]%m + m)%m : -1);}

ll mminvprime(ll a, ll m) {return (gcd(a,m)==1 ? (expo(a, m - 2, m)%m + m)%m : -1);}

ll ncrModp(ll n, ll r, ll p){if(n<r) return 0;if(r==0) return 1;ll fac[n+1];fac[0]=1;for(int i=1 ; i<=n ; i++){fac[i]=(fac[i-1]*i)%p;}return (fac[n]*mminvprime(fac[r],p)%p*mminvprime(fac[n-r],p)%p)%p;}

ll nfactModp(ll n, ll p){if (n >= p) return 0;ll result=1ll;for(ll i=1ll; i<=n; i++)result=(result*1ll*i) % p;return result%p;}

ll inv_nfactModp(ll n, ll p){return mminvprime(nfactModp(n,p),p)%p;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

ll phin(ll n) {ll phi_n = n; if (n % 2 == 0) {phi_n /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0) n /= i; phi_n = (phi_n / i * (i - 1));}} if (n > 1)phi_n = (phi_n / n * (n - 1)) ; return phi_n;}

ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

vector<ll> primeFactors(ll n) {vector<ll> ans;while (n % 2 == 0) {ans.pb(2); n /= 2;}for (ll i = 3; i *1ll* i <= n; i += 2) {while (n % i == 0) {ans.pb(i); n /= i;}}if (n > 2)ans.pb(n); return ans;}

/*dec-bin*/

string binary(ll x){string s; s=bitset<32>(x).to_string() ; return s;}

unsigned ll decimal(string s){unsigned ll x; x=bitset<32>(s).to_ulong() ; return x;}

/*misc.*/

bool powerOf_2_orNot(ll n){if (n == 0)return false;return (ceil(log2(n)) == floor(log2(n)));}

int mex(vector<int> &arr, int N){sort(arr.begin(), arr.end());int mex = 0;for (int idx = 0; idx < N; idx++){if (arr[idx] == mex){mex += 1;}}return mex;}

int isSubstring(string s1, string s2){if (s2.find(s1) != string::npos)return s2.find(s1);return -1;}

bool isVowel(char ch){return (0x208222 >> (ch & 0x1f)) & 1;}

string coin_toss(){srand(time(0)); if(rand()%2==0) return "Tails"; else return "Heads";}

vector<string> generate_string_Subsequences(string s){vector<string> v; for(int i=0 ; i<s.length() ; i++) for(int l=1 ; l<=s.length()-i ; l++) v.pb(s.substr(i,l)); return v;}

vector<vector<int>> generateSubsequences(const vector<int>& nums) { vector<vector<int>> subs; for(int i = 0; i < (1 << nums.size()); ++i) if(i) { vector<int> sub; for(int j = 0; j < nums.size(); ++j) if(i & (1 << j)) sub.push_back(nums[j]); subs.push_back(sub); } return subs; }

/*Range-OR*/

int prefix_count[bitscount][N];

void findPrefixCount(vector<int> &arr, int n){for (int i = 0; i < bitscount; i++) {prefix_count[i][0] = ((arr[0] >> i) & 1);for (int j = 1; j < n; j++) {prefix_count[i][j] = ((arr[j] >> i) & 1);prefix_count[i][j] += prefix_count[i][j - 1];}}}

int rangeOr(int l, int r){int ans = 0;for (int i = 0; i < bitscount; i++) {int x;if (l == 0)x = prefix_count[i][r];else x = prefix_count[i][r]- prefix_count[i][l - 1];if (x != 0)ans = (ans | (1 << i));}return ans;}

int rangeAnd(int l, int r){int ans = 0;for (int i = 0; i < bitscount; i++) {int x;if (l == 0)x = prefix_count[i][r];else x = prefix_count[i][r]- prefix_count[i][l - 1];if (x == r - l + 1)ans = (ans | (1 << i));}return ans;}

/*x*/

bool isPalindrome(string S){for (int i = 0; i < S.length() / 2; i++){if (S[i] != S[S.length() - i - 1]){return 0;}}return 1;}

bool isSmaller(string str1, string str2){int n1 = str1.length(), n2 = str2.length();if (n1 < n2)return true;if (n2 < n1)return false;for (int i = 0; i < n1; i++) {if (str1[i] < str2[i])return true;else if (str1[i] > str2[i])return false;}return false;}

string strSub(string str1, string str2){if (isSmaller(str1, str2))swap(str1, str2);string str = "";int n1 = str1.length(), n2 = str2.length();int diff = n1 - n2;int carry = 0;for (int i = n2 - 1; i >= 0; i--) {int sub = ((str1[i + diff] - '0') - (str2[i] - '0')- carry);if (sub < 0) {sub = sub + 10;carry = 1;}else carry = 0;str.push_back(sub + '0');}for (int i = n1 - n2 - 1; i >= 0; i--) {if (str1[i] == '0' && carry) {str.push_back('9');continue;}int sub = ((str1[i] - '0') - carry);if (i > 0 || sub > 0) str.push_back(sub + '0');carry = 0;}reverse(str.begin(), str.end());return str;}

bool isPerfectSquare(ll n) {ll root = sqrtl(n);return (root * 1ll * root == n);}

bool isFibonacci(int n) {if (n == 0) {return true;}int a = 0, b = 1, c = 1;while (c < n) {a = b;b = c;c = a + b;}return (c == n || isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4));}

int bit_sz(ll n){int cnt=0; while(n){if(n&1) cnt++; n>>=1;} return cnt;}

bool isSubsequence(string& s1, string& s2){int n = s1.length(), m = s2.length();int i = 0, j = 0;while (i < n && j < m) {if (s1[i] == s2[j])i++;j++;}return i == n;}

vector<string> generatePermutations(string s){vector<string> ans;sort(all(s));do {ans.pb(s);} while (next_permutation(all(s)));return ans;}

//returns true if s1 is a subsequence of s2

/*x*/

// always try to design the solution of recursion problems by the optimal recursion tree 

// think of dp and recurison problems only in terms of indexes

// try thinking recurison/dp in top-down manner

// we can calculate the number of subarrays on the basis of some constraint on the starting or the ending element	

void solve() {

	//number of ways - codeforces 466C ; honed my implementation skills alot, but will get tle.

	//466C requires some thinking and maths but thats it.



	int n,k;

	cin>>n>>k;



	//f(x)=(x%k).((n-x)%k) V x=[0,N]



	ll x1=(n%k)/2, x2=(n%k + k)/2,fx1,fx2;

	fx1=(x1%k)*1ll*((n-x1)%k);

	fx2=(x2%k)*1ll*((n-x2)%k);

    

    if(fx2>=fx1){

        cout<<x2<<endl;

    }

    else{

        cout<<x1<<endl;

    }

}	



int main(int argc, char **argv) {



	#ifndef ONLINE_JUDGE

	freopen("Error.txt", "w", stderr);

	#endif



	pneumonoultramicroscopicsilicovolcanoconiosis();

	#if LOCAL

		tst{

			solve();

		}

	#endif



}
