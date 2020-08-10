//전위순회 출력 : 1 2 4 5 3 6 7 
//중위순회 출력 : 4 2 5 1 6 3 7
//후위순회 출력 : 4 5 2 6 7 3 1

#include <iostream>

void 전위(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	std::cout << arr[idx] << ' ';
	전위(arr, idx * 2);
	전위(arr, idx * 2 + 1);
}
void 중위(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	
	중위(arr, idx * 2);
	std::cout << arr[idx] << ' ';
	중위(arr, idx * 2 + 1);
}
void 후위(int* arr, const int& idx = 1)
{
	if (idx > 7) return;
	
	후위(arr, idx * 2);
	후위(arr, idx * 2 + 1);
	std::cout << arr[idx] << ' ';
}

int main()
{
	using namespace std;

	int binaryTree[8]{ 0,1,2,3,4,5,6,7 };

	전위(binaryTree);
	cout << endl;
	중위(binaryTree);
	cout << endl;
	후위(binaryTree);

	return 0;
}