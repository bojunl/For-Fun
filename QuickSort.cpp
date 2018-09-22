#include <iostream>
#include <vector>

using namespace std;


void quicksort(int arr[], int low, int high){
	int pivot = low;
	int pos = high + 1;
	if(low < high){
		for(int i = high; i > low; i--){
			if(arr[i] > arr[pivot]){
				pos--;
				int tp = arr[i];
				arr[i] = arr[pos];
				arr[pos] = tp;
			}
		}
		int tp1 = arr[pivot];
		arr[pivot] = arr[pos - 1];
		arr[pos - 1] = tp1;
		quicksort(arr, low, pos - 2);
		quicksort(arr, pos, high);	
	}	
} 

int main(){
	int n, temp;
	cout<<"Input number of elements: \n";
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	quicksort(arr, 0, n - 1);
	cout<<"Sorted elements:\n";
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
