// more.c
// #pragma save_binary
#include <ansi.h>

void more(string cmd, string *text, int line)
{
        int i;
        int PAGE_SIZE=46;
        switch(cmd)
        {
         case "b":
                        line = line - PAGE_SIZE*2;
                        if(line < -PAGE_SIZE) return;
                        for(i=line + PAGE_SIZE; line < i;line++)
                        write(text[line]+"\n");
                        break;
          case "q":
                        return;
          default:
                        for(i=line + PAGE_SIZE; line<sizeof(text) && line<i; line++)
                        write(text[line] + "\n");
                        if( line <PAGE_SIZE )
                        {
                                write("\n");
                                return;
                        }
                        if( line>=sizeof(text) )
                        {
                                write(HBK"-------------------------------------------[ 請按 Enter 鍵結束 ]------"NOR);
                                input_to("pause");
                                return;
                        }
                        break;
        }

        write(sprintf(HBK"== 未完繼續 " NOR+YEL "第%d行/共%d行"GRN"(%d%%)" HBK" == (ENTER 繼續下一頁﹐q 離開﹐b 前一頁)"NOR,
                line,sizeof(text),(line*100/sizeof(text)) ));
        input_to("more", text, line);
}

void start_more(string msg)
{
        more("", explode(msg, "\n"), 0);
}

void pause(string arg)
{
 write("\n");
 return;
}

