#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "git.h"

int read_stdin();

int main() 
{
  char * repo_name = get_git_repo_name();
  char * branch_name = get_git_branch_name();

  printf("Repo: %s\n", repo_name);
  printf("Branch: %s\n", branch_name);

  printf("Write your notes below. Each line will be saved as a separate note. An empty line will exit.\n");
  read_stdin();
  printf("Done.\n");

  return 0;
}

int read_stdin()
{
  FILE * notes_file = fopen("tmp/test", "a+");
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, stdin)) > 1) {
    fputs(line, notes_file);
    printf("Took note: %s", line);
  }

  fclose(notes_file);
  if (line) {
    free(line);
  }

  return 0;
}

