#include <iostream>
#include <string>
#include <fstream>
#include <istream>
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
ifstream& operator>>(ifstream& file, graph& gr)
{
    getline(file,gr.name);
    file >> gr.size;
    getline(file,gr.format);
    file >> gr.width;
    file >> gr.height;
    file >> gr.dpi;
    file >> gr.depth;
    file.get();
    return file;
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
ofstream& operator<<(ofstream& file, const graph& gr)
{
    file << gr.name <<endl;
    file << gr.size<< endl;
    file << gr.format<< endl;
    file << gr.width <<endl;
    file << gr.height <<endl;
    file << gr.dpi << endl;
    file << gr.depth << endl;
    return file;
}
ostream& operator<<(ostream& stream, const graph& picture)
{
stream << picture.name;
stream << "\t" << picture.size;
stream << "\t" << picture.format;
stream << "\t" << picture.width;
stream << "\t" << picture.height;
stream << "\t" << picture.dpi;
stream << "\t" << picture.depth;
return stream;
}
istream& operator>>(istream& stream, graph& compare_picture)
{
getline(stream, compare_picture.name);
stream >> compare_picture.size;
getline(stream, compare_picture.format);
stream >> compare_picture.width;
stream >> compare_picture.height;
stream >> compare_picture.dpi;
stream >> compare_picture.depth;
stream.get();
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
bool graph::operator==(graph compare_picture)
{
    if ((name!=compare_picture.name)||
    (size!=compare_picture.size) ||
    (format!=compare_picture.format) ||
    (width!=compare_picture.width)  ||
    (height!=compare_picture.height) ||
    (dpi!=compare_picture.dpi)  ||
    (depth!=compare_picture.depth))
    return false;
    return true;
}
