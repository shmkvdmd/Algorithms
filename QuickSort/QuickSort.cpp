#include <iostream>
#include <vector>

using std::cout;

std::vector<int> quicksort(const std::vector<int>& vec)
{
	if (vec.size() < 2)
		return vec;
	int middle_value = vec[vec.size() / 2];
	std::vector<int> less_values;
	std::vector<int> greater_values;
	for (int number : vec)
	{
		if (number == middle_value) continue;
		if (number < middle_value) less_values.push_back(number);
		else greater_values.push_back(number);
	}
	std::vector<int> less_sorted = quicksort(less_values);
	std::vector<int> greater_sorted = quicksort(greater_values);
	less_sorted.push_back(middle_value);
	less_sorted.insert(less_sorted.end(), greater_sorted.begin(), greater_sorted.end());
	return less_sorted;
}

int main()
{
	std::vector<int> vec = { 69, 60, 38, 82, 99 };
	std::vector<int> sorted_vec = quicksort(vec);
	for (int num : sorted_vec)
	{
		cout << num << " ";
	}
}
