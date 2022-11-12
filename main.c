// main.c
#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 1000
int main(int argc, char ** argv)
{
  if (argc != 4)
    {
      printf("usage: %s command input output\n", argv[0]);
      return EXIT_FAILURE;
    }
  FILE * infptr = fopen(argv[2], "r");
  if (infptr == NULL)
    {
      printf("unable to open file %s!", argv[2]);
      return EXIT_FAILURE;
    }
  FILE * outfptr = fopen(argv[3], "w");
  if (outfptr == NULL)
    {
      printf("unable to open file %s!", argv[3]);
      fclose(infptr);
      return EXIT_FAILURE;
    }
  int num_lines = 0;
  char buffer[LINE_SIZE];
  while (fgets(buffer, LINE_SIZE, infptr) != NULL)
    {
      num_lines++;
    }

  fseek(infptr, 0, SEEK_SET);
  char ** lines = malloc(sizeof(char *) * num_lines);
  int i;
  for (i = 0; i < num_lines; i++)
    {
      if (feof(infptr))
	{
	  printf("not enough num_lines in file!\n");
	  fclose(infptr);
	  fclose(outfptr);
	  return EXIT_FAILURE;
	}
      lines[i] = malloc(sizeof(char) * LINE_SIZE);
      if (fgets(lines[i], LINE_SIZE, infptr) == NULL)
	{
	  printf("fgets error!\n");
	}
    }
  fclose(infptr);

  int total_length = 0;
  for (i = 0; i < num_lines; i++)
    {
      total_length += my_string_length(lines[i]);
    }

  if (strcmp(argv[1], "strlen") == 0)
    {
      for (i = 0; i < num_lines; i++)
	{
	  fprintf(outfptr,
		  "length: %d\n",
		  my_string_length(lines[i]));
	}
    }

  if (strcmp(argv[1], "countchar") == 0)
    {
      for (i = 0; i < num_lines; i++)
	{
	  fprintf(outfptr,
		  "count(%c): %d\n",
		  lines[i][0],
		  my_count_char(lines[i], lines[i][0]));
	}
    }

  if (strcmp(argv[1], "strup") == 0)
    {
      for (i = 0; i < num_lines; i++)
	{
	  my_string_upper(lines[i]);
	  fprintf(outfptr,
		  "%s",
		  lines[i]);
	}
    }

  for (i = 0; i < num_lines; i++)
    {
      free(lines[i]);
    }
  free(lines);
  fclose(outfptr);
  return EXIT_SUCCESS;
}
