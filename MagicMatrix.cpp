#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>

using namespace std;

int main()
{
	int i, j, l, line[3][3] = {{4, 3, 8},{9, 5, 1},{2, 7, 6}};
	vector<vector<int> > ref(3);
	for(i = 0; i < 3; i++)
		ref[i].resize(3);
	vector<vector<vector<int> > > g(8);
	for(i = 0; i < 8; i++){
		g[i].resize(3);
		for(j = 0; j < 3; j++){
			g[i][j].resize(3);
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			g[0][i][j] = line[i][j];
			g[1][j][i] = line[i][j];
			g[2][2-i][2-j] = line[i][j];
			g[3][2-j][2-i] = line[i][j];
			g[4][i][2-j] = line[i][j];
			g[5][2-j][i] = line[i][j];
			g[6][2-i][j] = line[i][j];
			g[7][j][2-i] = line[i][j];
		}
	}
	cout<<"input the matrix:\n";
	for(i = 0; i < 3; i++){
		cin>>ref[i][0]>>ref[i][1]>>ref[i][2];
	}
	int min_count = 1000, count; 
	for(i = 0; i < 8; i++){
		count = 0;
		for(j = 0; j < 3; j++){
			for(l = 0; l < 3; l++){
				count += abs(g[i][j][l] - ref[j][l]);
			}
		}
		if(count < min_count)
			min_count = count;
	}
/*
	for(i = 0; i < 8; i++){
		cout<<"\n\n";
		for(j = 0; j < 3; j++){
			for(l = 0; l < 3; l++){
				cout<<g[i][j][l]<<" ";
			}
			cout<<"\n";
		}
	}
*/
	cout<<min_count;
}
