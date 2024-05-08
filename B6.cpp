#include <iostream>
using namespace std;

//we want to create the node for the implementation of the binery search tree

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class bst{
    node *root;
    public:
    bst(){
        root=NULL;
    }

    //now insert function for the inserting the elements in to the tree 

    node* insert(node*root, int data){
        if (root == NULL){
            return new node(data);
        }
        if (data <root->data){
            root->left = insert(root->left,data); 
        }
        else{
            root->right = insert(root->right,data);
        }
        return root;
    }

    //now display function for the display the data of the tree
    //now we use the inorder display method for the display the elements in the tree

    void display(node *root){
        if (root !=NULL){
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);
        }
    }

    //now search function for the searching the elements from the binery search tree

    bool search(node *root ,int data){
        if (root == NULL){
            return false;
        }
        if (data < root->data){
            search(root->left,data);
        }
        else{
            search(root->right,data);
        }
        return true;
    }

    int findmax(node *root){
        if(root == NULL){
            return -1;
        }
        while (root->right != NULL){
            root=root->right;
        }
        return root->data;
    }

    int findmin(node* root){
        if (root == NULL){
            return -1;
        }
        while (root->left != NULL){
            root = root->left;
        }
        return root->data;
    }

    int height(node *root){
        if (root == NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 0;
        }
        else{
            int leftheight=height(root->left);
            int rightheight=height(root->right);

            if (leftheight > rightheight){
                return (leftheight+1);
            }
            else{
                return (rightheight+1);
            }
        }
    }

    void mirror(node *root){
        if (root == NULL){
            return ;
        }
        else{
            node *temp;
            mirror(root->left);
            mirror(root->right);

            temp=root->left;
            root->left=root->right;
            root->right=temp;
        }

    }
    void menu (){
        int ch,n,data,s;
        do{
            cout<<"----------------------MENU------------------------"<<endl;
            cout << "1. Insert elements" << endl;
            cout << "2. Display" << endl;
            cout << "3. Search element" << endl;
            cout << "4. Find minimum" << endl;
            cout << "5. Find maximum" << endl;
            cout << "6. The number of elemets present at the longest path" << endl;
            cout << "7. Create a mirror image of the tree" << endl;
            cout << "8. Exit" << endl;
            cout<<"Enter the choise:";
            cin>>ch;
            switch(ch){
                case 1:
                        cout<<"Enetr how many number do you want to insert:";
                        cin>>n;
                        for(int i=0; i<n; i++){
                            cout<<"Enter data:";
                            cin>>data;
                            root=insert(root,data);
                        }
                        cout<<"Data inserted successfully"<<endl;
                        break;
                case 2:
                        cout<<"The elements in the tree are as follows:"<<endl;
                        display(root);
                        cout<<endl;
                        break;
                case 3:
                        cout<<"Enter the number do you want to search:";
                        cin>>s;
                        if (search(root,s)==true){
                            cout<<"Element Found!!!"<<endl;
                        }else{
                            cout<<"Element not found"<<endl;
                        }
                        break;
                case 4:
                    cout << "Minimum element is:" << findmin(root) << endl;
                    break;
                case 5:
                    cout << "Maximum element is:" << findmax(root) << endl;
                    break;
                case 6:
                    cout << "The number of the nodes present at the longest path:" << (height(root)+1) << endl;
                    break;
                case 7:
                    mirror(root);
                    cout << "Mirror image of the tree created" << endl;
                    display(root);
                    cout<<endl;
                    break;
                case 8:
                    cout << "Exiting program" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;                         
            }
        }while(ch!=8);
    }
};

int main() {
    bst b1;
    b1.menu();
    return 0;
}