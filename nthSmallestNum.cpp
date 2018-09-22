#include <iostream>
#include <vector>

using namespace std;

int quickselect(int arr[], int low, int high, int target){
	int pivot = high;
	int pos = low - 1;
	if(low < high){
		for(int i = low; i < high; i++){
			if(arr[i] <= arr[pivot]){
				pos++;
				int temp = arr[pos];
				arr[pos] = arr[i];
				arr[i] = temp;
			}
		}
		int tp = arr[pivot];
		arr[pivot] = arr[pos + 1];
		arr[pos + 1] = tp;
		if(pos + 1 == target)
			return arr[pos + 1];
		else if(target <= pos)
			return quickselect(arr, low, pos, target);
		else
			return quickselect(arr, pos + 2, high, target);
	}
}


int main(){
	int n, order;
	cout<<"Input number of elements:\n";
	cin>>n;
	int arr[n];
	cout<<"Want to select which number: \n";
	cin>>order;
	cout<<"Input all the elements: \n";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<quickselect(arr,0,n-1,order);
	
	
	return 0;
}
