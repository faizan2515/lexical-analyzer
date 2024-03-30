#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "stack.h"
#include "symbol.h"
using namespace std;
fstream fp;
int main()
{
    string input,cpy;
    int n;
    Stack* store=new Stack;
    symbol match;
    char lexemeForward;
    while(true)
    {
        getline(cin,input);
        fp.open("file.txt",ios::app);
        fp<<input<<endl;
        if(input=="int main()" || input=="void main()")
        {
            fp.close();
            input = "";
            break;
        }
        fp.close();
        input = "";
    }
    while(store->isEmpty() || store->top()=='{')
    {
        getline(cin,input);
        fp.open("file.txt",ios::app);
        fp<<input<<endl;
        char look[input.length()+1];
        strcpy(look,input.c_str());

        for(int i=0;i<=input.length();i++)
        {
            if(look[i]=='{')
                store->push('{');
            else if(look[i]=='}')
            {
                store->pop();
                if(store->isEmpty())
                    goto x;
            }
        }
        input="";
        fp.close();
    }
    x:
    fp.close();
    cout<<"\n";
    system("cls");
    fp.open("file.txt",ios::in);
    while(!fp.eof())
    {
        int i=0,j;
        getline(fp,input);
        char look[input.length()+1];
        strcpy(look,input.c_str());
        string s="",s1="";
        for(i=0;look[i]!='\0';i++)
        {
            j=i;
            lexemeForward=look[i];
            if(lexemeForward=='(')
            {
                if(match.keyword(s)==false)
                    match.procedure(s,s1);
                s="";
                s=look[i];
                match.punctuator(s);
                s="";
            }
            else if(lexemeForward==')' || lexemeForward==';' || lexemeForward=='{' || lexemeForward=='}' || lexemeForward==',' || lexemeForward==':')
            {
                match.keyword(s);
                match.identifier(s,s1);
                match.num(s);
                s="";
                s=look[i];
                match.punctuator(s);
                s="";
            }
            else if(lexemeForward=='=' || lexemeForward=='<' || lexemeForward=='>' || lexemeForward=='!')
            {
                match.identifier(s,s1);
                match.num(s);
                s="";
                s=lexemeForward;
                if(look[++j]=='=')
                {
                    s+=look[j];
                    match.relop(s);
                    s="";
                    i++;
                }
                else
                {
                    match.relop(s);
                    s="";
                }
            }
            else if(lexemeForward=='+' || lexemeForward=='-' || lexemeForward=='*' || lexemeForward=='/' || lexemeForward=='%')
            {
                match.identifier(s,s1);
                s="";
                s=look[i];
                match.binop(s);
                s="";
            }
            else if(lexemeForward=='"' || lexemeForward=='\'')
            {
                i++;
                cout<<"<\"literal\">";
                while(look[i]!='"' || look[i]!='\'')
                {
                    i++;
                    if(look[i]=='"' || look[i]=='\'')
                        break;
                }
            }
            else if(lexemeForward==' ')
            {
                match.keyword(s);
                s1=match.datatype(s);
                match.punctuator(s);
                cout<<" ";
                s="";
            }
            else if(lexemeForward=='\t')
            {
                match.keyword(s);
                match.punctuator(s);
                cout<<"\t";
                s="";
            }
            else
            {
                s+=lexemeForward;
            }
        }
        if(s!="")
        {
            match.keyword(s);
        }
        cout<<"\n";
    }
    fp.close();
    input="";
    do
    {
        cout<<"\n\t\t\t\t[1] Symbol Table";
        cout<<"\n\t\t\t\t[0] Exit";
        cout<<"\n\t\t\t\tEnter Your Choice :";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                system("cls");
                fstream fp1;
                string id[2];
                fp1.open("symbolId.txt",ios::in);
                cout<<"\tToken\tLexeme\tType"<<endl;
                if(fp1)
                {
                    while(!fp1.eof())
                    {
                        int j=0;
                        getline(fp1,input);
                        char look[input.length()+1];
                        strcpy(look,input.c_str());
                        for(int i=0;look[i]!='\0';i++)
                        {
                            if(look[i]!=' ')
                                cpy+=look[i];
                            else
                            {
                                id[j]=cpy;
                                j++;
                                cpy="";
                            }
                        }
                        cout<<id[1]<<"\t"<<"id"<<"\t"<<id[0]<<"\t"<<cpy<<endl;
                        cpy="";
                    }
                }
                fp1.close();
                fp1.open("symbolProce.txt",ios::in);
                if(fp1)
                {
                    while(!fp1.eof())
                    {
                        int j=0;
                        getline(fp1,input);
                        char look[input.length()+1];
                        strcpy(look,input.c_str());
                        for(int i=0;look[i]!='\0';i++)
                        {
                            if(look[i]!=' ')
                                cpy+=look[i];
                            else
                            {
                                id[j]=cpy;
                                j++;
                                cpy="";
                            }
                        }
                        cout<<id[1]<<"\t"<<"proc"<<"\t"<<id[0]<<"\t"<<cpy<<endl;
                        cpy="";
                    }
                }
                fp1.close();
                break;
            }
            case 0:
                break;
        }
    }
    while(n!=0 && n!=1);
    remove("file.txt");
    remove("symbolId.txt");
    remove("symbolProce.txt");
    return 0;
}
