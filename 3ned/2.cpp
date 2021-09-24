#include <iostream>

void mergef(int arr[100], int l, int r)
{
	int m = (l + r) / 2;
	int i = l;
	int j = m + 1;
	int k = l;
	int temp[100];

	while ((i <= m) && (j <= r))
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	
	while (i <= m)
	{
		temp[k++] = arr[i++];
	}

	while (j <= r)
	{
		temp[k++] = arr[j++];
	}
	
	for(int i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(int arr[100], int l, int r)
{
	if (l >= r) {return;}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, (m + 1), r);
	mergef(arr, l, r);		
}

int main()
{
	std::cout << "Введите количество элементов массива:" << std::endl;
	int n = 0;
	std::cin >> n;
	std::cout << "Введите элементы массива:" << std::endl;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		std::cin >> x;
		arr[i] = x;
	}
	int l = 0;
	int r = n - 1;
	mergeSort(arr, l, r);	

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}
