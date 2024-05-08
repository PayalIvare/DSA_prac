#include<iostream>
using namespace std;
typedef struct node
{
	int telno;
	struct node *next;
};
class OpenHashing
{
	public:
		node *hashtable[10];
		OpenHashing()
		{
			int i;
			for(i=0;i<10;i++)
			{
				hashtable[i]=NULL;
			}
		}
		void display()
		{
			int i;
			cout<<"\nTelephone No : ";
			for(i=0;i<10;i++)
			{
				node *q=hashtable[i];
				while(q!=NULL)
				{
					cout<<q->telno;
					q=q->next;
					cout<<"\t";	
				}
				cout<<"\n";	
			}	
		}
		void insert()
		{
			int key,loc;
			cout<<"\n Enter Telephone Number to store :";
			cin>>key;	
			node *p=new node;
			p->telno=key;
			p->next=NULL;
			loc=key%10;
			if(hashtable[loc]==NULL)
			{
				hashtable[loc]=p;
			}
			else
			{
				node *q=hashtable[loc];
				while(q->next!=NULL)
				{
					q=q->next;
				}
				q->next=p;
			}
			cout<<"\n Telephone Number Inserted Successfully";			
		}
		int search()
		{
			int key,loc,count=0,flag=0;
			cout<<"\n Enter Telephone Number to search :";
			cin>>key;	
			loc=key%10;
			node *q=hashtable[loc];
			while(q!=NULL)
			{
				count++;
				if(q->telno==key)
				{
					flag=1;
					break;	
				}
				else
				{
					q=q->next;
				}	
			}
			if(flag==0)
			{
				cout<<"\nTelephone Number Not Found";
			}
			else
			{
				cout<<"Telephone Number Found";
			}	
			return count;
		}		
};

class linear_probing
{	
	public:
		int hashtable[10];
		int flag[10]={0,0,0,0,0,0,0,0,0,0};	
		void display()
		{
			int i=0;
			cout<<"\n Telephone Number : \n";
			for(i=0;i<10;i++)
			{
				if(flag[i]==1)
				{
					cout<<hashtable[i];
					cout<<"\n";
				}
				else
				{
					cout<<"-";
					cout<<"\n";
				}
			}
		}
		void insert()
		{
			int key,loc,i;
			
			cout<<"\n Enetr Telephone No :";
			cin>>key;
			loc=key%10;
			for(i=0;i<10;i++)
			{
				if(flag[loc]==0)
				{
					hashtable[loc]=key;
					flag[loc]=1;
					break;
				}
				else
				{
					loc=(loc+1)%10;
				}	
			}
			if(i==10)
			{
				cout<<"\n Table is full we cann't insert telephone number ";
			}
		}
		int search()
		{
			int key,loc,i,count=0;	
			cout<<"\n Enetr Telephone No to search :";
			cin>>key;
			loc=key%10;
			for(i=0;i<10;i++)
			{
				if(flag[loc]==1)
				{
					count++;	
					if(hashtable[loc]==key)
					{
						cout<<"\n Record Found ";
						return count;
						break;
					}
					else
					{
						loc=(loc+1)%10;
					}
				}
				else
				{
					cout<<"\nRecord Not found";
					break;
				}	
			}
			if(i==10)
			{
				cout<<"\n Record not found ";
			}
			return count;
		}
	
};
void open_h()
{
	OpenHashing ob;
	int ch,comp;
	do
	{
		cout<<"\n ***********************************";
		cout<<"\n 1.Insert Telephone Number ";
		cout<<"\n 2.Search Telephone Number ";
		cout<<"\n 3.Display All Telephonr Number ";
		cout<<"\n 4.Exit ";
		cout<<"\n ***********************************";
		cout<<"\n Enert Youc Choice :";
		cin>>ch;	
		switch(ch)
		{
			case 1:
				ob.insert();
				break;
			case 2:
				comp=ob.search();
				cout<<"\n Comparisions Required "<<comp;
				break;
			case 3:
				ob.display();
				break;
			case 4:
				cout<<"\n Program Ended Succesfully ";
				break;
			default:
				cout<<"\n You Have Enter Wrong Choice ";
		}
		
	}while(ch!=4);
}
void linear_p()
{
	linear_probing ob;
	int ch,comp=0;
	do
	{
		cout<<"\n 1.Insert Telephone No :";
		cout<<"\n 2.Display :";
		cout<<"\n 3.Search :";
		cout<<"\n 4.Exit :";
		cout<<"\n  Enter Your Choice :";
		cin>>ch;	
		switch(ch)
		{
			case 1:
				ob.insert();
				break;
			case 2:
				ob.display();
				break;
			case 3:
				comp=ob.search();
				cout<<"\n Comparisions Required "<<comp;
				break;
			case 4:
				cout<<"\n Thank You ";
				break;
			default:
				cout<<"\n You Have Entered wrong choice ";		
		}	
	}while(ch!=4);
}
int main()
{
	int ch_h;
	do
	{
		cout<<"\n 1.Open Hashing ";
		cout<<"\n 2.Linear Probing ";
		cout<<"\n 3.Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch_h;
		switch(ch_h)
		{
			case 1:
				open_h();
				break;
			case 2:
				linear_p();
				break;
			case 3:
				cout<<"\n Thank You";
				break;
			default:
				cout<<"\n You Have Entered Wrong Choice ";			
		}	
	}while(ch_h!=3);
	return 0;
}
