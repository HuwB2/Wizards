//
//  main.cpp
//  Wizards
//
//  Created by Huw Borradaile on 10/11/2020.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void splitDigits(vector<int>& digits, int num)
{
    while(num >= 1)
    {
        digits.push_back(num % 10);
        num = num /10;
    }
}

bool unique(vector<int>& digits)
{
    //for each element
    for(int j = 0; j<digits.size(); j++){
        //look ahead for duplicates
        for(int k=(j+1);k<digits.size(); k++){
            //if same break!
            if(digits[j] == digits[k]) return false;
        }
    }
    
    return true;
}

bool isMagic(vector<int>& digits)
{
    //check for magic
    
    int n = digits.size()-1;
    
    //stores locations been to
    set<int> memory;
    
    int i=n;
    while(memory.find(i) == memory.end())
            {
                i-=digits[i];
                
                //skip back round
                while(i < 0)
                {
                    i += n;
                }
                if(i==0) return true;
                
                memory.insert(i);
//                cout << "i: " << i << " n: " << n << endl;
            }
    return false;
}

int main() {
    
    int A = 110;
    int B = 1000;
    
    vector<int> digits;
    
    
    // loop A to B
    for(int i=0; i<digits.size(); i++)
    {
        cout << digits[i] << " ";
    }
    
    for(int i = A; i<=B; i++)
    {
        //erase digits
        digits.clear();
        
        //split digits in vector
        splitDigits(digits, i);
        
        //all digits are unique?
        if(unique(digits) && isMagic(digits)) cout << i << endl;
        
    }
    
    return 0;
}
