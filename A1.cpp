#include <iostream>
using namespace std;
#define size 10

class linearprobing{
    int phone[size];
    int flag[size];
     
    public:
    linearprobing(){
        for (int i=0; i<size; i++){
            flag[i]=0;
        }
    }

    void insert(int x){
        int loc;
        loc=x%size;

        for (int i=0 ; i<size; i++){
            if(flag[loc]==0){
                phone[loc]=x;
                flag[loc]=1;
                break;
            }
            else{
                loc=(loc+1)%size;
            }
        }
    }

    void create(){
        int n,x;
        cout<<"Enter the total entries of the phone number do you want to added:";
        cin>>n;
        cout<<"Enter the phone number entries :"<<endl;
        for (int i=0; i<n; i++){
            cin>>x;
            insert(x);
        }
    }

    int find(int x){
        int loc=x%size;
        for (int i=0; i<size; i++){
            if (flag[loc]==1 && phone[loc]==x){
                return loc;
            }else {
                loc=(loc+1)%size;
            }
        }
        return -1;
    }

    void search(){
        int x, loc;
        cout<<"Enter the number do you want to search it:"<<endl;
        cin>>x;
        if ((loc=find(x))==-1){
            cout<<"Phone number is not present in the hashtable!!!"<<endl;
        }else{
            cout<<"Phone number is present at "<<loc<<" in the hash table!"<<endl;
        }

    }

    void print(){
        cout<<"The hashatble is ->"<<endl;
        for (int i=0; i<size; i++){
            cout<<i<<"->";
            if (flag[i]==1){
                cout<<phone[i]<<endl;
            }else if (flag[i]==0){
                cout<<"-------"<<endl;
            }
        }
    }

};

struct node{
    int phone;
    node* next;
};

class separate_chaining{
    node*hash[size];
    public:

    separate_chaining(){
        for(int i=0; i<size; i++){
             hash[i]=NULL;
        }
    }

    void create(){
        int n,x;
        cout<<"Enter the total number of the elements do you want to insert in the hash"<<endl;
        cin>>n;
        cout<<"Enter the elements want to insert"<<endl;
        for (int i=0; i<n; i++){
            cin>>x;
            insert(x);
        }
    }

    void insert(int key){
        int loc=key%size;
        node*p=new node;
        p->phone=key;
        p->next=NULL;

        if(hash[loc]==NULL){
            hash[loc]=p;
        }else{
            node*q=hash[loc];
            while (q->next!=NULL){
                q=q->next;
            }
            q->next=p;
        }
    }

    void display(){
        cout<<"The hash table is ->"<<endl;
        for (int i=0 ; i<size; i++){
            node*q =hash[i];

            cout<<" ( "<<i<<") ->";
            while (q){
                cout<<q->phone;
                if (q->next){
                   cout<<"->";
                }
                q=q->next;
            }
            cout<<endl;
        }
    }
};
int main(){

    cout<<"Linear Probing"<<endl;
    linearprobing l;
    l.create();
    l.print();
    l.search();

    cout<<"Separate chaining"<<endl;
    separate_chaining s;
    s.create();
    s.display();
    return 0;
}



