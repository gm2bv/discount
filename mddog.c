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
  char text[] = "=HOGE=\n    hoge\n=HOGE2=\n    hoge2\n";
  //  char text[] = "=HOGE=\n    hoge\n=HOGE2=\n    hoge2\n- list1\n- list2\n";
  //  char text[] = "- list1\n- list2\n    >HOGE\n\nhogehoge\n\n# TITLE\n";
  //char text[] = "=hoge=\nhoge2\n    hogehoge\n=hoge2=\n- line1\n- line2";
  //  char text[] = "# TITLE\nhogehoge\n\n- LIST1\n- LIST2\n\nHOGE1\n**HOGE2**\nHOGE3\n\n## SUB-TITLE\n";
  //       char text[] = "#HOGEHOGE\n\n- list1-1\n- list1-2\n\n    > HOGEHOGE\n\nhogehogehogege\n\n- list2-1\n- list2-2\n=HOGE=\n    hogehoge\n=HOGE2=\n    hogehoge2\n=HOGE3=\n    hogehoge3\n- hogehogehoge3\n- HOGE4\n";
  //  char text[] = "";

  char str[] = "INSERT 1 LINE\n";
  mkd_flag_t flags = MKD_NOHEADER || MKD_NOPANTS;
  int num = atoi(argv[1]);
  int convert = atoi(argv[2]);
  MDDOG_PARAGRAPH *para;

  switch(convert){
  case 1:  /* 指定の段落の生データを返す 　　　　　　　　　　　　　*/
        length = mddog_get_paragraph_raw(text, flags, num, &ret);
        break;
  case 2:  /* 指定の段落のHTMLデータを返す 　　　　　　　　　　　　*/
        length = mddog_get_paragraph_html(text, flags, num, &ret);
        break;
  case 3:  /* 指定の段落を任意の文字列に入れ替えたデータを返す     */
           /* 任意の文字列がNULLだとその段落を削除したデータを返す */
        length = mddog_alter_paragraph(text, flags, num, str, &ret);
  //  length = mddog_alter_paragraph(text, flags, num, NULL, &ret);
  //  length = mddog_alter_paragraph("", flags, 0, str, &ret);
        break;
  case 4:
    mddog_paragraphs(text, flags, &para);
    break;
  }

  printf("%s\n", text);
  printf("===================\n");

  if( ret != NULL ){
    if(convert != 4){
      printf("%s\n", ret);
    }else{
      while( para != NULL ){
        printf("%s\n", para->text);
        para = para->next;
      }
    }
  }

  mddog_cleanup();

  return 1;
}
