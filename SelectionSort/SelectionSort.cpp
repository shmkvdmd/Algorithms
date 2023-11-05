#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int smallestIndex(const std::vector<int> vec)
{
    int smallest_num = vec[0];
    int smallest_index = 0;
    for (size_t i = 0; i != vec.size(); ++i)
    {
        if (smallest_num > vec[i])
        {
            smallest_num = vec[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

std::vector<int> selection_sort(const std::vector<int> vec)
{
    std::vector<int> defaultVector = vec;
    std::vector<int> sortedVector;
    while (!defaultVector.empty())
    {
        int smallest_index = smallestIndex(defaultVector);
        sortedVector.push_back(defaultVector[smallest_index]);
        defaultVector.erase(defaultVector.begin() + smallest_index);
    }
    return sortedVector;
}

int main()
{
    std::vector<int> vec = { 50,2,7,1230,0,33 };
    std::vector<int> sortedVec = selection_sort(vec);
    for (int num : sortedVec)
    {
        cout << num << " ";
    }
    cout << endl;
}
