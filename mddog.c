#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mkdio.h"

char *pgm = "mddog";

//typedef MMIOT void;

int main(int argc, char* argv[])
{
  char text[] = "    block1\n    block2\n\nTITLE\n----\n\n- LIST1\n- LIST2\n\nHOGE1\n**HOGE2**\nHOGE3\n\n## SUB-TITLE\n\n>QUOTE\n>QUOTE2\n\n|H1|H2|H3|\n|----|----|----|\n|HOGE1|HOGE2|HOGE3|\n|HOGEHOGE1|HOGEHOGE2|HOGEHOGE3|\n";
  mkd_flag_t flags = MKD_NOHTML || MKD_NOPANTS;
  int num = 5;

  MMIOT* doc = mkd_string(text, strlen(text), flags);
  if( doc == NULL ){
    printf("Error\n");
    exit(-1);
  }

  int ret = mddog_compile(doc, flags, num);
  if( ret > 0 ){
  }

  mkd_cleanup(doc);
  return 1;
}
