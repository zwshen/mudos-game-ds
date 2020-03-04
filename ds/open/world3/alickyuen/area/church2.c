// updated 26.12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST¡DChurch¢ISt.Rolence"NOR);
	set("long", @LONG
ª÷¥úºÉ´²«á¡A§A¨Ó¨ì¤F¤@¶¡·sªº©Ð¶¡¡C¦ý¤£ª¾¬°¦ó§A¦³¤@ºØ¤£¦wªº·PÄ±
¥t§A¤£´H¦Ó·X¡A¦Ó§A¤SÅ¥¨ì¤@¨Ç¥sÁn±q«n­±¶Ç¨Ó¡A¥t§A§ó¥[®`©È¡C³o¼Ë¤¤¶¡
¦³¤@´L[1;32m¤ë¼v¯«¹³[0m¡A¦ý¦³¤@¼ËªF¦è¤Q¤À©_©Ç¡A¨º´N¬O¤ë¼v¯«¹³ªº¥k¤â¦ù¤F¥X¨Ó
¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"church4",
"out" : __DIR__"church",
]));
set("light",1);
	set("item_desc", ([ /* sizeof() == 2 */
  "¤ë¼v¯«¹³" : "§A¬Ý¨ì[1;33m¤ë¼v¯«¹³ªº¤â[0m¦ù¤F¥X¨Ó, §A¥i¥H¹Á¸Õ®»ºN(touch)¥¦ªº¤â¡C\n",
]));
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}
void init()
{
add_action("do_touch","touch");
}
int do_touch(string arg)
{
        object me;
        me=this_player();
        if (arg != "¤ë¼v¯«¹³ªº¤â" && arg != "hand") 
                   return notify_fail("³o¸Ì¨S¦³³o­ÓªF¦è¥iºN¡C\n");
        else {
                   message_vision("$NºN¤F¤@¤U¤ë¼v¯«¹³ªº¤â¡C\n¬ðµM¦a¤W¬ï¤F­Ó¤j¬}¡A$N±¼¤F¶i¥h¡C\n\n" ,me);
                   me->move(__DIR__"church3");
                   tell_room(environment(me),me->query("name")+"¬ðµM¥X²{¦b§A²´«e¡Cn",me);
           return 1;
                 }
}
