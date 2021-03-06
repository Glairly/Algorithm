#include "../libraries/mixin.h"
#define RED true
#define BLACK false
#define HEAD true
#define CHILD false
#define RIGHT 1
#define LEFT  2
// implementation of Red-black tree is to simply the implementation of 2-3 tree  (╯°□°）╯︵ ┻━┻


struct Node
{
    lld val = -1;
    Node *left = nullptr,*right = nullptr;
    bool color = BLACK;
} typedef n;


void _copy(n &node,n &blueprint)
{
    node.val = blueprint.val;
    node.left = blueprint.left;
    node.right = blueprint.right;
    node.color = blueprint.color;
}

void swapColor(n &node)
{
    if(node.left)
    {
        node.left->color = BLACK;
    }
    if(node.right)
    {
        node.right->color = BLACK;
    }
}

n& _init(lld val = -1)
{
    n *node = new n();
    node->val = val;
    return *node;
}

n& rotateLeft(n &nod)  // child node
{
    n *node = new n();
    _copy(*node,nod);

    n *Head = node->right, // new head
       *Left = Head->left; // new node.left right node
    node->right = Left;
    Head->left =  node;
    // color
    Head->color = nod.color;
    node->color = RED;
    return *Head;
}

n& rotateRight(n &nod)
{
    n *node = new n();
    _copy(*node,nod);

    n *Head = node->left, // new head
       *LeftR = node->left->right;
    node->left = LeftR;
    Head->right = node;
    // color

    Head->color = nod.color;
    node->color = RED;

    return *Head;
}

bool isRed(n *node)
{
    if(node)
    {
        return node->color;
    }
    else
        return false;
}


void _insert(n &root,lld val)
{
    if(&root == nullptr || root.val == val)
        return;
    if(root.val == -1) // head
    {
        root.val = val;
        return ;

    }
    if(root.val > val)
    {
        if(root.left == nullptr)
        {
            n *node = new n();
            node->val = val;
            root.left = node;
            node->color = RED;
        }
        else
            _insert(*root.left,val);
    }
    if(root.val < val)
    {
        if(root.right == nullptr)
        {
            n *node = new n();
            node->val = val;
            root.right = node;
            node->color = RED;
        }
        else
            _insert(*root.right,val);
    }

    if( !isRed(root.left) && isRed(root.right))
    {
        root = rotateLeft(root);
    }
    if(isRed(root.left) && isRed(root.left->left))
    {
        root = rotateRight(root);
    }
    if(isRed(root.left) && isRed(root.right))
    {
        swapColor(root);
    }
}

pair<n&,bool> _get(n &root,lld val,bool res)
{
    if(&root == nullptr || root.val == -1)
    {
        n *nu = new n();
        return  {*nu,false};
    }
    if(root.val == val)
        return {root,false}; // head
    if(root.val > val)
    {
        if(root.left == nullptr)
        {
            n *nu = new n();
            return  {*nu,false};
        }
        else if (root.left->val == val)
        {
            if(res == HEAD)
            {
                return {root,LEFT};
            }
            else
                return {*root.left,LEFT};
        }
        else
            return  _get(*root.left,val,res);
    }
    if(root.val < val)
    {
        if(root.right == nullptr)
        {
            n *nu = new n();
            return  {*nu,false};
        }
        else if (root.right->val == val)
        {

            if(res == HEAD)
            {
                return {root,RIGHT};
            }
            else
                return  {*root.right,RIGHT};
        }
        else
            return  _get(*root.right,val,res);
    }
}
//         o <- h
// L -> o     o <- R          ->  success(RL) -> h = RL (change child) ->
//     RL ->o   o <- RR

//                o <- h
//      L -> o           o <- R          ->  success(RL) -> h = RL (change child) ->
//        o     o    RL ->o   o <- RR

bool success(n &node)
{
    cout<<2;

    n    *Left = node.left,
          *Right = node.right,
           *RL = node.right->left;

    if(Right == nullptr)
    {
        cout<<3;
        if(Left == nullptr)
            return false;
        node.val = Left->val; // copy value
        return success(*Left);
    }
    else
    {
        if(RL == nullptr)
        {
            cout<<4;
            node.val = Right->val;
            node.right = Right->right;
            return true;
        }
        else
        {
            cout<<5;
            node.val = RL->val;
            return success(*RL);
        }
    }
}

bool _delete(n &root,lld val)
{
    cout<<1;
    if(&root == nullptr || root.val == -1)
        return false;

    if(root.val == val)
    {
        return success(root);
    }
    else if(root.val > val)
    {
        if(root.left)
        {
            if(root.left->val == val)
            {
                return success(*root.left);
            }
            else
                return _delete(*root.left,val);
        }
        else
            return false;
    }
    else if(root.val < val)
    {
        if(root.right)
        {
            if(root.right->val == val)
            {
                return success(*root.right);
            }
            else
                return _delete(*root.right,val);
        }
        else
            return false;
    }
}

int main()
{
    n root;
    int num;
    cin>>num;
    srand(time(NULL));
    for(int i = 0 ; i < num ; i++)
    {
        lld t = rand()%100;
        cout<<t<<" ";
        _insert(root,t);
    }
    RESULT
    printTree(root," ",0);
//    ENDLINE
//    printTree(root," ",1);
    RESULT
    cin>>num;
    _delete(root,num);
//    cout<<(_get(root,num,CHILD)).val;
    RESULT
    printTree(root," ",0);
}
