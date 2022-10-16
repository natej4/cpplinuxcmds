#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int compare (fstream& file1, fstream& file2, string& f1, string& f2);
void ignore (fstream& file1, fstream& file2, string& n);
void c (fstream& file1, fstream& file2, int& loc);

int main(int argc, char* argv[])
{
    if (3 > argc > 6)
    {
        cerr << "Invalid number of arguments" << endl;
        return -1;
    }

    string f1 = argv[argc-2];
    string f2 = argv[argc-1];
    fstream file1 (f1.c_str(), ios::in);
    fstream file2 (f2.c_str(), ios::in);

    if(!file1 || !file2)
    {
        cerr << "One or more of the files specified does not exist or is a directory" << endl;
        return -1;
    }

    string argv1 = argv[1];
    string argv2 = argv[2];
    string argv3 = argv[3];
    if(argv1.find("-") != -1)
    {
        if(argv1 == "-i")
        {
            string n = argv[2];
            ignore(file1, file2, n);
        }
        
        else if(argv1 == "-c");
        else
        {
            cerr << "invalid option" << endl;
            return -1;
        }
    }
    if(argv2.find("-") != -1)
    {
        if(argv2 == "-i")
        {
            string n = argv[3];
            ignore(file1, file2, n);
        }
        else if(argv2 == "-c");
        else
        {
            cerr << "invalid option" << endl;
            return -1;
        }
    }
    int loc;
    loc = compare (file1, file2, f1, f2);

    loc--;
    if (argv1 == "-c")
        c(file1, file2, loc);
    else if (argv3.find("-") != -1)
    {
        if (argv3 == "-c")
        {
            c(file1, file2, loc);
        }
        else
        {
            cerr << "invalid option" << endl;
            return -1;
        }
    }
    
    cout << endl;
}

int compare (fstream& file1, fstream& file2, string& f1, string& f2)
{
    int line = 1;
    int loc;
    char ch1, ch2;

    while (file1 && file2)
    {
        file1.get(ch1);
        file2.get(ch2);
        if (ch1 == '\n' && ch2 == '\n')
            line++;
        if (ch1 != ch2)
        {
            loc = file1.tellg();
            cout << f1 << " " << f2 << " differ: byte " << loc << ", line " << line << " ";
            return loc;
        }
    }
    if (file2)
        cout << "cmp: EOF on " << f1 << endl;
    else
        cout << "cmp: EOF on " << f2 << endl;
}

void ignore (fstream& file1, fstream& file2, string& n)
{
    int num;
    stringstream ss(n);

    ss >> num;
    file1.seekg(num);
    file2.seekg(num);
}

void c (fstream& file1, fstream& file2, int& loc)
{
    char ch;
    cout << loc << endl;
    file1.seekg(loc);
    file2.seekg(loc);
    file1.get(ch);
    cout << ch << endl;
    int oct = int(ch);
    cout << oct << " " << ch << " ";
    file2.get(ch);
    oct = int(ch);
    cout << oct << " " << ch;
}