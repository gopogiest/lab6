#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <fstream>
#include <cstring>
using std::string;
using std::ifstream;
using std::ofstream;
using namespace std;
class graph
{
    protected:
        string name;
        int size;
        string format;
        int width;
        int height;
        int dpi;
        int depth;
    public:
        graph() : name(""), size(0), format(""),width(0),height(0),dpi(0),depth(0){};
        graph (string, int, string,int, int,int,int);
        string get_name();
        void out();
        static int pl(graph[]);
        void del_picture();


        friend ofstream& operator<<(ofstream& file, const graph& gr);
        friend ifstream& operator>>(ifstream& stream, graph& gr);
        friend ostream& operator<<(ostream& stream, const graph& picture);
        friend istream& operator>>(istream& stream, graph& picture);
        bool operator==(graph picture);
};
class pictures_of_nature : public graph
{
    protected:
        string place;
        string author;
    public:
        pictures_of_nature(): graph(), place(""), author("") {};
        pictures_of_nature(string, int, string,int, int,int,int, string, string);
        bool operator==(pictures_of_nature author_picture);
        void del_author_picture();
        int sequence(pictures_of_nature authors_pictures[]);
        friend ofstream& operator<<(ofstream &stream, const pictures_of_nature& gr);
        friend ifstream& operator>>(ifstream &stream, pictures_of_nature& apicture);
        friend ostream& operator<<(ostream &stream, const pictures_of_nature& picture);
        friend istream& operator>>(istream &stream, pictures_of_nature& picture);
};
#endif
