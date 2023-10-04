#include <iostream>
#include <ctype.h>
#include <stdio.h>
const int N = 1000;
void completion(double arr[N], int n) {
	std::cout << "Enter elements \n";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		
	}
	return;
}
void sum(double arr[N], int n, double sum1) {
	for (int i = 1; i < n; i = 2 * i + 1)
	{
		sum1 += arr[i];
	}
	std::cout << "Asddition result = " << sum1 << '\n';
	return;
}
void newarr(double arr[N], int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 1 && arr[i] > -1)
		{
			arr[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] == 0)
			{
				arr[j] = arr[j + 1];
				arr[j + 1] = 0;
			}
		}
	}
	std::cout << "array = ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
}
void composition(double arr[N], int last, int first, int n, int temp, int p,double composition1) {
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0) {
			p++;
		}
	}
	for (int i = 0; i < n; ++i)
	{

		if (arr[i] < 0) {
			last = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0) {
			first = i;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] < 0 && arr[i + 1] < 0)
		{
			temp = 1;

		}
	}
	if (temp == 1 && p < 2)
	{
		std::cout << "Composition error \n";
	}
	else {
		for (int i = first + 1; i < last; ++i)
		{
			composition1 *= arr[i];
		}
		std::cout << "Composition result = " << composition1 << '\n';
	}
}
void random(int first0, int last0, double arr[N], int n) {
	std::cout << "indicate boundaries from = ";
	std::cin >> first0;
	std::cout << "before = ";
	std::cin >> last0;
	if (first0 >= last0) {
		std::cout << "incorrect range";
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			arr[i] = rand() % (last0 - first0) + first0;
		}
	}
}
void is_digit(double arr[N], int i, int n) {

}
int main()
{
	double arr[N];
	double sum1 = 0, composition1 = 1;
	int n = 0, p = 0, temp = 0;
	int op;
	int first = 0, last = 0;
	int first0 = 0, last0 = 0;
	std::cout << "Enter the number of array elements \n";
	std::cin >> n;
	if (n > N) {
		std::cout << "The number must be less than 10000";
	}
	else {
		std::cout << "If you want to fill the array automatically, enter (0) and specify the bounds, otherwise enter (1) and fill the array \n";
		std::cin >> op;
		switch (op)
		{
		default:
			std::cout << " 0 and 1 !!!!";
			break;
		case 0:random (first0, last0, arr, n);
				sum(arr, n, sum1);
				composition(arr, last, first, n, temp, p, composition1);
				newarr(arr, n);
				break;
		case 1:
			completion(arr, n);
			sum(arr, n, sum1);
			composition(arr, last, first, n, temp, p, composition1);
			newarr(arr, n);
			break;
			}
			return 0;
		}
	}
