//������ȸ ��� : 1 2 4 5 3 6 7 
//������ȸ ��� : 4 2 5 1 6 3 7
//������ȸ ��� : 4 5 2 6 7 3 1

#include <iostream>

void ����(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	std::cout << arr[idx] << ' ';
	����(arr, idx * 2);
	����(arr, idx * 2 + 1);
}
void ����(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	
	����(arr, idx * 2);
	std::cout << arr[idx] << ' ';
	����(arr, idx * 2 + 1);
}
void ����(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	
	����(arr, idx * 2);
	����(arr, idx * 2 + 1);
	std::cout << arr[idx] << ' ';
}

int main()
{
	using namespace std;

	int binaryTree[8]{ 0,1,2,3,4,5,6,7 };

	����(binaryTree);
	cout << endl;
	����(binaryTree);
	cout << endl;
	����(binaryTree);

	return 0;
}