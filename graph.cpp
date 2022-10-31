#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "graph.h"
using namespace std;

graph :: graph(string nm, int sz, string frt, int wdt, int hght, int dp, int dpt)
{
    name = nm;
    size = sz;
    format = frt;
    width = wdt;
    height = hght;
    dpi = dp;
    depth = dpt;
}

string graph:: get_name()
{
    return name;
}

void graph:: out()
{
    cout << name <<"\t";
    cout << size <<"\t" ;
    cout << format;
    cout << "\t" << width;
    cout << "\t"<< height;
    cout << "\t"<< dpi;
    cout << "\t"<< depth << endl;
}
void graph::set_mas (ifstream &file)
{
    getline(file,name);
    file >> size;
    getline(file,format);
    file >> width;
    file >> height;
    file >> dpi;
    file >> depth;
    file.get();
}
int graph::pl(graph gr[])
{
    int plos[10];
    int max=0;
    int num=0;
    for (int y=0;y<10;y++)
        {
            plos[y]=((gr[y].dpi*gr[y].height)*gr[y].width);
            if(plos[y]>max)
            {
                max=plos[y];
                num=y;
           }
        }
    cout << "\nSamaya bolshaya ploshad u izobrazheniya:  "<<gr[num].name<<"\t";
    cout << max << endl;
}
void graph::get_into(ofstream &file)
{
    file << name <<endl;
    file << size<< endl;
    file << format<< endl;
    file << width <<endl;
    file << height <<endl;
    file << dpi << endl;
    file << depth << endl;
}
void  graph :: del_picture()
{
    name=string();
    size=int();
    format=string();
    width=int();
    height=int();
    dpi=int();
    depth=int();
}
