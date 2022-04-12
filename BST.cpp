#include<iostream>
using namespace std;

class BST{
public:
    int data;
    BST *left;
    BST *right;

    BST(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

BST *createBST(){
    int x;
    cin>>x;
    if(x == -1)
        return NULL;

    BST *root = new BST(x);

    cout<<"less than && left of: " <<root->data<<endl;
    root->left = createBST();

    cout<<"greater than && right of: "<<root->data<<endl;
    root->right = createBST();

    return root;

}

void showBST(BST *root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    showBST(root->left);
    showBST(root->right);
}

 bool search(BST *root, int a){

    if(root == NULL)
        return false;

    else if(root->data == a)
        return true;

    else if(root->data > a)
        return search(root->left, a);

    else
        return search(root->right, a);
}

BST *insert(BST *r, int x){
    if(r == NULL)
        return new BST(x);
    else if(r->data > x){
        r->left = insert(r->left, x);
    }
    else if(r->data < x){
        r->right = insert(r->right, x);
    }

       return r;
}

BST *getSuccessor(BST *r){
    BST *curr = r->right;
    while(curr!=NULL && curr->left!=NULL)
        curr = curr->left;

    return curr;
}



BST *del(BST *r, int x){
    if(r == NULL)
        return r;

    else if(r->data > x){
        r->left = del(r->left, x);
    }
    else if(r->data < x){
        r->right  = del(r->right, x);
    }


    else
    {
        if(r->left == NULL)
        {

           BST *temp = r->right;
           delete r;
           return temp;
        }

        else if(r->right == NULL){
            BST *temp = r->left;
            delete r;
            return temp;
        }

        else {
            BST *eleSuccessor  = getSuccessor(r);
            r->data = eleSuccessor->data;
            r-> right  = del(r->right, eleSuccessor -> data);
            return r;
        }
    }
}

BST *balanceBST(int arr[], BST *r, int min, int max){
    if(min>max)
        return r;
    int mid  = (min+max)/2;
    r = new BST(arr[mid]);

    r->left = balanceBST(arr, r->left, min, mid-1 );
    r->right = balanceBST(arr, r->right, mid+1, max);

    return r;
}

BST *floor(BST* root, int key){
    BST *res = NULL;
    while(root!=NULL){
        if(root->data == key)
            return root;

        else if(root->data > key)
            root = root->left;

        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}

BST *ceil(BST *root, int key){
    BST *res = NULL;
    while(root!=NULL)
    {
        if(root->data == key)
            return root;

        else if(root->data < key)
            root = root->right;


        else{
            res = root;
            root = root->left;
        }

    }
    return res;
}


int main(){

    BST *r = createBST();
    cout<<endl;
//    showBST(r);
//    cout<<endl;
//
//    cout<<search(r, 6)<<endl;
//    showBST(insert(r, 5));
//    cout<<endl;
//    showBST(del(r, 8));

//      int arr[] = {8,10,12,15,18,20,25};
//      int n = sizeof(arr)/sizeof(arr[0]);
//      int min = 0;
//      int max = n-1;
//      int mid = (min+max)/2;
//      BST *p = new BST(arr[mid]);
//      showBST(balanceBST(arr, p, min, max));

        BST *res  = floor(r, 8);
        cout<<res->data<<endl;

        BST *res1 = ceil(r, 8);
        cout<<res1->data<<endl;


    return 0;
}

