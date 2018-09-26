#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
	if(a > b)
		return a;
	else 
		return b;
}


int LIS(vector<int> &vec){
	int ans[vec.size()+1][vec.size()+1];
	for(int i = 0; i <= vec.size(); i++)
		for(int j = 0; j <= vec.size(); j++)
			ans[i][j] = 0;
	for(int i = 1; i <= vec.size(); i++){
		for(int j = i; j <= vec.size(); j++){
			if(vec[i-1] > vec[j-1])
				ans[i][j] = ans[i - 1][j];
			else
				ans[i][j] = max(ans[i - 1][j], 1 + ans[i - 1][i]);
		}
	}
	return ans[vec.size()][vec.size()] - 1;
}

int main(){
	int n;
	cout<<"Input number of elements: \n";
	cin>>n;
	vector<int> g;
	for(int i = 0; i < n; i++){
		int temp;
		cin>>temp;
		g.push_back(temp);
	}
	g.push_back(0xFFFF);
	cout<<"Length of longest increasing subsequence is:"<<LIS(g);
	return 0;
}
