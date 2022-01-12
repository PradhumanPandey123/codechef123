////// JANUARY LONAG CHALLANGE/////

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
///////-----------------------------------------------------Mathematics-----------concepts///////////////////////////////////////////////////////////////
//// 1.countTrailingZeroes//////
//int countTrailingZeros(int n){int res = 0;for(int i=5; i<=n; i=i*5){res = res + (n / i);}return res;}
//////---------------------///////
///// 2.Eucleadian algorithm for hcf or gcd////////
//int gcd(int a,int b){while(a!=b){if(a>b)a=a-b;else b=b-a;return a;}
///////-------------------------////////
/////3.Prime aproach efficient///////
//int prime(int n)
////{if(n==1)return false;for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
/////----------------------------/////////
/////---------3.seive of erathosthenes-----------////////////
////void sieve(int n){if(n <= 1)return;bool isPrime[n+1];fill(isPrime, isPrime + n + 1, true);for(int i=2; i*i <= n; i++){
////if(isPrime[i]){for(int j = 2*i; j <= n; j = j+i){isPrime[j] = false;}}}for(int i = 2; i<=n; i++){if(isPrime[i])cout<<i<<" ";}}
////////----------------------------------------//////////////
///////---------------4.iterative power--------///////////////
//int power_recursive(int a,int n){if(n==0)return 1;int temp=power_recursive(a,n/2);temp=temp*temp;if(n%2==0)return temp;elsereturn temp*x;}
////////-------------------------------------///////////////
//Pradhuman pandey
// codechef problem----chef and riffles
// concept----graph,recursion,indexing,positioning
void solve();
void decompose(ll src,vector<bool>&vis,vector<ll>&cycle);
vector<int>nextposition;
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
void decompose(ll src,vector<bool>&vis,vector<ll>&cycle){
	if(vis[src])
	return;
	cycle.push_back(src);
	vis[src]=1;
	decompose(nextposition[src],vis,cycle);
}
void solve(){
	ll n,k;
	cin>>n>>k;
	ll index=1;
	nextposition.resize(n+1);
	for(ll i=1;i<=n;i+=2)nextposition[i]=index++;
	for(ll i=2;i<=n;i+=2)nextposition[i]=index++;
	
	vector<bool>visited(n+1);
	vector<ll>ans(n+1);
	for(ll i=1;i<=n;i++){
		vector<ll>cycle;
		decompose(i,visited,cycle);
		 for(ll j = 0; j <cycle.size(); j ++) {
                ans[cycle[(j + k) % cycle.size()]] = cycle[j];
            }
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
	cout<<endl;
}
