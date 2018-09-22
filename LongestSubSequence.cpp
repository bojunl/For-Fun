#include <iostream>

using namespace std;

int a[10000];

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int longest(int last,int before,int length){
	if(last == 0)
		if(a[last] <= before)
			return length + 1;
		else 
			return length;
	else if(a[last] <= before)
		return max(longest(last - 1, a[last], length + 1), longest(last - 1, before, length));
	else 
		return max(longest(last - 1, before, length), longest(last - 1, a[last], 1));
}




int main(){
	
	int n;
	cout<<"Input number of elements:\n";
	cin>>n;
	cout<<"Input the sequence:\n";
	for(int i = 0; i < n; i++)
		cin>>a[i];
	cout<<longest(n-1, 0xFFFFFFFF, 0);
	return 0;
}
