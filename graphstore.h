#ifndef GRAPHSTORE_H
#define GRAPHSTORE_H
#include <string>
#include <fstream>
#include "graph.h"
class graphstore
{
    private:
        int max_num_pictures;
        int num_pictures;
        graph *gr;
    public:
        graphstore(unsigned int max_np);
        ~graphstore();
        void add_picture(graph picture);
        void read_from_file(string filename);
        void write_to_file(string filename);
        void display_all();
        void find(char x);
        void delete_picture(int number);
        void seq();
};
#endif
