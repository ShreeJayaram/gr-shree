#include <iostream>
#include <string>

int main()
{
  using namespace std;
  string input;  
  cout << "Enter input bit string" << endl << endl; 
  cin >> input;
  
  int temp;
  int i = input.size();
  int j = 0;
  
  for ( j = 0; j < i; ++j)
    { 
        --i;

        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    
    cout << "The reversed string is: " << input << endl;
        
    cout << "Enter bit number: ";
    
    int bitn;
    cin >> bitn;
    
    int store[100] ;
    int k;
    
    //r (k = 0; k < bitn; k++)
    { 
        store[100] ++; 
        
    } 
    
    //ut << store[100];
    
    //turn 0;
    
} 
    
