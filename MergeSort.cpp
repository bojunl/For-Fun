#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> vec1, vector<int> vec2){
	vector<int> nvec;
	while(vec1.size() > 0){
		if(vec2.size() > 0){
			if(vec1[0] < vec2[0]){
				nvec.push_back(vec1[0]);
				vec1.erase(vec1.begin());
			}
			else{
				nvec.push_back(vec2[0]);
				vec2.erase(vec2.begin());
			}
		}
		else{
			nvec.push_back(vec1[0]);
			vec1.erase(vec1.begin());
		}
	}
	if(vec2.size() > 0)
		for(int i = 0; i < vec2.size(); i++)
			nvec.push_back(vec2[i]);
	return nvec;
}

vector<int> mergesort(vector<int> k){
	if(k.size() == 1)
		return k;
	else if(k.size() == 2){
		if(k[0] > k[1]){
			int tp = k[0];
			k[0] = k[1];
			k[1] = tp;
		}
		return k;
	}
	else{
		vector<int> vt1(k.begin(), k.begin() + k.size() / 2);
		vector<int> vt2(k.begin() + k.size() / 2, k.end());
		return merge(mergesort(vt1), mergesort(vt2));
	}
}



int main(){
	vector<int> g;
	int n, temp;
	cout<<"Input number of elements:\n";
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>temp;
		g.push_back(temp);
	}
	vector<int> ans;
	ans = mergesort(g);
	cout<<"Sorted Numbers: \n";
	for(int i = 0; i < n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
