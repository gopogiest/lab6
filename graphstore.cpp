#include <string>
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
void graphstore::operator+=(const graph &picture)
{
    if (num_pictures < max_num_pictures)
        {
            gr[num_pictures] = picture;
            num_pictures++;
        }
}
void graphstore::add_picture(graph new_graph)
{
    if (num_pictures < max_num_pictures)
        {
            gr[num_pictures] = new_graph;
            num_pictures++;
        }
}
void graphstore::add_compare_picture(graph new_graph)
{
            picture_for_comparision = new_graph;
}
void graphstore::comparision(string filename)
{
    read_from_file_compare_picture(filename);
    bool found=false;
    for (int i=0;i<num_pictures;i++){
        if (gr[i]==picture_for_comparision){
            found=true;
            if(found==true){
                cout<<"\nWe have found a picture!"<<endl;
                cout<<gr[i]<<endl;
            }
        }
    }
    if (!found)
        cout<<"\nThere is no such pictures!"<<endl;
}
void graphstore :: read_from_file(string filename)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
        {
            cout << "\n\n File don't exist!"<< endl;
            exit(1);
        }
    int N;
    file >> N;
    file.get();
    for (int i=0; i<N; i++)
        {
            graph new_graph;
            file>>new_graph;
            add_picture(new_graph);
        }
    file.close();
    cout<< "\n Number of added pictures:"<< num_pictures;
}
void graphstore :: read_from_file_compare_picture(string filename)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
        {
            cout << "\n\n File don't exist!"<< endl;
            exit(1);
        }
    int N;
    file >> N;
    file.get();
    for (int i=0; i<N; i++)
        {
            graph new_graph;
            file>>new_graph;
            add_compare_picture(new_graph);
        }
    file.close();
}
void graphstore :: write_to_file (string filename)
{
    ofstream outfile;
    outfile.open(filename);
    outfile << num_pictures << endl;
    for (int i=0;i<num_pictures;i++)
        {
            outfile<<gr[i];
        }
    outfile.close();
    cout << "\nnumber of writed pictures: "<< num_pictures;
}
ostream& operator<<(ostream& stream, const graphstore& astore)
{
    cout << "\n\nAll pictures: \n";
    for (int i=0;i<astore.num_pictures;i++)
        {
            if (astore.gr[i].get_name()!=string())
                stream << astore.gr[i]<<endl;
        }
        return stream;
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
    if (temp==1){
        for (int i=0;i<10;i++)
            {
                u1=gr[i].get_name();
                u2=u1[0];
                if (u2==x)
                    {
                        gr[i].out();
                        count+=1;
                    }
            }
        if (count==0) cout << "NET TAKIH KARTINOK!";
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
            if (count==0) cout << "NET TAKIH KARTINOK!";
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

