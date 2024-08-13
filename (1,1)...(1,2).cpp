//A_1=1,A_2=1
//(a,b)=(1,2)
//1 1 3 5 11 21 43 85 171
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string encode(char letter);//char->int
char decode(string num);//int->char
string funn(int a);

int main(){
    int i,j;
    string n;
    string x;
    char outext;
    vector<string> x2;
    char st;
    while(1)
    {
        cout<<endl;
        cout<<"Encode or Declode(E or D)?"<<endl;
        cin>>st;
        if(st=='0')break;
        else if(st=='E'||st=='e')
        {
            cout<<"INPUT TEXT"<<endl;
            cin.ignore();
            getline(cin,x);
            cout<<endl<<"OUTPUT CODE"<<endl;
            for(i=0;i<x.length();i++)
            {
                cout<<encode(x[i])<<endl;
            }
        }
        else if(st=='d'||st=='D')
        {
            cout<<"INPUT CODE"<<endl;
            i=0;
            x2.clear();
            while(1)
            {
                cin>>x;
                if(x=="0")break;
                x2.push_back(x);
            }
            cout<<endl<<"INPUT TEXT"<<endl;
            for(i=0;i<x2.size();i++)
            {
                outext=decode(x2[i]);
                cout<<outext;
            }
        }
        cout<<endl;

    }
}


string encode(char letter){//char->int  ***I LOVE MATH->73 32 76 79 86 69 32 77 65 84 72
    int i,j,c=0;
    string ans;
    string n;
    n =  funn(letter);
    int legg=n.length();
    for(i=1;i<=9;i++){
        if(int(n[c])-48==i){
            ans+='1';
            c++;
        }
        else{
            ans+='0';
        }
    }
//    cout<<n<<endl;
    return ans;
}


char decode(string num){//int->char  ***73 32 76 79 86 69 32 77 65 84 72  ->  I LOVE MATH
    int i,sum=0;
    for(i=0;i<9;i++)
    {
        if(num[i]=='1')
        {
            if(i==0||i==1)sum+=1;
            else if(i==2)sum+=3;
            else if(i==3)sum+=5;
            else if(i==4)sum+=11;
            else if(i==5)sum+=21;
            else if(i==6)sum+=43;
            else if(i==7)sum+=85;
            else if(i==8)sum+=171;
        }
    }
   return char(sum);
}


string funn(int a){
    char tmp;
    string tmp2="1";
    string b;
    int m_st[]={0,1,1,3,5,11,21,43,85,171};
    string mem ;
    int i,i_;
    for(i=9;i>0;i--){
        if(m_st[i]<=a)
        {
//            cout<<m_st[i]<<' '<<i<<endl;
            a=a-m_st[i];
            tmp=i+48;
            b.push_back(tmp);
            if(a==0){
                break;
            }
        }
    }
    reverse(b.begin(),b.end());
    if(int(b[0])%2==0)
    {
        for(i=2;i<(int(b[0])-48);i++)
        {
            tmp2=tmp2+char(i+48);
        }
        b.erase(b.begin());
        b=tmp2+b;
        return b;
    }
    else
    {
        return b;
    }
}


