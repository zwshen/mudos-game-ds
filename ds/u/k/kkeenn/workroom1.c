#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
 set("short",HIC"龍人辦公處"NOR);
 set("long","觀看目前報告Cmd : help report\n");
set("exits", ([
"east":__DIR__"workroom3.c",
"west":__DIR__"workroom2.c",
 ]) );
set("objects",([
] ) );
set("light",1);
set("no_goto",1);
setup();
}
void init()
{
 add_action("do_help","help");
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
}
int do_help(string arg)
{
 if(arg=="report")
 {
   if( file_size(__DIR__"origami/help.txt")>0 )
   {
    this_player()->start_more( read_file(__DIR__"origami/help.txt") );
    write("\n");
   } else write(" SORRY. 沒有這個檔案. \n");
  return 1;
 }
 return 0;
}
void delay(object me)
{
        write("
  "HIW"\n\t當前工作：\n"HIM"\t\t排序\t時空\t類別\t名稱\t\t完成度"+
     "\n\t\t"HIC"首項\t未來\t工會\t摺紙戰士\t10%"+
     "\n\t\t次項\t未來\t區域\t精靈界\t\t0%"+
     "\n\t\t備註\t古代\t維護\t情城池\t\t無%\n\n"
NOR);
}
