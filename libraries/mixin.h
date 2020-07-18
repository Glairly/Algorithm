#include <bits/stdc++.h>
#define lld long long int
#define ENDLINE cout<<endl;
#define RESULT  cout<<"\n-----------------RESULT-----------------\n";

using namespace std;

template <class T> void printArr(vector<T> &arr,string split = " ")
{
    for(auto &i : arr)
    {
        cout<<i<<split;
    }
}

template <class T> void printTree(T &root,string split = " ",int mode = 0)
{

    if(mode == 0)
        cout<<root.val<<split;
    if(root.left == nullptr) {}
    else
        printTree(*root.left,split,mode);
    if(mode == 1)
        cout<<root.val<<split;
    if(root.right == nullptr) {}
    else
        printTree(*root.right,split,mode);
    if(mode == 2)
        cout<<root.val<<split;
}


