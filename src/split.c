#include "split.h"
#include <stdio.h>

static int comptoken(const char *str,char token)
{
  int comp;
  int j;

  comp = 0;
  j = 0;
  while (str[comp] != '\0')
    {
      if (str[comp] == token)
        j++;
      comp++;
    }
  return j;
}

char **std_split(char *str,
		 char token)
{
  char **new_str;
  int nbr_token;
  int bonus;
  int i;
  int j;
  int comp;

  comp = 0;
  i = 0;
  j = 0;
  nbr_token = comptoken(str,token);
  bonus = 2;
  new_str = malloc((sizeof(char*)) * (nbr_token + bonus));
  new_str[i] = malloc(sizeof(char) * 32);
  while(str[comp] != '\0') 
    {
      new_str[i][j] = str[comp];
      comp++;
      j++;
      if (str[comp] == token || str[comp] == '\0')
	{
	  new_str[i][j] = '\0';
	  j = 0;
	  i++;
	  new_str[i] = malloc(sizeof(char) * 32);
	  if (str[comp] != '\0')
	    comp++;
	}
    }
  new_str[i] = NULL;
  return new_str;
}
