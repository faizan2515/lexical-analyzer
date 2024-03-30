#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include <fstream>
using namespace std;

class symbol
{
    public:
        void identifier(string s,string &s1);
        void procedure(string s,string &s1);
        bool keyword(string s);
        string datatype(string s);
        void opt();
        void punctuator(string s);
        void relop(string s);
        void binop(string s);
        void num(string s);

    private:
        static int countId;
        static int countProce;
};

#endif // SYMBOL_H
