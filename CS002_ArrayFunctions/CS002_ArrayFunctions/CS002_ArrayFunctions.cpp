#include "array_functions.h"
#include "test.h"
using namespace std;

const int MAX_SIZE = 20;
typedef int ARRAY_TYPE;

int main()
{
	ARRAY_TYPE arr[MAX_SIZE] = { 1,2,3,4,5,6,7,8 };
	int num_used = 8;

	testFnc(arr, num_used);
}

