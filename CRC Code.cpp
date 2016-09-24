#include<iostream>
#include<math.h>
using namespace std;
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i];
}
int main()
{
		int message2[100],message1[100],gp[100]={1,0,0,1,1},n=10,m=5,j,i;
		cout<<"\t\t\tSENDER\n";
		cout<<"Length of Message: ";
		cin>>n;
		cout<<"Enter Message Bits: ";
		for(i=0;i<n;i++)
			cin>>message1[i];
		cout<<"Length of Generator Polynomial: ";
		cin>>m;
		cout<<"Enter Message Bits: ";
		for(i=0;i<m;i++)
			cin>>gp[i];
		cout<<endl<<"Message Entered: ";
		display(message1,n);
		for(i=0;i<n;i++)
			message2[i]=message1[i];
		for(i=n;i<n+m-1;i++)
			message2[i]=0;
		cout<<endl<<"Generator Polynomial: ";
		display(gp,m);
		cout<<endl<<"Message padded with 0 bits: ";
		display(message2,n+m-1);
		cout<<endl<<"Quotient: ";
		for(i=0;i<n;i++)
		{
			if(message2[i]==1)
				{
					for(j=0;j<m;j++)
					message2[i+j]=(message2[i+j]^gp[j]);
					cout<<"1";
				}
			else 	cout<<"0";
		}
		cout<<endl<<"Reminder: ";
		display(message2,n+m-1);
		for(i=n;i<n+m-1;i++)
			message1[i]=message2[i];
		cout<<endl<<"Message Sent: ";
		display(message1,n+m-1);
		cout<<"\n\n\t\t\tRECEIVER\n";
		cout<<"Introduce Error?    1:YES    0:NO   Choice: ";
		cin>>i;
		if(i){
				cout<<"Enter Bit Position: ";
				cin>>i;
				message1[i-1]=1-message1[i-1];
				cout<<endl<<"Message With Error: ";
				display(message1,n+m-1);
			}
		for(i=0;i<n;i++)
		{
			if(message1[i]==1)
				for(j=0;j<m;j++)
					message1[i+j]=(message1[i+j]^gp[j]);
		}
		cout<<endl<<"Message Verification: ";
		display(message1,n+m-1);
          for(i=0;i<n+m-1;i++)
          if(message1[i]==1){cout<<endl<<"ERROR OCCURED";i=100;break;}
          if(i!=100)cout<<endl<<"NO ERROR OCCURED";
}
