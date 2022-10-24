#include <iostream>
using namespace std;
int main()
{
int MissingNumber(int array[], int n) {
            int value = 0;
            int result = 0;
            for (int i = 0; i < n; i++)
            {
                value = i >= n-1 ? 0 : array[i];
                result = result ^ value ^ (i + 1);  
            }
            return result;
    }

