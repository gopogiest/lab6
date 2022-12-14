#ifndef GRAPHSTORE_H
#define GRAPHSTORE_H
#include <string>
#include <fstream>
#include "graph.h"
using namespace std;
class graphstore
{
    protected:
        int max_num_pictures;
        int max_num_author_pictures;
        int num_pictures;
        int num_auth_pictures;
        graph *gr;
        graph picture_for_comparision;
        pictures_of_nature *authors_pictures;
        pictures_of_nature auth_picture_for_comparision;

    public:
        graphstore(unsigned int max_np, unsigned int max_np_auth);
        ~graphstore();
        void comparision(string filename);
        void comparision_auth_pictures(string filename);
        void add_picture(graph picture);
        void add_auth_picture(pictures_of_nature apicture);
        void read_from_file(string filename);
        void read_from_file_author_pictures(string filename);
        void write_to_file(string filename);
        void write_to_file_authors_puctures(string filename);
        void find(char x);
        void delete_picture(int number);
        void delete_author_picture(int number);
        void seq();
        void read_from_file_compare_picture(string filename);
        void read_from_file_compare_author_picture(string filename);
        void add_compare_picture(graph new_graph);
        void add_auth_compare_picture(pictures_of_nature apicture);

        void operator+=(const string filename);

        friend ostream& operator<<(ostream& stream, const graphstore& astore);
};
#endif
