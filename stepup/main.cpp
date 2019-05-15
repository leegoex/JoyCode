#include <iostream>

int factorial(int val)
{
  if(val == 0) {
    return 1;
  }
  int retVal = val;
  while(--val > 0) {
    retVal *= val;
  }
  return retVal;
}

int permute(int n, int k)
{
  if(n < k) {
    return 0;
  }
  return factorial(n) / factorial(n - k);
}

int calcCount(int oneStepCount, int twoStepCount)
{
  std::cout << "calculate one step = " << oneStepCount << ", two step = " << twoStepCount << std::endl;
  int retVal = 0;
  if(oneStepCount == 0 || twoStepCount == 0) {
    retVal = 1;
  }
  else if(oneStepCount >= twoStepCount)
  {
    retVal = permute(oneStepCount + 1, twoStepCount);
  } 
  else 
  {
    retVal =  permute(twoStepCount + 1, oneStepCount);
  }
  std::cout << "the step count = " << retVal << std::endl;
  return retVal;
}

int main(int argc, char* argv[])
{
  if(argc < 2) {
    std::cout << "please give the step count first!" << std::endl;
    return 0;
  }
  int stepCount = std::stoi(argv[1]);
  std::cout << "begin to calculate the total count of " << stepCount << std::endl;
  int totalCount = 0;
  for(int i = 0; i <= stepCount / 2; ++i) {
    totalCount += calcCount(stepCount - i * 2, i);
  }
  std::cout << "total count = " << totalCount << std::endl;
  return 0;
}