#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVec(const vector<int>& vec){
    for (const auto& elem : vec){
        cout << elem << " ";
    }
    cout << endl;
}

void Merge(vector<int>& vec, int first_num, int middle_num, int last_num){
    int n1 = middle_num - first_num + 1;
    int n2 = last_num - middle_num;
    vector<int> left_vec(n1), right_vec(n2);
    for(size_t i = 0; i != n1; ++i){
        left_vec[i] = vec[first_num+i];
    }
    for(size_t i = 0; i != n2; ++i){
        right_vec[i] = vec[middle_num + 1 +i];
    }
    int i = 0, j = 0;
    int k = first_num;
    while (i < n1 && j < n2){
        if(left_vec[i] <= right_vec[j]){
            vec[k] = left_vec[i];
            ++i;
        }
        else{
            vec[k] = right_vec[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        vec[k] = left_vec[i];
        ++i;
        ++k;
    }
    while(i < n2){
        vec[k] = right_vec[j];
        ++j;
        ++k;
    }
}
void MergeSort(vector<int>& vec, int first_num, int last_num){
    if(first_num >= last_num)
        return;
    int middle_num = first_num + ((last_num - first_num) / 2);
    MergeSort(vec, first_num, middle_num);
    MergeSort(vec, middle_num + 1, last_num);
    Merge(vec, first_num, middle_num, last_num);
}

int main(){
    vector<int> vec {6,5,3,1,8,7,2,4};
    PrintVec(vec);
    MergeSort(vec, 0, vec.size());
    PrintVec(vec);
}