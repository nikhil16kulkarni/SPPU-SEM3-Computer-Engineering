#include<bits/stdc++.h>
using namespace std;

struct student{
    
        int marks,rn;
        char name[50],pa;
    
}s[100];
        
    void read(int n){
        int i;
        for(int i=0;i<n;i++){
            cout<<"Enter Name of Student";
            cin>>s[i].name;
            cout<<"Enter Roll Number";
            cin>>s[i].rn;
            cout<<"Student is present or not?(Enter p if present & a if absent)";
            cin>>s[i].pa;
            if(s[i].pa=='p' || s[i].pa=='P'){
            	cout<<"Enter Marks";
                cin>>s[i].marks;
            }
            if(s[i].pa=='a' || s[i].pa=='A'){
                cout<<"This student is Absent"<<endl<<endl;
                s[i].marks==0;
            }
            else{
                cout<<"Invalid Choice Entered"<<endl<<endl;
            }
            
        }
    }
    
    float avg(int n){
        int i,sum=0;
        float av;
        for(int i=0;i<n;i++){
            sum=sum+s[i].marks;
        }
        av=sum/n;
        cout<<av<<endl;
        return 0;
    } 
    
    int max(int n){
        int ma=s[0].marks,i;
        for(int i=0;i<n;i++){
            if(ma<s[i].marks)   ma=s[i].marks;
        }
        cout<<ma<<endl;
        return 0;
    }
    
    int min(int n){
        int mi=s[0].marks,i;
        for(int i=0;i<n;i++){
            if(mi>s[i].marks)   mi=s[i].marks;
        }
        cout<<mi<<endl;
        return 0;
    }
    
    void abse(int n){
        int i;
        for(int i=0;i<n;i++){
            if(s[i].pa=='a' || s[i].pa=='A'){
                cout<<s[i].name<<endl;
            }
        }
    }
    
    int freq(int ar[],int n){
        int mc=1,res=ar[0],cc=1;
        for(int i=1;i<n;i++){
            if(ar[i]==ar[i-1])    cc++;
            else{
                if(cc>mc){
                    mc=cc;
                    res=ar[i-1];
                }
                cc=1;
            }
        }
            
        if(cc>mc){
            mc==cc;
            res=ar[n-1];
        }
        cout<<res;
        return 0;
    }

int main(){
    int n;
    cout<<"Enter Total no. of students";
    cin>>n;
    read(n);
    int ar[n];
    for(int i=0;i<n;i++)    ar[i]=s[i].marks;
    sort(ar,ar+n);
    cout<<"Average Score is : "<<endl;
    avg(n);
    cout<<"Highest Score is : "<<endl;
        max(n);
        cout<<"Lowest Score is : "<<endl;
        min(n);
        cout<<"List of Students who are absent is : ";
        abse(n);
    /*int ch,yn;
    cout<<"Enter choice:\n1.Calculate Average\n2.Highest score\n3.Lowest score\n4.Marks Scored by most of the students\5.List of Students who are Absent";
    do{
    switch(ch){
        case 1 : cout<<"Average Score is : "<<endl;
        avg(n);
        break;
        
        case 2 : cout<<"Highest Score is : "<<endl;
        max(n);
        break;
        
        case 3 : cout<<"Lowest Score is : "<<endl;
        min(n);
        break;
        
        case 4 : cout<<"List of Students who are absent is : ";
        abse(n);
        break;
        
        default : cout<<"Incorrect Choice Entered";
        break;
    }
    cout<<"Do you want to continue?(y/n)";
    cin>>yn;
    }while(yn=='Y' || yn=='y'); */
    
    
    
    
}
