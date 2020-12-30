#include <iostream>

using namespace std;

class obj{
public:
	int arr[5];
};

int main()
{
	obj* myObj = new obj();
	myObj->arr[0] = 1;
	printf("%d\n", myObj->arr[0]);
	return 0;
}


