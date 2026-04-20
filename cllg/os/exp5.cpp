#include<iostream>
using namespace std;

int main(){
	int n,m;
	cout<<"\nEnter number of processes:";
	cin>>n;
	
	cout<<"\nEnter number of resources:";
	cin>>m;
	
	int alloc[n][m];
	int max[n][m];
	int need[n][m];
	int avail[m];
	
	cout<<"\nEnter Allocation matrix:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>alloc[i][j];
		}
	}
	
	cout<<"\nEnter Max matrix:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>max[i][j];
		}
	}
	
	cout<<"\nEnter Available Resources :\n";
	for(int j=0;j<m;j++){
		cin>>avail[j];
	}
	
	//calculate Need Matrix= max- allocation
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	
	bool finish[n];
	for(int i=0;i<n;i++)
		finish[i]=false;
	
	int safeSeq[n];
	int work[m];
	
	for(int j=0;j<m;j++)
		work[j]=avail[j];
		
	int count=0;
	while(count<n){
		bool found=false;
		
		for(int i=0;i<n;i++){
		
			if(finish[i]==false){
				bool possible=true;
				for(int j=0;j<m;j++){
					if(need[i][j]>work[j]){
						possible=false;
						break;
					}
				}
				if(possible){
					for(int j=0;j<m;j++)
						work[j]+=alloc[i][j];
					safeSeq[count]=i;
					count++;
					
					finish[i]=true;
					found=true;	
				}
			}
		}
		if(found==false){
			cout<<"\nSystem is NOT in Safe State\n";
			return 0;
		}
	}		
	cout<<"\nSystem is  in Safe State\n";
	cout<<"\n Safe Sequence: ";
	for(int i=0;i<n;i++)
		cout<<"p"<<safeSeq[i]<<" ";
		
	cout<<endl;
	return 0;	
	
}
 
 
 
 
 
 
 
 
 
 
   
 
  
             