#include <iostream>
using namespace std;

int main()
{
   int *arrayA;
   arrayA = new int[3];
   
   arrayA[0] = 0;
   arrayA[1] = 5;
   arrayA[2] = 10;
   
   for (int i=0; i < 4; i++)
   {
       int *arrayB;
       arrayB = new int[3];
       
       arrayB[0] = arrayA[0] + 1;
       arrayB[1] = arrayA[1] * 2;
       arrayB[2] = arrayA[2] + 5;
       
       arrayA = arrayB;
   }
   
   cout <<"Array A[0]: " << arrayA[0] << endl;
   cout <<"Array A[1]: " << arrayA[1] << endl;
   cout <<"Array A[2]: " << arrayA[2] << endl;
}