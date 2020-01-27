#include <iostream>
#include "Queue.h"
using namespace std;
void traverse(Queue* queue){
    while(!queue->isEmpty()){
        cout << *(int *)queue->deQueue()<<" ";
    }
    cout <<endl;
}
int main()
{
   //an Queue application Categorize Data
   /*
    we take data from user when number equal -1 it mean its end
   */
   int num=0;
   int *dataPtr;
   Queue* queue0to9   = new Queue();
   Queue* queue10to19 = new Queue();
   Queue* queue20to29 = new Queue();
   Queue* queueover29 = new Queue();
   while(num!=-1){
    cin>>num;
    dataPtr  = (int *)malloc (sizeof(int));
    *dataPtr = num;

    if (num > 0   && num < 10) {queue0to9->enQueue(dataPtr);}
    if (num >= 10 && num < 20) {queue10to19->enQueue(dataPtr);}
    if (num >= 20 && num < 30) {queue20to29->enQueue(dataPtr);}
    if (num >29) {queueover29->enQueue(dataPtr);}
   }
   cout << "Data   0..9    : ";traverse(queue0to9);
   cout << "Data   10..19  : ";traverse(queue10to19);
   cout << "Data   20..29  : ";traverse(queue20to29);
   cout << "Data   over 29 : ";traverse(queueover29);
    return 0;
}
