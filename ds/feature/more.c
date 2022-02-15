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
                                write(HBK"-------------------------------------------[ �Ы� Enter �䵲�� ]------"NOR);
                                input_to("pause");
                                return;
                        }
                        break;
        }

        write(sprintf(HBK"== �����~�� " NOR+YEL "��%d��/�@%d��"GRN"(%d%%)" HBK" == (ENTER �~��U�@���Mq ���}�Mb �e�@��)"NOR,
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

