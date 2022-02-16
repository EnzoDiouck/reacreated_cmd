#include "fusion.h"

char *std_fusion(char *str1, char *str2)
{
  char *new_str;
  int comp;
  int comp2;

  comp = 0;
  comp2 = 0;
  new_str = malloc(sizeof(char) * (((std_strlen(str1) * std_strlen(str2)) + 1)));
  while(str1[comp] != '\0')
    {
      new_str[comp2] = str1[comp];
      comp++;
      comp2++;
    }
  new_str[comp2] = '/';
  comp = 0;
  comp2++;
  while(str2[comp] != '\0' && str2[comp] != ' ')
    {
      new_str[comp2] = str2[comp];
      comp++;
      comp2++;
    }
  return new_str;
}

char *std_script(char *str)
{
  char *new_str;
  int comp;

  new_str = malloc(sizeof(char) * std_strlen(str));
  comp = 0;
  new_str[comp++] = '#';
  new_str[comp++] = '!';
  while(str[comp] != ' ' && str[comp] != '\0')
    {
      new_str[comp] = str[comp];
      comp++;
    }
  new_str[comp] = '\0';
  return new_str;
}

char *std_remove(char *str)
{
  char *new_str;
  int comp;
  int comp2;

  comp = 5;
  comp2 = 0;
  new_str = malloc(sizeof(char) * (std_strlen(str) - 4));
  while (str[comp] != '\0')
    {
      new_str[comp2] = str[comp];
      comp++;
      comp2++;
    }
  new_str[comp2] = '\0';
  return new_str;
}

char *clearcmd(char *str)
{
  char *new_str;
  int comp;

  comp = 0;
  new_str = malloc(sizeof(char) * 256);
  while (str[comp] != ' ' && str[comp] != '\0')
    {
      new_str[comp] = str[comp];
      comp++;
    }
  new_str[comp] = '\0';
  return new_str;
}
