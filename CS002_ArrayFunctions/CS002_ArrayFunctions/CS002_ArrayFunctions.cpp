#include "array_functions.h"
#include "test.h"
using namespace std;

const int MAX_SIZE = 10;
typedef int ARRAY_TYPE;

int main()
{
	ARRAY_TYPE arr[MAX_SIZE] = { 1,2,3,4,5 };
	int num_used = 5;

	testFnc(arr, num_used);
}

