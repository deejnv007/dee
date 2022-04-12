#include<bits/stdc++.h>
using namespace std;


class Node{
public:
   int data;
   Node *left;
   Node *right;

   Node(int val){
       data = val;
       left = NULL;
       right = NULL;
   }

};

int height(Node *root){
    if(root == NULL)
        return 0;

    return 1+max(height(root->left), height(root->right));
}

int main(){

    return 0;
}
