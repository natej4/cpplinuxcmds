#include <iostream>
#include <fstream>
#include <stack>
#include <cstdlib>


using namespace std;

void readFile(stack<string>& lines, ifstream& infile);
void printLines(stack<string>& lines, int numLines);

int main(int argc, char** argv)
{
  ifstream infile(argv[1]);
  int numLines = atoi(argv[2]);
  stack<string> lines;
  readFile(lines, infile);
  printLines(lines, numLines);
  
  infile.close();
}

void readFile(stack<string>& lines, ifstream& infile)
{
  char line[256];
  while (infile)
  {
    infile.getline(line, 256);
    lines.push(line);
  }

}

void printLines(stack<string>& lines, int numLines)
{
  lines.pop();
  stack<string> output;
  for (int i = 0; i < numLines; i++)
  {
    output.push(lines.top());
    lines.pop();
  }
  while(!output.empty())
  {
    cout << output.top() << endl;
    output.pop();
    }

}