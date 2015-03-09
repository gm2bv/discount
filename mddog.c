/*
 * SAMPLE PROGRAM for mdDog
 * by gm2bv <gm2bv2001@gmail.com> 2015/02/27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mkdio.h"

char *pgm = "mddog";

typedef struct _mddog_paragraph{
  char *text;
  int length;
  struct _mddog_paragraph *next;
} MDDOG_PARAGRAPH;


int main(int argc, char* argv[])
{
  char *ret;
  int length;
  char text[] = "TITLE\n----\n\n- LIST1\n- LIST2\n\nHOGE1\n**HOGE2**\nHOGE3\n\n## SUB-TITLE\n";
  //  char text[] = "";

  char str[] = "insert 2 lines\nhogehoge\n\n";
  mkd_flag_t flags = MKD_NOHEADER || MKD_NOPANTS;
  int num = 0;
  MDDOG_PARAGRAPH *para;

  /* 指定の段落の生データを返す 　　　　　　　　　　　　　*/
  //length = mddog_get_paragraph_raw(text, flags, num, &ret);

  /* 指定の段落のHTMLデータを返す 　　　　　　　　　　　　*/
  //  length = mddog_get_paragraph_html(text, flags, num, &ret);
 
  /* 指定の段落を任意の文字列に入れ替えたデータを返す     */
  /* 任意の文字列がNULLだとその段落を削除したデータを返す */
  length = mddog_alter_paragraph(text, flags, num, str, &ret);
  //length = mddog_alter_paragraph(text, flags, num, NULL, &ret);

  printf("%s\n", text);
  printf("===================\n");
  /*
  if( ret != NULL ){
    printf("%s\n", ret);
  }
*/

  mddog_paragraphs(text, flags, &para);
  while( para != NULL ){
    printf("%s\n", para->text);
    para = para->next;
  }

  mddog_cleanup();

  return 1;
}
