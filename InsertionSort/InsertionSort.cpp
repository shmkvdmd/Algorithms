#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& vec){
    for(size_t i = 0; i != vec.size(); ++i){
        int j = i;
        while (j >= 0 && vec[j - 1] > vec[j]){
            std::swap(vec[j - 1], vec[j]);
            --j;
        }
    }
}

void PrintVector(std::vector<int> vec){
    std::cout << std::endl;
    for (const auto& elem : vec){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec{5,2,4,6,1,3};
    InsertionSort(vec);
    PrintVector(vec);
}