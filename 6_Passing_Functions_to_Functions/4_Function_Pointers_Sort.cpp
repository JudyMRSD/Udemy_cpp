//
// Created by Jin Zhu on 11/1/18.
//
#include <vector>
#include <iostream>
using namespace std;

//callback function
int compare(int a, int b){
    if(a>b) return 1;
    else return -1;
}
//bubble sort
void BubbleSort(vector<int>& A, int(*compare)(int, int)){
    int n = A.size();
    int i, j, tmp;
    for(i = 0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(compare(A[j], A[j+1])>0){//A[j] > A[j+1]
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}

int main(){
    int i;
    vector<int> A = {3,2,5};
    BubbleSort(A, compare);
    for(int i = 0; i<A.size(); i++){
        cout<<A[i];
    }
    cout<<endl;
}