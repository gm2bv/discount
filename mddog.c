/*
 * SAMPLE PROGRAM for mdDog
 * by gm2bv <gm2bv2001@gmail.com> 2015/02/27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mkdio.h"

char *pgm = "mddog";

//typedef MMIOT void;


int main(int argc, char* argv[])
{
  char *ret = NULL;
  int length;
  char text[] = "    block1\n    block2\n\nTITLE\n----\n\n- LIST1\n- LIST2\n\nHOGE1\n**HOGE2**\nHOGE3\n\n## SUB-TITLE\n\n>QUOTE\n>QUOTE2\n\n|H1|H2|H3|\n|----|----|----|\n|HOGE1|HOGE2|HOGE3|\n|HOGEHOGE1|HOGEHOGE2|HOGEHOGE3|\n";
  char str[] = "insert 2 lines\nhogehoge\n\n";
  mkd_flag_t flags = MKD_NOHTML || MKD_NOPANTS;
  int num = 6;

  /* 指定の段落の生データを返す 　　　　　　　　　　　　　*/
  //ret = mddog_get_paragraph_raw(text, flags, num, &length);

  /* 指定の段落のHTMLデータを返す 　　　　　　　　　　　　*/
  ret = mddog_get_paragraph_html(text, flags, num, &length);
 
  /* 指定の段落を任意の文字列に入れ替えたデータを返す     */
  /* 任意の文字列がNULLだとその段落を削除したデータを返す */
  //ret = mddog_alter_paragraph(text, flags, num, str, &length);
 
  printf("%s\n", text);
  printf("===================\n");
  if( ret != NULL ){
    printf("%s\n", ret);
    free(ret);
  }

  return 1;
}
