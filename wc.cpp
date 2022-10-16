#include <iostream>
#include <fstream>


using namespace std;

int lines(ifstream& infile);
int words(ifstream& infile);
int bytes(ifstream& infile);
void options(ifstream& infile, int argc, char** argv);

int main(int argc, char** argv)
{
  ifstream infile(argv[argc-1]);
  options(infile, argc, argv);
  
  infile.close();
}

int bytes(ifstream& infile)
{
  int b=0;
  while(infile)
  {
    infile.get();
    b++;
  }
  infile.clear();
  infile.seekg(0);
  return b;
}

int words(ifstream& infile)
{
  int w = 1;
  char ch;
  while(infile)
  {
    infile.get(ch);
    if (ch == ' ' || ch == '\n')
      w++;
  }
  infile.clear();
  infile.seekg(0);
  return w;
}

int lines(ifstream& infile)
{
  int l = 1;
  char ch;
  while(infile)
  {
    infile.get(ch);
    if (ch == '\n')
      l++;
  }
  infile.clear();
  infile.seekg(0);
  return l;
}
void options(ifstream& infile, int argc, char** argv)
{

  if (argc == 3)
  {
  string argv1 = argv[1];
    if(argv1 == "-l")
      cout << "\t" << lines(infile);
    else if (argv1 == "-w")
      cout << "\t"  << words(infile);
    else if (argv1 == "-c")
      cout << "\t"  << bytes(infile);
    else
      cout << "Invalid option" << endl;
  }
  else if (argc == 4)
  {
  string argv1 = argv[1];
  string argv2 = argv[2];
  if(argv1 == "-l")
      cout << "\t"  << lines(infile);
  else if (argv1 == "-w")
      cout << "\t"  << words(infile);
  else if (argv1 == "-c")
      cout << "\t"  << bytes(infile);
  else
      cout << "Invalid option" << endl;
      
  if(argv2 == "-l")
      cout << "\t"  << lines(infile);
  else if (argv2 == "-w")
      cout << "\t"  << words(infile);
  else if (argv2 == "-c")
      cout << "\t"  << bytes(infile);
  else
      cout << "Invalid option" << endl;
  }
  else
  {
    cout << "\t"  << lines(infile) << "\t"  << words(infile) << "\t"  << bytes(infile);
  }
  cout << " " << argv[argc-1] << endl;
  
}