#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "graphstore.h"

using namespace std;
graphstore :: graphstore (unsigned int max_np, unsigned int max_np_auth)
{
    max_num_pictures = max_np;
    max_num_author_pictures = max_np_auth;
    gr = new graph[max_num_pictures];
    authors_pictures = new pictures_of_nature[max_num_author_pictures];
    num_auth_pictures = 0;
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
    max_num_author_pictures = 0;
    delete[] authors_pictures;
    num_auth_pictures = 0;
    cout << "\n Destructor of graphstore:";
    cout << "\n memory deleted";
}
void graphstore::operator+=(const string filename)
{
    if (filename!="auth_picture.txt"){
        read_from_file(filename);
    }
    else read_from_file_author_pictures(filename);

}
void graphstore::add_auth_picture(pictures_of_nature apicture)
{
    if (num_auth_pictures < max_num_author_pictures)
        {
            authors_pictures[num_auth_pictures] = apicture;
            num_auth_pictures++;
        }
}
void graphstore::add_picture(graph new_graph)
{
    if (num_pictures < max_num_pictures)
        {
            gr[num_pictures] = new_graph;
            num_pictures++;
        }
        else cout<<"\nToo many pictures in graphstore!"<<endl;
}
void graphstore::add_compare_picture(graph new_graph)
{
            picture_for_comparision = new_graph;
}
void graphstore :: add_auth_compare_picture(pictures_of_nature apicture)
{
    auth_picture_for_comparision = apicture;
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
void graphstore :: comparision_auth_pictures(string filename)
{
    read_from_file_compare_author_picture(filename);
    bool found = false;
    for (int i=0;i<num_auth_pictures;i++){
            if (authors_pictures[i]==auth_picture_for_comparision){
                found=true;
                if (found==true){
                    cout<<"\nWe have found a picture!"<<endl;
                    cout<<authors_pictures[i]<<endl;
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
void graphstore :: read_from_file_author_pictures(string filename)
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
            pictures_of_nature apicture;
            file>>apicture;
            add_auth_picture(apicture);
        }
    file.close();
    cout<< "\n Number of added pictures:"<< num_auth_pictures;
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
void graphstore :: read_from_file_compare_author_picture(string filename)
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
            pictures_of_nature apicture;
            file>>apicture;
            add_auth_compare_picture(apicture);
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
void graphstore :: write_to_file_authors_puctures (string filename)
{
    ofstream outfile;
    outfile.open(filename);
    outfile << num_auth_pictures << endl;
    for (int i=0;i<num_auth_pictures;i++)
        {
            outfile<<authors_pictures[i];
        }
    outfile.close();
    cout << "\nnumber of writed authors pictures: "<< num_auth_pictures;
}
ostream& operator<<(ostream& stream, const graphstore& astore)
{
    cout << "\n\nAll pictures: \n";
    for (int i=0;i<astore.num_pictures;i++)
        {
            if (astore.gr[i].get_name()!=string())
                stream << astore.gr[i]<<endl;
        }
    cout <<"\n\nAll author's pictures:\n";
    for (int i=0;i<astore.num_pictures;i++)
        {
            if (astore.authors_pictures[i].get_name()!=string())
                stream << astore.authors_pictures[i]<<endl;
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
    if (temp==1){
        for (int i=0;i<10;i++)
            {
                u1=authors_pictures[i].get_name();
                u2=u1[0];
                if (u2==x)
                    {
                        cout<<authors_pictures[i]<<endl;
                        count+=1;
                    }
            }
    }
    else if (temp==2)
        {
            for (int i=0;i<10;i++)
            {
                find=authors_pictures[i].get_name();
                if ((find[find.length()-1]) == x){
                    cout<<authors_pictures[i]<<endl;
                    count+=1;
                    u2=' ';
                }

            }
        }
        if (temp==1){
        for (int i=0;i<10;i++)
            {
                u1=gr[i].get_name();
                u2=u1[0];
                if (u2==x)
                    {
                        cout<<gr[i]<<endl;
                        count+=1;
                    }
            }
    }
    else if (temp==2)
        {
            for (int i=0;i<10;i++)
            {
                find=gr[i].get_name();
                if ((find[find.length()-1]) == x){
                    cout<<gr[i]<<endl;
                    count+=1;
                    u2=' ';
                }

            }
        }
    if (count==0) cout << "NET TAKIH KARTINOK!";
}
void graphstore ::  delete_picture(int number)
{
    gr[number].del_picture();
    //delete[] &gr[number];
}
void graphstore :: delete_author_picture(int number)
{
    authors_pictures[number].del_author_picture();
}
void graphstore :: seq()
{
    gr[0].pl(gr);
    authors_pictures[0].sequence(authors_pictures);
}

