#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <fstream>
#include <cstring>
using std::string;
using std::ifstream;
using std::ofstream;
class graph
{
    private:
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
        void set_mas(ifstream &file);
        static int pl(graph[]);
        void get_into(ofstream &file);
        void del_picture();
};
#endif
