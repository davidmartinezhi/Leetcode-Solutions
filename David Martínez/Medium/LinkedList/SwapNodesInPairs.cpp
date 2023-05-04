#include <iostream>
using namespace std;

struct ListNode{

    //Attributes
    int val;
    ListNode* next;

    //Constructor
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
}


