#include <iostream>
#include <vector>

int binary_search(const std::vector<int> vec, int guessNumber)
{
	int min = 0;
	int max = vec.size() - 1;
	while (min <= max)
	{
		int mid = (min + max) / 2;
		int currentGuess = vec[mid];
		if (currentGuess == guessNumber)
		{
			return mid;
		}
		if (currentGuess > guessNumber)
		{
			max = mid - 1;
		}
		else if (currentGuess < guessNumber)
		{
			min = mid + 1;
		}
	}
	std::cout << "Not found ";
	return -1;
}
int main()
{
	std::vector<int> vec = { 5,6,7,8,9,10 };
	std::cout << binary_search(vec, 8) << std::endl;
	std::cout << binary_search(vec, 2) << std::endl;
}
