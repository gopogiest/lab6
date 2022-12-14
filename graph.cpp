#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <cstdlib>
#include "graph.h"
#include "graphstore.h"
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

/*void graph:: out()
{
    cout << name <<"\t";
    cout << size <<"\t" ;
    cout << format;
    cout << "\t" << width;
    cout << "\t"<< height;
    cout << "\t"<< dpi;
    cout << "\t"<< depth << endl;
}*/
/*void graph :: out_auth_picture(pictures_of_nature apicture)
{
    cout << apicture.name<< "\t";
    cout << apicture.size << "\t";
    cout << apicture.format <<"\t";
    cout << "\t"<< apicture.width;
    cout << "\t" << apicture.height;
    cout << "\t"<< apicture.dpi;
    cout << "\t"<< apicture.depth;
    cout << "\t" << apicture.place;
    cout << "\t" << apicture.author;


}*/
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
    file << gr.name;
    file << gr.size;
    file << gr.format;
    file << gr.width;
    file << gr.height;
    file << gr.dpi;
    file << gr.depth;
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
istream& operator>>(istream& stream, graph& picture)
{
getline(stream, picture.name);
stream >> picture.size;
getline(stream, picture.format);
stream >> picture.width;
stream >> picture.height;
stream >> picture.dpi;
stream >> picture.depth;
stream.get();
return stream;
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
/*методы класса-наследника*/


pictures_of_nature::pictures_of_nature(string nm, int sz, string frt, int wdt, int hght, int dp, int dpt, string plc, string auth) :
graph(nm, sz,frt,wdt, hght,dp,dpt), place(plc), author(auth)
{
    cout<<"\nConstructor of class-daughter";
}
bool pictures_of_nature :: operator==(pictures_of_nature author_picture)
{
    if ((name!=author_picture.name)||
    (size!=author_picture.size) ||
    (format!=author_picture.format) ||
    (width!=author_picture.width)  ||
    (height!=author_picture.height) ||
    (dpi!=author_picture.dpi)  ||
    (depth!=author_picture.depth)||
    (place!=author_picture.place)||
    author!=author_picture.author)
    return false;
    return true;
}
ostream& operator<<(ostream &stream, const pictures_of_nature& picture)
{
    stream << static_cast<graph>(picture);
    stream << "\t\t" << picture.place;
    stream << "\t\t" << picture.author;
    return stream;
}
istream& operator>>(istream& stream, pictures_of_nature& picture)
{
    stream >> static_cast<graph&>(picture);
    getline(stream,picture.place);
    getline(stream,picture.author);
    return stream;
}
ofstream& operator<<(ofstream &stream, const pictures_of_nature& picture)
{
    stream << static_cast<graph>(picture);
    stream << picture.place;
    stream << picture.author;
    return stream;
}
ifstream& operator>>(ifstream &stream, pictures_of_nature& apicture)
{
    stream >> static_cast<graph&>(apicture);
    getline(stream, apicture.place);
    getline(stream, apicture.author);
    return stream;
}
void pictures_of_nature:: del_author_picture()
{
    name=string();
    size=int();
    format=string();
    width=int();
    height=int();
    dpi=int();
    depth=int();
    place=string();
    author=string();
}
int pictures_of_nature::sequence(pictures_of_nature authors_pictures[])
{
    int plos[10];
    int max=0;
    int num=0;
    for (int y=0;y<10;y++)
        {
            plos[y]=((authors_pictures[y].dpi*authors_pictures[y].height)*authors_pictures[y].width);
            if(plos[y]>max)
            {
                max=plos[y];
                num=y;
           }
        }
    cout << "\nSamaya bolshaya ploshad u izobrazheniya:  "<<authors_pictures[num].name<<"\t";
    cout << max << endl;
}
