#include <iostream>

int main(int argc, char* argv[])
{
  int array[] = {6, 5, 0, 3, 1, 8, 7, 2, 9, 4};
  int length = sizeof(array)/sizeof(int);

  for(int i = 0; i < length; ++i) {
    for(int j = i; j > 0; --j) {
      if(array[j] < array[j-1]) {
        array[j] = array[j] ^ array[j - 1];
        array[j - 1] = array[j] ^ array[j - 1];
        array[j] = array[j] ^ array[j - 1];
      } else {
        break;
      }
    }
    for(int n = 0; n < length; ++n) {
      std::cout << array[n] << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}