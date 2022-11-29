#ifndef GRAPHSTORE_H
#define GRAPHSTORE_H
#include <string>
#include <fstream>
#include "graph.h"
using namespace std;
class graphstore
{
    private:
        int max_num_pictures;
        int num_pictures;
        graph *gr;
        graph picture_for_comparision;
    public:
        graphstore(unsigned int max_np);
        ~graphstore();
        void comparision(string filename);
        void add_picture(graph picture);
        void read_from_file(string filename);
        void write_to_file(string filename);
        void find(char x);
        void delete_picture(int number);
        void seq();
        void read_from_file_compare_picture(string filename);
        void add_compare_picture(graph new_graph);

        void operator+=(const graph &picture);
        friend ostream& operator<<(ostream& stream, const graphstore& astore);
};
#endif
