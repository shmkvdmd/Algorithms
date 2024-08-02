#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& vec){
    for(size_t j = 1; j != vec.size(); ++j){
        int key = vec[j];
        int i = j - 1;
        while(i >= 0 && vec[i] > key){
            vec[i + 1] = vec[i];
            i = i - 1;
        }
        vec[i + 1] = key;
    }
}

int main(){
    std::vector<int> vec{5,2,4,6,1,3};
    InsertionSort(vec);
    for (const auto& elem : vec){
        std::cout << elem << " ";
    }
}