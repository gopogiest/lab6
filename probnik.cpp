#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "graphstore.h"
using namespace std;
int main()
{
    /*int grlength=0;
    ifstream inp;
    inp.open("lab1.txt");
    inp >> N;
    gr = new graph[N];
    inp.get();
    while ((!inp.eof())&&(grlength<N))
        {
            gr[grlength].set_mas(inp);
            grlength++;
        }
    inp.close();
    cout << "Nachalnyi massiv:";
    cout << "\nName\tSize\tFormat\tWidth\tHeight\tdpi\tdepth\n\n";
    for (int i=0;i<N;i++)
        gr[i].out();
    char x;
    cout << "\nWrite the symbol: ";
    cin >> x;
    find(x, gr);
    for (int i=0;i<1;i++){
       gr[i].pl(gr);
    }
    for (int i=0;i<N;i++)
        gr[i].get_into(gr);
    delete[] gr;*/
    char x;
    int choice;
    graph picture;
    graphstore my_store(25);
    my_store.read_from_file("lab1.txt");
    my_store.display_all();
    my_store.seq();
    cout << "\n Write a letter:" << endl;
    cin >> x;
    my_store.find(x);
    // my_store.pl();
    cout << "\nDo u want to delete or add a new picture(1-2), or nothing of this? (3)" << endl;
    cin >> choice;
    while ((choice != 1) && (choice != 2) && (choice != 3))
    {
        cout << "\nWrong data! Try again:";
        cout << "\nDo u want to delete or add new picture (1-2), or nothing of this? (3)" << endl;
        cin >> choice;
    }
    if (choice == 2)
    {

        string file_name = "";
        cout << "\nWrite a name of the file: ";
        cin >> file_name;
        my_store.read_from_file(file_name);
        my_store.display_all();
        my_store.seq();
    }
    else if (choice == 1)
    {
        int number;
        cout << "\n Write which picture do you wanna remove: " << endl;
        cin >> number;
        my_store.delete_picture(number);
        my_store.display_all();
        my_store.seq();
    }
    my_store.write_to_file("Images.dat");

    return 0;
}
