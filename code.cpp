#include<iostream>
#include<fstream>
#include<sstream>
#define max 100000
using namespace std;
struct frequency
{
    int freq;
    string quad;
};

int main()
{
    struct frequency a[max],b[max];
    fstream file;
    string word,t,q,filename;
    int cnt=1,n,i=0,mx=0;
    cout<<"Enter filename : ";
    cin>>filename;
    file.open (filename.c_str());
    while (file >> word)
    {
        int len=word.size();
        for(int i=0; i<len; i++)
        {
            for(int k=33; k<=47; k++)
            {
                if(int(word[i])==33)//if an exclamation
                {
                    if(isalpha(word[i-1]))
                        break;
                    else
                        word[i]=' ';
                }
                if(int(word[i])==36)        //if $
                {
                    if(isdigit(word[i+1]))
                        break;
                    else
                        word[i]=' ';
                }
                if(int(word[i])==38)    //if &
                {
                    if(isdigit(word[i-1])&&isdigit(word[i+1])||isalpha(word[i-1])&&isalpha(word[i+1]))
                        break;
                    else
                        word[i]=' ';
                }
                if(int(word[i])==39)           //if '
                {
                    if(isalpha(word[i-1])&&isalpha(word[i+1]))
                        break;
                    else
                        word[i]=' ';

                }
                if(int(word[i])==42)        //if *
                {
                    if(isdigit(word[i-1])&&isdigit(word[i+1]))
                        break;
                    else
                        word[i]=' ';

                }
                if(int(word[i])==43)         //if +
                {
                    if(isdigit(word[i-1])&&isdigit(word[i+1]))
                        break;
                    else
                        word[i]=' ';

                }

                if(int(word[i])==k)
                    word[i]=' ';
            }

            for(int k=58; k<=64; k++)
            {
                if(int(word[i])==64)    //@
                {
                    if(isalpha(word[i-1])&&isalpha(word[i+1]))
                        break;
                    else
                        word[i]=' ';

                }
                if(int(word[i])==k)
                    word[i]=' ';
            }
            for(int k=91; k<=96; k++)
            {
                if(int(word[i])==95)  //_
                {
                    if(isalpha(word[i-1])&&isalpha(word[i+1]))
                        break;
                    else
                        word[i]=' ';

                }
                if(int(word[i])==k)
                    word[i]=' ';
            }
            for(int k=123; k<=126; k++)
            {
                if(int(word[i])==k)
                    word[i]=' ';
            }
            //word[i]=' ';
            word[i]=tolower(word[i]);

        }
        t=t+word+" ";
    }
    istringstream iss(t);
    while(iss >> word)
    {
        b[i].quad=word;
        i++;
    }
    n=i;
    for(int i=0; i<n-3; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(cnt%4!=0)
            {
                a[i].quad+=b[j].quad+' ';
                cnt++;
            }
            else
            {
                a[i].quad+=b[j].quad+' ';
                cnt=1;
                break;
            }

        }

    }
    for(int i=0; i<n-3; i++)
    {
        cout<<a[i].quad<<endl;
    }
    for(int i=0; i<n-3; i++)
    {
        int c=1;
        for(int j=1; j<n; j++)
            if(a[i].quad==a[j].quad)
            {
                a[i].freq=c++;
            }
    }
    for(int i=0; i<n-3; i++)
    {
        cout<<a[i].quad<<" "<<a[i].freq<<endl;
    }
    mx=0;
    for(int i=1; i<n-3; i++)
    {
        if(a[mx].freq<a[i].freq)
            mx=i;
    }
    cout<<endl<<a[mx].quad<<" "<<a[mx].freq<<endl;
}



