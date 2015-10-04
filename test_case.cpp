#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#define _FSTREAM
#ifdef _FSTREAM
    /* you'd better not rewrite these 2 files */
    std::ifstream fin;
    std::ofstream fout("f.out");
#else
    #define fin std::cin
    #define fout std::cout
#endif // _FSTREAM

void init(){
    int cnt = 0;
    int high = 0;
    long int gen = 0;

    #ifdef _FSTREAM
        std::ofstream fgen("f.in");
        srand(time(NULL));
        while( ( cnt = rand() ) < 10000 );
        while( cnt-- ){
            high = rand();
            if( high & (1<<14) )
                gen = ( ( high << 16 ) | rand() ) % INT_MAX - ( INT_MAX >> 1 ) - ( INT_MAX >> 2 ) ;
            else
                gen = rand();
            gen = gen > LONG_MAX ? LONG_MAX - 1 : gen;
            gen = gen < LONG_MIN ? LONG_MIN + 1 : gen;
            fgen<<gen<<std::endl;
        }
        fgen.close();
        fin.open("f.in");
    #endif // _FSTREAM
    return;

}

void SendByte(char c){
    fout<<c;
}

void Test(long int &_in,long int &_ref){
    int cnt = 0 , ccnt = 0 , wcnt = 0;

    #ifdef _FSTREAM
        fout.close();
        fin.close();
        fin.open("f.in");
        std::ifstream fref("f.out");
        while(fin>>_in){
            fref>>_ref;
            cnt++;
            if( _in != _ref ){
                wcnt++;
                std::cout<<"Case "<<cnt<<" : Wrong"<<std::endl
                         <<"Right: "<<_in<<std::endl
                         <<"Wrong: "<<_ref<<std::endl;
            }
        }
        std::cout<<wcnt<<" wrong answers in " <<cnt<<" cases."<<std::endl;
        if( !wcnt )
            std::cout<<"All cases passed."<<std::endl;
    #endif // _FSTREAM
    return;

}

int main(){
    long int in,ref;
    void SendInt(long int Dec);

    init();
    while(fin>>in)
        SendInt(in);
    Test(in,ref);

    return 0;
}

/*  Display methods for test cases, the input parameter is long int type, of course you can change it.
    if you wanna write a new line,using 'SendByte('\r')' and 'SendByte('\n')' in Windows                */
void SendInt(long int Dec){
    //TO DO
}

