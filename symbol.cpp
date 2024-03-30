#include "symbol.h"
#include <iostream>
#include <string.h>
#include <fstream>
bool symbol::keyword(string s)
{
    if(s=="auto"){cout<<"<auto>";return true;}
    else if(s=="struct"){cout<<"<struct>";return true;}
    else if(s=="break"){cout<<"<break>";return true;}
    else if(s=="continue"){cout<<"<continue>";return true;}
    else if(s=="switch"){cout<<"<switch>";return true;}
    else if(s=="case"){cout<<"<case>";return true;}
    else if(s=="enum"){cout<<"<enum>";return true;}
    else if(s=="register"){cout<<"<register>";return true;}
    else if(s=="typedef"){cout<<"<typedef>";return true;}
    else if(s=="extern"){cout<<"<extern>";return true;}
    else if(s=="return"){cout<<"<return>";return true;}
    else if(s=="union"){cout<<"<union>";return true;}
    else if(s=="const"){cout<<"<const>";return true;}
    else if(s=="default"){cout<<"<default>";return true;}
    else if(s=="goto"){cout<<"<goto>";return true;}
    else if(s=="sizeof"){cout<<"<sizeof>";return true;}
    else if(s=="volatile"){cout<<"<volatile>";return true;}
    else if(s=="static"){cout<<"<static>";return true;}
    else if(s=="if"){cout<<"<if>";return true;}
    else if(s=="else"){cout<<"<else>";return true;}
    else if(s=="while"){cout<<"<while>";return true;}
    else if(s=="for"){cout<<"<for>";return true;}
    else if(s=="do"){cout<<"<do>";return true;}
    else return false;
}
string symbol::datatype(string s)
{
    if(s=="int"){cout<<"<int>";return "int";}
    else if(s=="signed"){cout<<"<signed>";return "signed ";}
    else if(s=="unsigned"){cout<<"<unsigned>";return "unsigned ";}
    else if(s=="short"){cout<<"<short>";return "short ";}
    else if(s=="long"){cout<<"<long>";return "long ";}
    else if(s=="float"){cout<<"<float>";return "float";}
    else if(s=="double"){cout<<"<double>";return "double";}
    else if(s=="char"){cout<<"<char>";return "char";}
    else if(s=="void"){cout<<"<void>";return "void";}
    return "";
}
void symbol::punctuator(string s)
{
    if(s=="(")
        cout<<"<LB,(>";
    else if(s==")")
        cout<<"<RB,)>";
    else if(s=="{")
        cout<<"<LP,{>";
    else if(s=="}")
        cout<<"<RP,}>";
    else if(s==";")
        cout<<"<;>";
    else if(s==",")
        cout<<"<,>";
    else if(s==":")
        cout<<"<:>";
}
void symbol::identifier(string s,string &s1)
{
    string match;
    fstream fp1;
    char look[s.length()+1];
    strcpy(look,s.c_str());
    fp1.open("symbolId.txt",ios::in);
    if(fp1)
    {
        while(!fp1.eof())
        {
            int i;
            string input,s2;
            getline(fp1,input);
            char look[input.length()+1];
            strcpy(look,input.c_str());
            for(i=0;look[i]!='\0';i++)
            {
                if(look[i]!=' ')
                    s2+=look[i];
                else
                    break;
            }
            if(s2==s)
            {
                cout<<"<id,"<<look[i+1]<<">";
                goto x;
            }
        }
    }
    fp1.close();
    if(look[0]=='a' || look[0]=='A')
        match=look[0];
    else if(look[0]=='b' || look[0]=='B')
        match=look[0];
    else if(look[0]=='c' || look[0]=='C')
        match=look[0];
    else if(look[0]=='d' || look[0]=='D')
        match=look[0];
    else if(look[0]=='e' || look[0]=='E')
        match=look[0];
    else if(look[0]=='f' || look[0]=='F')
        match=look[0];
    else if(look[0]=='g' || look[0]=='G')
        match=look[0];
    else if(look[0]=='h' || look[0]=='H')
        match=look[0];
    else if(look[0]=='i' || look[0]=='I')
        match=look[0];
    else if(look[0]=='j' || look[0]=='J')
        match=look[0];
    else if(look[0]=='l' || look[0]=='L')
        match=look[0];
    else if(look[0]=='m' || look[0]=='M')
        match=look[0];
    else if(look[0]=='n' || look[0]=='N')
        match=look[0];
    else if(look[0]=='o' || look[0]=='O')
        match=look[0];
    else if(look[0]=='p' || look[0]=='P')
        match=look[0];
    else if(look[0]=='q' || look[0]=='Q')
        match=look[0];
    else if(look[0]=='r' || look[0]=='R')
        match=look[0];
    else if(look[0]=='s' || look[0]=='S')
        match=look[0];
    else if(look[0]=='t' || look[0]=='T')
        match=look[0];
    else if(look[0]=='u' || look[0]=='U')
        match=look[0];
    else if(look[0]=='v' || look[0]=='V')
        match=look[0];
    else if(look[0]=='w' || look[0]=='W')
        match=look[0];
    else if(look[0]=='x' || look[0]=='X')
        match=look[0];
    else if(look[0]=='y' || look[0]=='Y')
        match=look[0];
    else if(look[0]=='z' || look[0]=='Z')
        match=look[0];
    for(int i=1;look[i]!='\0';i++)
    {
        if(look[i]=='a' || look[i]=='A')
            match+=look[i];
        else if(look[i]=='b' || look[i]=='B')
            match+=look[i];
        else if(look[i]=='c' || look[i]=='C')
            match+=look[i];
        else if(look[i]=='d' || look[i]=='D')
            match+=look[i];
        else if(look[i]=='e' || look[i]=='E')
            match+=look[i];
        else if(look[i]=='f' || look[i]=='F')
            match+=look[i];
        else if(look[i]=='g' || look[i]=='G')
            match+=look[i];
        else if(look[i]=='h' || look[i]=='H')
            match+=look[i];
        else if(look[i]=='i' || look[i]=='I')
            match+=look[i];
        else if(look[i]=='j' || look[i]=='J')
            match+=look[i];
        else if(look[i]=='l' || look[i]=='L')
            match+=look[i];
        else if(look[i]=='m' || look[i]=='M')
            match+=look[i];
        else if(look[i]=='n' || look[i]=='N')
            match+=look[i];
        else if(look[i]=='o' || look[i]=='O')
            match+=look[i];
        else if(look[i]=='p' || look[i]=='P')
            match+=look[i];
        else if(look[i]=='q' || look[i]=='Q')
            match+=look[i];
        else if(look[i]=='r' || look[i]=='R')
            match+=look[i];
        else if(look[i]=='s' || look[i]=='S')
            match+=look[i];
        else if(look[i]=='t' || look[i]=='T')
            match+=look[i];
        else if(look[i]=='u' || look[i]=='U')
            match+=look[i];
        else if(look[i]=='v' || look[i]=='V')
            match+=look[i];
        else if(look[i]=='w' || look[i]=='W')
            match+=look[i];
        else if(look[i]=='x' || look[i]=='X')
            match+=look[i];
        else if(look[i]=='y' || look[i]=='Y')
            match+=look[i];
        else if(look[i]=='z' || look[i]=='Z')
            match+=look[i];
        else if(look[i]=='0' || look[i]=='1' || look[i]=='2' || look[i]=='3' || look[i]=='4' || look[i]=='5' || look[i]=='6' || look[i]=='7' || look[i]=='8' || look[i]=='9')
            match+=look[i];
    }
    fp1.open("symbolId.txt",ios::in);
    if(fp1)
    {
        if(match==s)
        {
            fp1.close();
            fp1.open("symbolId.txt",ios::app);
            countId++;
            cout<<"<id,"<<countId<<">";
            if(s1=="")
                fp1<<endl<<match<<" "<<countId<<" "<<"unknown";
            else
                fp1<<endl<<match<<" "<<countId<<" "<<s1;
        }
    }
    else
    {
        if(match==s)
        {
            fp1.close();
            fp1.open("symbolId.txt",ios::out);
            countId++;
            cout<<"<id,"<<countId<<">";
            if(s1=="")
                fp1<<match<<" "<<countId<<" "<<"unknown";
            else
                fp1<<match<<" "<<countId<<" "<<s1;
        }
    }
    x:
    fp1.close();
    s1="";
}
void symbol::procedure(string s,string &s1)
{
    string match;
    fstream fp1;
    char look[s.length()+1];
    strcpy(look,s.c_str());
    fp1.open("symbolProce.txt",ios::in);
    if(fp1)
    {
        while(!fp1.eof())
        {
            int i;
            string input,s2;
            getline(fp1,input);
            char look[input.length()+1];
            strcpy(look,input.c_str());
            for(i=0;look[i]!='\0';i++)
            {
                if(look[i]!=' ')
                    s2+=look[i];
                else
                    break;
            }
            if(s2==s)
            {
                cout<<"<proc,"<<look[i+1]<<">";
                goto x;
            }
        }
    }
    fp1.close();
    if(look[0]=='a' || look[0]=='A')
        match=look[0];
    else if(look[0]=='b' || look[0]=='B')
        match=look[0];
    else if(look[0]=='c' || look[0]=='C')
        match=look[0];
    else if(look[0]=='d' || look[0]=='D')
        match=look[0];
    else if(look[0]=='e' || look[0]=='E')
        match=look[0];
    else if(look[0]=='f' || look[0]=='F')
        match=look[0];
    else if(look[0]=='g' || look[0]=='G')
        match=look[0];
    else if(look[0]=='h' || look[0]=='H')
        match=look[0];
    else if(look[0]=='i' || look[0]=='I')
        match=look[0];
    else if(look[0]=='j' || look[0]=='J')
        match=look[0];
    else if(look[0]=='l' || look[0]=='L')
        match=look[0];
    else if(look[0]=='m' || look[0]=='M')
        match=look[0];
    else if(look[0]=='n' || look[0]=='N')
        match=look[0];
    else if(look[0]=='o' || look[0]=='O')
        match=look[0];
    else if(look[0]=='p' || look[0]=='P')
        match=look[0];
    else if(look[0]=='q' || look[0]=='Q')
        match=look[0];
    else if(look[0]=='r' || look[0]=='R')
        match=look[0];
    else if(look[0]=='s' || look[0]=='S')
        match=look[0];
    else if(look[0]=='t' || look[0]=='T')
        match=look[0];
    else if(look[0]=='u' || look[0]=='U')
        match=look[0];
    else if(look[0]=='v' || look[0]=='V')
        match=look[0];
    else if(look[0]=='w' || look[0]=='W')
        match=look[0];
    else if(look[0]=='x' || look[0]=='X')
        match=look[0];
    else if(look[0]=='y' || look[0]=='Y')
        match=look[0];
    else if(look[0]=='z' || look[0]=='Z')
        match=look[0];
    for(int i=1;look[i]!='\0';i++)
    {
        if(look[i]=='a' || look[i]=='A')
            match+=look[i];
        else if(look[i]=='b' || look[i]=='B')
            match+=look[i];
        else if(look[i]=='c' || look[i]=='C')
            match+=look[i];
        else if(look[i]=='d' || look[i]=='D')
            match+=look[i];
        else if(look[i]=='e' || look[i]=='E')
            match+=look[i];
        else if(look[i]=='f' || look[i]=='F')
            match+=look[i];
        else if(look[i]=='g' || look[i]=='G')
            match+=look[i];
        else if(look[i]=='h' || look[i]=='H')
            match+=look[i];
        else if(look[i]=='i' || look[i]=='I')
            match+=look[i];
        else if(look[i]=='j' || look[i]=='J')
            match+=look[i];
        else if(look[i]=='l' || look[i]=='L')
            match+=look[i];
        else if(look[i]=='m' || look[i]=='M')
            match+=look[i];
        else if(look[i]=='n' || look[i]=='N')
            match+=look[i];
        else if(look[i]=='o' || look[i]=='O')
            match+=look[i];
        else if(look[i]=='p' || look[i]=='P')
            match+=look[i];
        else if(look[i]=='q' || look[i]=='Q')
            match+=look[i];
        else if(look[i]=='r' || look[i]=='R')
            match+=look[i];
        else if(look[i]=='s' || look[i]=='S')
            match+=look[i];
        else if(look[i]=='t' || look[i]=='T')
            match+=look[i];
        else if(look[i]=='u' || look[i]=='U')
            match+=look[i];
        else if(look[i]=='v' || look[i]=='V')
            match+=look[i];
        else if(look[i]=='w' || look[i]=='W')
            match+=look[i];
        else if(look[i]=='x' || look[i]=='X')
            match+=look[i];
        else if(look[i]=='y' || look[i]=='Y')
            match+=look[i];
        else if(look[i]=='z' || look[i]=='Z')
            match+=look[i];
        else if(look[i]=='0' || look[i]=='1' || look[i]=='2' || look[i]=='3' || look[i]=='4' || look[i]=='5' || look[i]=='6' || look[i]=='7' || look[i]=='8' || look[i]=='9')
            match+=look[i];
    }
    fp1.open("symbolProce.txt",ios::in);
    if(fp1)
    {
        if(match==s)
        {
            fp1.close();
            fp1.open("symbolProce.txt",ios::app);
            countProce++;
            cout<<"<proc,"<<countProce<<">";
            if(s1=="")
                fp1<<endl<<match<<" "<<countProce<<" "<<"unknown";
            else
                fp1<<endl<<match<<" "<<countProce<<" "<<s1;
        }
    }
    else
    {
        if(match==s)
        {
            fp1.close();
            fp1.open("symbolProce.txt",ios::app);
            countProce++;
            cout<<"<proc,"<<countProce<<">";
            if(s1=="")
                fp1<<match<<" "<<countProce<<" "<<"unknown";
            else
                fp1<<match<<" "<<countProce<<" "<<s1;
        }
    }
    x:
    fp1.close();
    s1="";
}
void symbol::relop(string s)
{
    if(s=="==")
        cout<<"<relop,==>";
    else if(s=="<=")
        cout<<"<relop,<=>";
    else if(s==">=")
        cout<<"<relop,>=>";
    else if(s=="<")
        cout<<"<relop,<>";
    else if(s==">")
        cout<<"<relop,>>";
    else if(s=="!=")
        cout<<"<relop,!=>";
    else if(s=="=")
        cout<<"<=>";
}
void symbol::binop(string s)
{
    if(s=="+")
        cout<<"<+>";
    else if(s=="-")
        cout<<"<->";
    else if(s=="*")
        cout<<"<*>";
    else if(s=="/")
        cout<<"</>";
    else if(s=="%")
        cout<<"<%>";
}
void symbol::num(string s)
{
    string match="";
    int flag=0;
    char look[s.length()+1];
    strcpy(look,s.c_str());
    for(int i=0;look[i]!='\0';i++)
        if(look[i]=='.' || look[i]=='0' || look[i]=='1' || look[i]=='2' || look[i]=='3' || look[i]=='4' || look[i]=='5' || look[i]=='6' || look[i]=='7' || look[i]=='8' || look[i]=='9')
        {
            match+=look[i];
            flag=1;
        }
    if(flag==1)
        cout<<"<num,"<<match<<">";
}
int symbol::countId=0;
int symbol::countProce=0;
