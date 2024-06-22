#include<bits/stdc++.h>

using namespace std;

vector<int> arr[10001];

vector<int> prime;

vector<int> visited;
vector<int> dist;

bool isValid(int i,int j){
	int a = prime[i] , b = prime[j];
	int cnt = 0;
	while(a){
		if(a%10!=b%10){
			cnt++;
		}
		a /=10;
		b/=10;
	}
	
	return cnt==1;
}

bool isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	
	return true;
}

void builtGraph(){
	for(int i=1001;i<9999;i++){
		if(isPrime(i)){
			prime.push_back(i);
		}
	}
	
	for(int i=0;i<prime.size();i++){
		for(int j=i+1;j<prime.size();i++){
			if(isValid(i,j)){
				arr[prime[i]].push_back(prime[j]);
				arr[prime[j]].push_back(prime[i]);
			}
		}
	}
}

void dfs(int a){
	visited[a] = 1;
	dist[a] = 0;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int child : arr[curr]){
			if(visited[child]==0){
				dist[child] = dist[curr] + 1;
				visited[child] = 1;
				q.push(child);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	builtGraph();
	while(t--){
		int a,b;
		cin>>a>>b;
		visited.clear();
		visited.resize(10001,0);
		dist.clear();
		dist.resize(10001,-1);
		
		if(dist[b]==-1){
			cout<<"Impossible\n";
		}
		else{
			cout<<dist[b]<<endl;
		}
		
		
	}
	
	
	return 0;
}
