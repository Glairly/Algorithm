#include <bits/stdc++.h>
#define lld long long int
using namespace std;

void printArr(vector<lld> &arr)
{
    for(auto &i : arr)
    {
        cout<<i<<" ";
    }
}


void _init(vector<lld> &arr,lld size)
{
    arr.resize(size*2+1);
    for(auto &i : arr)
    {
        i = -1;
    }
}


/* H L1 R1 L1.1 L1.2 R1.1 R1.2
   0 1  2  3    4    5    6 */

void _insert(vector<lld> &arr,lld num)
{

    for(int i = 0 ; i < arr.size(); )
    {
        if(arr[i] == -1)
        {
            arr[i] = num;
            return ;
        }
        if(num <= arr[i])
            i = (i<<1) + 1;
        else
            i = (i<<1) + 2;
    }
}

template <class T> void queryAscend(vector<T> &src,vector<T> &arr,int index)
{
    if(index >= src.size() || src[index] == -1 )
        return;
    queryAscend(src,arr,(index<<1)+1);
    if(src[index] != -1)
        arr.push_back(src[index]);
    queryAscend(src,arr,(index<<1)+2);

}

template <class T> vector<T> getAscend(vector<T> &src)
{
    vector<T> dup;
    queryAscend(src,dup,0);
    return dup;
}

template <class T> void queryDescend(vector<T> &src,vector<T> &arr,int index)
{
    if(index >= src.size() || src[index] == -1 )
        return;
    queryDescend(src,arr,(index<<1)+2);
    if(src[index] != -1)
        arr.push_back(src[index]);
    queryDescend(src,arr,(index<<1)+1);

}

template <class T> vector<T> getDescend(vector<T> &src)
{
    vector<T> dup;
    queryDescend(src,dup,0);
    return dup;
}


int main()
{
    vector<lld> arr;
    lld n;
    cin>>n;
    _init(arr,n);
    srand(time(NULL));
    clock_t tStart = clock();
    for(lld i = 0 ; i < n ; i++)
    {
        lld t = rand() % 40;
        // cout<<t<<" ";
        _insert(arr,t);
    }
    vector<lld> ascend = getAscend(arr);
    vector<lld> descend = getDescend(arr);

    cout<<endl<<"---------Result---------"<<endl;
    printArr(ascend);
    cout<<endl<<"------------------------"<<endl;
    printArr(descend);


}
