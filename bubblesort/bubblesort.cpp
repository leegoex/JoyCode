#include <iostream>

int main(int argc, char* argv[])
{
  int array[] = {6,3,5,4,2,7,5,8,4,9,0,1,2,4,6,7};

  int i,j;
  int len = sizeof(array)/sizeof(int);
  for(i = 0; i < len; i++) {
    for(j = i; j < len; j++) {
      if(array[i] > array[j]) {
        array[i] = array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
      }
    }
    for(int n = 0; n < len; n++) {
      std::cout << array[n] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}