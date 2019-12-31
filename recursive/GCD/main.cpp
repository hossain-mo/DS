#include <iostream>

using namespace std;
int getGCD(int ptr1, int ptr2);
int main()
{
    cout << getGCD(25,10) << endl;
    return 0;
}
int getGCD(int ptr1, int ptr2){
    if(ptr2 == 0)
        return ptr1;
    if(ptr1 == 0)
        return ptr2;
    return getGCD(ptr2,ptr1%ptr2);
}
