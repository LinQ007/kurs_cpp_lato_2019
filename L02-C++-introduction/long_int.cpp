#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
    //Constructor
    LongInt(int left, int right) : left(left), right(right)
    {
    }

    //Constructor
    LongInt(std::string str)
    {
        int number = std::stoi(str);
        left = number / 100;
        right = number % 100;
    }

    //Copy constructor
    LongInt(const LongInt& other)=default;

    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
	if(left)
	    {
       		 if(right<10)
	    	     {
	                 return std::to_string(left) + "0" + std::to_string(right);
		     }
		 else
			return std::to_string(left) + std::to_string(right);		 
	
	    } 
         else 
	     return std::to_string(right);	 
			     
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1(1,70);
    LongInt val2("2831");
    LongInt val3("0");
    std::cout << val1.toString() << std::endl;
    val1 += val2;
    std::cout << val1.toString() << std::endl;
    std::cout << val3.toString() << std::endl;
    LongInt val4("10");
    std::cout << val4.toString() << std::endl;
}

