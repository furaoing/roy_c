#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <random>
#include "true_random.h"

using namespace std;

void generate_bigDataSet()
{
  ofstream myfile;
  myfile.open ("example.txt");
  int r_min = 0;
  int r_max = int (pow(10.0, 9.0));
  for(int i=0; i<0.5*r_max;i++)
  {

      myfile << true_random(r_min,r_max) << "\n";
  }
  myfile.close();

}

int collision_detection()
{
   int i;
   int j;
   char buffer[300];
   int guess;
   string str_buffer;
   int int_buffer;
   int round = 0;

   int r_min = 0;
   int r_max = int (pow(10.0, 9.0));

   ifstream myfile("example.txt");

    while(true)
    {
      round += 1;
      cout << "Round " << round << " Processing...\n";
      ifstream myfile("example.txt");
       if(myfile.is_open())
       {
         guess = true_random(r_min, r_max);    //pick a guess;
         for(i=0; i<0.5*r_max;i++)
         {
            myfile.getline(buffer,300);
            str_buffer = {buffer};
            int_buffer = stoi(str_buffer);
            if(guess == int_buffer)
            {
                cout << "Inloop Fail" << guess << "\n";
                break;
            }

            if(i == (0.5*r_max-1))
            {
                cout << guess;
                return guess;
            }
         }
       }
       else
         cout << "Unable to open file";
       myfile.close();
    }
   return 0;
}

int _main()
{
    generate_bigDataSet();
    //collision_detection();
}
