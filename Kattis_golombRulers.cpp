/*

Link to original problem:
https://open.kattis.com/problems/golombrulers

How it works:
Highlevel:
  To find all the values of a golomb ruler we need to find the difference between the different marks given. 
  To do this we need to take all N choose 2 combinations of mark inputs. This should be a O(N^2) runtime.
  We will put these combinations in a set. If while placing these values in a set, we come across a duplicate entry, we will call the input NOT A RULER.
  If there are no duplicate enteries, we wonder if there are any values missing. We can check this easily by finding the size of the set. If there are no duplicates and we have to have numbers 1 through N, we should have a set of size N.
  Lastly, if we do not have a set of size N, we need to find out the which elements are missing and return "missing <numbers missing> "

Notes:
General note: if you want to send a EOF character using the keyboard, use either...
ctrl-d on linix 
ctrl-z on windows


Note 1: 
while(ss >> input) 
ss is a stringstream object. Using >> will take the next string object (seperated by white space) and will place that value into input. 
***IMPORTANT AND USEFUL*** 
  input is of type int. ss will convert the returned value of >> to be int.


Note 2: 
To find all N chooes 2 combinations, we take a mark and subtract it against all elements in the set. However, we do not want to account for duplicates. Nn the nested forloop we always set the j value to be one less then the element we are currently on to do this.

the line
s.find(abs(iv[i] - iv[j])) == s.end() is also of note.
s.find will return s.end if it cannot find the value abs(iv[i] - iv[j]). In the set s. 


Note 3: If the set is size N, then return a perfect ruler. Otherwise, we know we are missing something. we want to use a forloop that increments an iterator and a int at the same time. This is because an iterator on a set will return the values of the set in acending order and if we increment them both at the same time, we would expect that values to be the same since both the iterator and int should start at 1. If they do not equal each other, then we have to let the int "catch up" to the current value of the iterator. These values are the ones that are missing from the ruler.


*/


#include <iostream>
#include <vector>
#include <set>
#include <cmath> 
#include <sstream>

void operations(std::vector<int> iv, int h){ //input vector and higest respectively
  std::set<int> s;

  //Note 2
  for(int i = iv.size() - 1; i > 0; i--){
    for(int j = i-1; j > -1; j--){
      if(s.find(abs(iv[i] - iv[j])) == s.end())
        s.insert(abs(iv[i] - iv[j]));
      else{
        std::cout<< "not a ruler \n";
        return;
      }
    }
  }


  // note 3
  if(s.size() != h){
    std::cout << "missing ";
    { // declare new scope for j
      auto j = s.begin();
      for(int i = 1; j != s.end(); i++,j++){
        if(*j == i)
          continue;
        else{
          while(i != *j){
            std::cout << i << " ";
            i++; 
          }
        }
      std:: cout << "\n";
      }
      
    }
  }
  else
    std::cout << "perfect \n"; 


}



int main() {
  
  int input, highestVal = 0;
  std::vector <int> inputVector;
  std::string s;


  while(true){

    // read in line from keyboard
    std::getline(std::cin, s);

    // if the read in line was EOF, terminate.
    if(std::cin.eof())
      return 0;

    std::stringstream ss(s);

      // Note 1
      while(ss >> input){
        if(input > highestVal)
          highestVal = input;
        inputVector.push_back(input);
      }
      operations(inputVector, highestVal);
      inputVector.clear();
      highestVal = 0;
  }

}
