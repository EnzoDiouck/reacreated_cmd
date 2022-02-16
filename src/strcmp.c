/*
** *****************************************************************************
** enzo.pfeiffer
** enzo.pfeiffer <enzo.pfeiffer@student-station>
**
** strcmp.c - 2021
**
** *****************************************************************************
*/

#include "strcmp.h"

int std_strcmp(char *str1, char *str2)
{
  int comp;

  comp = 0;
  while ((str1[comp] != '\0') && (str2[comp] != '\0'))
    {
      if (str1[comp] != str2[comp])
	return (-1);
      comp++;
    }
  return 0;
}
