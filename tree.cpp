//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<map>
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

int height(Node *r){
    if(r == NULL){
        return 0;
    }
        return 1+max(height(r->left) ,height(r->right));

}

void preorder(Node *r){
    if(r==NULL)
        return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r){
    if(r == NULL)
        return;

    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node *r)
{
    if(r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

void printLevelOrder(Node *r){
    if(r == NULL)
        return;
    queue<Node *>q;
    q.push(r);

    while(q.empty()==false){
        Node *curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
    }
}

void printLevelOrderLineByLine(Node *r){
    if(r == NULL)
        return;
    queue<Node *>q;
    q.push(r);
    q.push(NULL);

    while(q.size()>1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            q.push(NULL);
            cout<<endl;
            continue;
        }

        cout<<curr->data<<" ";
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);

    }
}

void printLevelOrderLineByLine1(Node *r){
    if(r==NULL)
        return;
    queue<Node *>q;
    q.push(r);

    while(q.empty() == false){
            cout<<"\n";
            int count = q.size();
        for(int i=0; i<count; i++){
            Node *curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left != NULL)
            q.push(curr->left);
            if(curr->right != NULL)
            q.push(curr->right);
        }
    }
}

 void printNodeAtK(Node *r, int k){
   if(r == NULL)
        return;
   if(k == 0){
        cout<<r->data<<" ";
   }
   else{
   printNodeAtK(r->left, k-1);
   printNodeAtK(r->right, k-1);
 }
}

 int leftLevel = 0;
 void printLeftView(Node *r, int level){
    if(r==NULL)
        return;

    if(leftLevel<level){
        cout<<r->data<<" ";
        leftLevel = level;
    }
    printLeftView(r->left, level+1);
    printLeftView(r->right, level+1);
}

int rightLevel = 0;
void printRightView(Node *r, int level){
    if(r==NULL)
        return;

    if(rightLevel<level){
        cout<<r->data<<" ";
        rightLevel = level;
    }
    printRightView(r->right, level+1);
    printRightView(r->left, level+1);

}

//void topView(Node *r, int dist, int level, auto &map){
//    if(r == NULL){
//        return;
//    }
//        if(map.find(dist) == map.end() || level < map[dist].second){
//        map[dist] = {r->data, level};
//        }
//    topView(r->left, dist-1, level+1, map);
//    topView(r->right, dist+1, level+1, map);
//
//}

//void topView(Node *r, int level, auto &m){
//    if(r == NULL){
//        return;
//    }
//        if(m.find(level) == m.end()){
//        m[level] = r->data;
//        }
//    topView(r->left, level-1, m);
//    topView(r->right, level+1, m);
//
//}

void topView(Node *r, int level, auto &m){
    if(r == NULL){
        return;
    }

    m.insert( {level, r->data} );

    topView(r->left, level-1, m);
    topView(r->right, level+1, m);

}

void bottomView(Node *r, int level, auto &m){
    if(r == NULL){
        return;
    }

    m.insert({level, r->data});

    if(m.find(level) != m.end()){
      m[level] = r->data;
   }

    bottomView(r->left, level-1, m);
    bottomView(r->right, level+1, m);

}


bool isChildrenSum(Node *r){
    if(r == NULL)
        return true;
    if(r->left == NULL & r->right == NULL)
        return true;

    int sum = 0;
    if(r->left != NULL){
        sum+=r->left->data;
    }
    if(r->right != NULL)
    {
       sum+=r->right->data;
    }

    return(r->data == sum && isChildrenSum(r->left) && isChildrenSum(r->right));

}

bool isBalancedTree(Node *r){
    if(r == NULL)
        return true;

        int lh = height(r->left);
        int rh = height(r->right);

    return
    (abs(lh - rh)>1 && isBalancedTree(r->left) && isBalancedTree(r->right));

}
void maxWidth(Node *r){
    if(r == NULL)
        return;
    queue<Node *>q;
    q.push(r);
    int maxWidth = 0;
    while(q.empty() == false){
       // cout<<"\n";
        int count = q.size();
        if(count>maxWidth)
            maxWidth = count;

        for(int i=0; i<count; i++){
            Node *curr = q.front();
            q.pop();

           // cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
    cout<<maxWidth<<endl;

}

Node *p = NULL;
Node *BTToDLL(Node *r){

    if(r == NULL)
     return r;

     Node *head = BTToDLL(r->left);
     if(p == NULL){
        head = r;
     }
     else{
        r->left = p;
        p->right = r;
     }
     p = r;

     BTToDLL(r->right);

    return head;
}
int main(){
//    Node *root = new Node(10);
//    root->left = new Node(20);
//    root->right = new Node(30);
//    root->left->left = new Node(40);
//    root->right->right = new Node(50);
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(9);
    root->right->right = new Node(3);
    root->right->left->right = new Node(5);

    int res = height(root);
    cout<<res<<endl;

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    printLevelOrder(root);
    cout<<endl;
    printLevelOrderLineByLine(root);
    cout<<endl;
    printLevelOrderLineByLine1(root);
    cout<<endl;
    printNodeAtK(root, 1);
    cout<<endl;
    printLeftView(root, 1);
    cout<<endl;
    printRightView(root,1);
    cout<<endl;

//    map<int, pair<int, int>> map;
//     topView(root, 0, 0, map);
//     for(auto it : map){
//        cout<<it.second.first<<" ";
//    }
//    cout<<endl;


    map<int, int> m;
     topView(root, 0, m);
     for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;

    bottomView(root, 0, m);
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;


    cout<<isChildrenSum(root)<<endl;
    cout<<isBalancedTree(root)<<endl;
    maxWidth(root);
    cout<<endl;

    Node *ptr = BTToDLL(root);
    cout<<ptr->data;

    return 0;
}
