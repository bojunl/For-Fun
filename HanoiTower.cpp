#include <iostream>

using namespace std;

int hanoi(int n, char sor, char temp, char des){
	int step = 0;
	if(n > 0){
		step += hanoi(n - 1, sor, des, temp);
		step ++;
		cout<<"Move disk "<<n<<" from "<<sor<<" to "<<des<<"\n";
		step += hanoi(n - 1, temp, sor, des);
		return step;
	}
	else 
		return 0;
}


int main(){
	int k, ans;
	cout<<"Input tower height:\n";
	cin>>k;
	ans = hanoi(k, 'A', 'B', 'C');
	cout<<"Need "<<ans<<" steps\n";
	return 0;
}
