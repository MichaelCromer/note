#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

char * read_command_stdout(char * command) 
{
  char * line;
  size_t len;
  FILE * command_stream = popen(command, "r");
  ssize_t read = getline(&line, &len, command_stream);
  pclose(command_stream);

  if (read <= 0) {
    return NULL;
  }

  if (line[read - 1] == '\n') {
    line[read - 1] = '\0';
  }

  return line;
}


