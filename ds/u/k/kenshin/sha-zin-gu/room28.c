// Room: /u/k/kenshin/sha-zin-gu/room28.c
 
#include <ansi.h> 
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "主臥房");
        set("long", @LONG
這裡就是寧采和的主臥房了，裡面的擺設相當的整齊，另外還有
兩把寶劍懸掛在牆上，除此之外，你還發覺怎會有一種味道怪怪的，
好像不是屬於此房間的味道，會是哪傳過來的呢?
LONG
        );
        set("light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room27",
]));   
  set("item_desc", ([ /* sizeof() == 1 */
"壁畫" : "此為武松打虎圖，但畫中武松的右眼好像凹了進去，用力一看，裡頭似乎有個開關，是要按(press)下去嗎？\n"
]));        set("no_clean_up", 0);
        set("current_light", 4);
        setup();
        replace_program(ROOM);
} 
 
void init()
{
      add_action("do_press","press");
}

int do_press(string arg)
{
       object me;
       me=this_player();
        if( !arg || arg != "開關")
       return 0;
       else {
message_vision(HIW"$N按下開關後，此時地板開了大空，$N整個人往下掉！\n"NOR,me);
       me->move(__DIR__"room30");  
//message_vision(HIC"只聽到一陣慘叫聲，$N往上面掉下來。\n"NOR,me); 
        } 
          return 1;
}

