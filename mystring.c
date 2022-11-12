// mystring.c
#include "mystring.h"
#include <ctype.h>
#include <stddef.h>

int my_string_length(const char * str)
{
  int len = 0;
  while (str[len] != '\0')
    {
      len = len + 1;
    }
  return len;
}

int my_count_char(const char * str, char ch)
{
  int cnt = 0;
  while (* str != '\0')
    {
      if (* str == ch)
	{
	  cnt = cnt + 1;
	}
      str = str + 1;
    }
  return cnt;
}

void my_string_upper(char * str)
{
  while(*str != '\0')
    {
      * str = toupper(* str);
      str = str + 1;
    }
}

char * my_find_char(char * str, char ch)
{
  int ind = 0;
  while (str[ind] != '\0')
    {
      if (str[ind] == ch)
	{
	  return (& str[ind]);
	}
      ind = ind + 1;
    }
  return NULL;
}
