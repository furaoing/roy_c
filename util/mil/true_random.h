#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int true_random(int r_min, int r_max)
{
  random_device rd;
  int buffer;
  while(true)
  {
     buffer = rd();
     if( (r_min < buffer) && (buffer < r_max)  )
     {
         return buffer;
     }
  }
}
