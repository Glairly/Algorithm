//#include "../libraries/mixin.h"
//struct _pair
//{
//    lld low = -1,hi = -1;
//    _pair  *parent=nullptr,*left=nullptr,*midP=nullptr,*right=nullptr;
//};
//
//void _init(_pair &root,lld low,lld hi)
//{
//    root.low = low;
//    root.hi = hi;
//}
//
//vector<_pair>* _splitNode(_pair &node)
//{
//    vector<_pair> *arr = new vector<_pair>;
//    _pair left,right;
//    left.low = node.low;
//    left.left = node.left;
//    right.hi = node.hi;
//    right.right = node.right;
//    arr->push_back(left);
//    arr->push_back(right);
//    return arr;
//}
//
//void _split(_pair &now,_pair &parent,lld mid,bool left) // after sort value in now node val = mid value
//{
//
//    _pair
//    *Head = new _pair(),*nodeM = parent.midP,
//    nodeL,nodeR; // new node
//    auto arr = _splitNode(now);
//    nodeL = arr[0],nodeR = arr[1];
//    if(parent.midP)
//    {
//        if(left)
//        {
//            lld temp = parent.low;
//            parent.low = mid;
//            auto arr2 = _splitNode(parent);
////            Head->left = no
//        }
//        else
//        {
//
//        }
//    }
//    else
//    {
//        if(left)
//        {
//            parent.hi = parent.low;
//            parent.low = mid;
//            parent.midP = &nodeR;
//            parent.left = &nodeL;
//        }
//        else
//        {
//            parent.hi = mid;
//            parent.midP = &nodeL;
//            parent.left = &nodeR;
//        }
//    }
//}
//
//template <class T> vector<T>  _sort(T a,T b,T c)
//{
//    vector<T> arr{a,b,c};
//    sort(arr.begin(),arr.end(),less<T>());
//    return arr;
//}
//
//bool _push(_pair *node,lld val)
//{
//    auto temp = _sort(node->low,val,node->hi);
//    if(temp[0] == -1)
//    {
//        node->low = temp[1];
//        node->hi = temp[2];
//        return false;
//    }
//    node->low = temp[0];
//    node->hi = temp[2];
//    return true;
//}
//
//void _insert(_pair &root,lld val)
//{
//    cout<<endl;
//    _pair *now = &root;
//    while(true)
//    {
//        if(!now) {}
//        auto low = now->low;
//        auto hi = now->hi;
//        // travel
//        if(val <= low)
//        {
//            if(val == low)
//                return;
//            if(now->left)
//            {
//                now = now->left;
//                continue;
//            }
//        }
//        else if(val >= hi)
//        {
//            if(val == hi)
//                return;
//            if(now->right)
//            {
//                now = now->right;
//                continue;
//            }
//        }
//        if(!_push(now,val))
//        {
//            return ;
//        }
//        else
//        {
//            if(now->parent)  // sub head
//            {
//
//                if(_push(now->parent,val))
//                {
//                    cout<<"split subhead"<<endl;
////                    _split(*now->parent,val);
//                }
//                else
//                    return ;
//            }
//            else   // head
//            {
//                cout<<"split head"<<endl;
////                _split(*now,val);
//            }
//        }
//
//    }
//
//}
//
//void print(_pair &root)
//{
//    if(&root == nullptr)
//        return;
//    print(*root.left);
//    printf("(%lld  %lld) ",root.low,root.hi);
//    print(*root.midP);
//    print(*root.right);
//
//
//
//}
//
//int main()
//{
//    _pair root;
//    _init(root,0,2);
//    _insert(root,1);
//    //  print(root);
//    _insert(root,3);
//    //  print(root);
//    _insert(root,4);
//    //  print(root);
//    _insert(root,5);
//    print(root);
//
//
//}
