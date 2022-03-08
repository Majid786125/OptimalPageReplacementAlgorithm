#include <iostream>

using namespace std;
void Print(int PA[],int FA[],int Fsize,int Psize)
{
    cout<<endl;
    cout<<"Current Frame is : ";
    for(int i=0;i<Fsize;i++)
    {
        cout<<FA[i];
        cout<<" ";
    }

cout<<endl;
   /* cout<<"All Page Number Are : ";
     for(int i=0;i<Psize;i++)
     {
         cout<<PA[i];
         cout<<" ";
     }

     cout<<endl;*/
}
bool Same(int FA[],int FN,int P)
{
    bool flage= false;
    for (int i = 0; i < FN; ++i) {
        if(FA[i]==P)
        {
            flage= true;
            break;
        }
    }
    return flage;
}
int Index(int FA[],int PA[],int FN,int i,int PN)
{
    int max[FN],MaxN,index=0;
    for (int j = 0; j < FN; ++j) {
        for (int k = i; k < PN; ++k) {
            if(FA[j]==PA[k])
            {
                max[j]=k;
                break;
            }
        }
    }
    MaxN=max[0];
    for(int i=0;i<FN;i++)
    {
        if(MaxN<max[i])
        {
            MaxN=max[i];
            index=i;
        }
    }
    return index;
}
int Fault(int PA[],int FA[],int PN,int FN)
{
    int Tfault=0,P;
    for(int i=0;i<PN;i++)
    {
        if(i>=FN)
        {
        P=PA[i];
        if(!Same(FA,FN,P))
        {
            int I= Index(FA,PA,FN,i,PN);
            FA[I]=P;
            Tfault++;
            Print(PA,FA,FN,PN);
        }
    }
        else
        {
           FA[i]=PA[i];
           Tfault++;
           Print(PA,FA,FN,PN);
        }
    }
   // cout<<endl;
    Print(PA,FA,FN,PN);
    return Tfault;
}
int main() {
    int NP, NF, P;

    cout << "Enter Number of Page :";
    cin >> NP;
    int PA[NP];
    cout << "Enter Number of Frames : ";
    cin >> NF;
    int FA[NF];
    for (int i = 0; i < NP; ++i) {
        cout << "Enter Page Number : ";
        cin >> P;
        PA[i] = P;
    }
    for (int i = 0; i < NF; i++)
    {
        FA[i]=-1;
    }
    int T= Fault(PA,FA,NP,NF);
    cout<<"Total Fault are : "<<T<<endl;
    cout<<"Total No of hits ="<<NP-T<<endl;
    cout<<"Page Fault Percentage ="<<(T*100)/NP;

}