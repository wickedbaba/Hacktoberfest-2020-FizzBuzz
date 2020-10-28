
#include<bits/stdc++.h>
 #define ll  long long int
using namespace std;


void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {


	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}


void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}


int main(){
ll m,n,i,j,t;
int a;
cin >> t;

for(i=0;i<t;i++){
    cin >> n;
    vector<int>v;
        for(j=0;j<n;j++){
            cin>>a;
            v.push_back(a);
        }


    MergeSort(v, 0, n - 1);



    for(j=0;j<n;j=j+3){
            m=v[j];
            if(m!=v[j+1] || m!=v[j+2])
                 break;
        }
    cout << m<<endl;

}

return 0;
}
