// Recursive Fizzbuzz in C++
// Author: yadav-aman

#include<iostream>

int fizz(int n){
    if (n==101)
        return 0;
    if (n%3 == 0 && n%5 == 0)
        std::cout<<"FizzBuzz ";
    else if (n%5 == 0)
       std::cout<<"Buzz ";
    else if (n%3 == 0)
       std::cout<<"Fizz ";
    else
        std::cout<<n<<" ";
    return fizz(n+1);
}

int main(){
    fizz(1);
    return 0;
}

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
