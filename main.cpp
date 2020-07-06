#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string path;

    cout << "Vvedite put' k failu f: "; // d:\\f.txt
    cin >> path;

    ifstream fin;
    fin.open(path.c_str());

    if(!fin.is_open())
    {
        cout << "ERROR!!!" << endl;
        return -1;
    }
    else
    {
        cout << "File otkrit." << endl;
    }

    int mass[100];

    int counter = 0;
    do
    {
        fin >> mass[counter];
        counter++;
    }while(!fin.eof());

    for(int i = 0; i < counter; i++)
        cout << mass[i] << " ";
    cout << endl;

    fin.close();

    ofstream fout;
    fout.open("d:\\nechet.txt");

    for(int i = 0; i < counter; i++)
    {
        if((mass[i] % 2 == 1) || (mass[i] % 2 == -1))
        {
            fout << mass[i] << " ";
        }
    }

    fout.close();

    fout.open("d:\\chet.txt");

    for(int i = 0; i < counter; i++)
    {
        if(mass[i] % 2 == 0)
        {
            fout << mass[i] << " ";
        }
    }

    fout.close();

    return 0;
}
