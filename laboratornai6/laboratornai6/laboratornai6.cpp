#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char String[100];

    int Words[50];

    int Number = 0;

  int i, j , t = 0;
  int End_Word = 1; 

  cout << "Vvedite stroky: " << endl;
  gets_s(String);

  for (i = 0; i < 50; i ++)
  {
    if (String[i] == ' ')
    {
      String[i] = '\0';
      End_Word = 1;
    }
    else if (End_Word)
    {
      Words[Number ++] = i;
      End_Word = 0;
    }
  }

  for (j = Number - 1; j > 0; j --)
      for (i = 0; i < j; i++)
      {
          if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
          {
              t = Words[i];
              Words[i] = Words[i + 1];
              Words[i + 1] = t;
          }
      }
  cout << "Result:" << endl;
  for (i = 0; i < Number; i++)
  {
      char *m = &String[Words[i]];
      cout << m << " ";
  }
  return 0;
}