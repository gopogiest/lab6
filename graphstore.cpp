#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "graphstore.h"

using namespace std;
graphstore :: graphstore (unsigned int max_np)
{
    max_num_pictures = max_np;
    gr = new graph[max_num_pictures];
    num_pictures = 0;
    cout << "\n Vyzvan constructor graphstore:";
    cout << "\n Vydeleno objects - " << max_num_pictures;
    cout << "\n number of loaded pictures - " << num_pictures << endl;
}
graphstore :: ~graphstore()
{
    max_num_pictures = 0;
    delete[] gr;
    num_pictures = 0;
    cout << "\n Destructor of graphstore:";
    cout << "\n memory deleted";
}
void graphstore :: add_picture(graph picture)
{
    if (num_pictures < max_num_pictures)
        {
            gr[num_pictures] = picture;
            num_pictures++;
        }
}
void graphstore :: read_from_file(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open())
        {
            cout << "\n\n File don't exist!"<< endl;
            exit(1);
        }
    int N;
    infile >> N;
    infile.get();
    for (int i=0; i<N; i++)
        {
            graph new_graph;
            new_graph.set_mas(infile);
            add_picture(new_graph);
        }
    infile.close();
    cout<< "\n Number of added pictures:"<< num_pictures;
}
void graphstore :: write_to_file (string filename)
{
    ofstream outfile;
    outfile.open(filename);
    outfile << num_pictures << endl;
    for (int i=0;i<num_pictures;i++)
        {
            gr[i].get_into(outfile);
        }
    outfile.close();
    cout << "\nnumber of writed pictures: "<< num_pictures;
}
void graphstore :: display_all()
{
    cout << "\n\nAll pictures: \n";
    for (int i=0;i<num_pictures;i++)
        {
            if (gr[i].get_name()!=string())
                gr[i].out();
        }
}
void graphstore::find(char x)
{
    int temp=0,count=0;
    string u1=" ";
    char u2=' ';
    string find=" ";
    cout << "Vvedite variant zadania (1-2): ";
    cin >> temp;
    while((temp!=1)&&(temp!=2))
        {
            cout << "Neverno vvedeny dannye!\n";
            exit(1);
        }
    cout << "\n";
    if (temp==1)
        for (int i=0;i<10;i++)
            {
                u1=gr[i].get_name();
                u2=u1[0];
                if (u2==x)
                    {
                        gr[i].out();
                    }
            }
    else if (temp==2)
        {
            for (int i=0;i<10;i++)
            {
                find=gr[i].get_name();
                if ((find[find.length()-1]) == x){
                    gr[i].out();
                    count+=1;
                    u2=' ';
                }

            }
            if (count==0) cout << "NET TAKIH FAILOV!";
        }
}
void graphstore ::  delete_picture(int number)
{
    gr[number].del_picture();
    //delete[] &gr[number];
}
void graphstore :: seq()
{
    gr[0].pl(gr);
}
