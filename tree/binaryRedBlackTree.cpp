#include "../libraries/mixin.h"
#define RED true
#define BLACK false
#define HEAD true
#define CHILD false
// implementation of Red-black tree is to simply the implementation of 2-3 tree  (╯°□°）╯︵ ┻━┻


struct Node
{
    lld val = -1;
    Node *left = nullptr,*right = nullptr;
    bool color = BLACK;
} typedef n;

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

n& rotateLeft(n &nod)  // child node
{
    n *node = new n();
    node->val = nod.val;
    node->left = nod.left;
    node->right = nod.right;
    node->color = nod.color;

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
    node->val = nod.val;
    node->left = nod.left;
    node->right = nod.right;
    node->color = nod.color;

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

//n& _get(n &root,lld val,bool res)
//{
//    if(&root == nullptr || root.val == -1)
//    {
//        n *nu = new n();
//        return  *nu;
//    }
//    if(root.val == val) return root; // head
//    if(root.val > val)
//    {
//        if(root.left == nullptr)
//        {
//            n *nu = new n();
//            return  *nu;
//        }
//        else if (root.left->val == val)
//        {
//            if(res == HEAD)
//            {
//                return root;
//            }
//            else
//                return *root.left;
//        }
//        else
//            _get(*root.left,val,res);
//    }
//    if(root.val < val)
//    {
//        if(root.right == nullptr)
//        {
//            n *nu = new n();
//            return  *nu;
//        }
//        else if (root.right->val == val)
//        {
//            if(res == HEAD)
//            {
//                return root;
//            }
//            else
//               return  *root.right;
//        }
//        else
//            _get(*root.right,val,res);
//    }
//}

//bool _delete(n &root,lld val)
//{
//    if(&root == nullptr || root.val == -1)
//        return false;
//
//}


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
    //printTree(root," ",1);
}
