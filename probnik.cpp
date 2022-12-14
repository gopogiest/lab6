#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "graphstore.h"
using namespace std;
int main()
{

    char x;
    int choice,number=0;
    graph picture;
    pictures_of_nature apicture;
    graphstore my_store(25,25);
    my_store.read_from_file("lab1.txt");
    my_store.read_from_file_author_pictures("authorspictures.txt");
    cout<< my_store;
    my_store.seq();
    cout << "\nWrite a letter:" << endl;
    cin >> x;
    my_store.find(x);


    graph compare_picture;
    cout<<"\n\nComparing pictures..."<<endl;
    my_store.comparision("compare_picture.txt");

    pictures_of_nature auth_picture_for_comparision;
    cout<<"\n\nComparing authors pictures..."<<endl;
    my_store.comparision_auth_pictures("auth_compare_picture.txt");

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
        cout << "\nWrite the name of file: ";
        cin >> file_name;
        my_store+=file_name;
        string file = "";
        cout << "\nWrite the name of file: ";
        cin >> file;
        my_store+=file;
        cout<<my_store;
        my_store.seq();
    }
    else if (choice == 1)
    {
        cout << "\n Write which picture do you wanna remove: (number)" << endl;
        cin >> number;
        my_store.delete_picture(number);
        my_store.delete_author_picture(number);
        cout<<my_store;
        my_store.seq();
    }
    my_store.write_to_file("Images.dat");
    my_store.write_to_file_authors_puctures("AuthorsImages.dat");

    return 0;
}
