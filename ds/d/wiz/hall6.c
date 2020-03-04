// Room: /d/wiz/hall6.c
#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", "魔神會議室");
 set("long", @LONG

  這裡是大巫師們相互討論與開會的地方﹐往下是職業技能討論廳。

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall5",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/arch_b", "???");
}

void init()
{
 if(query("open")) return;
 if(userp(this_player()))
 {
   if(wiz_level(this_player()) < wiz_level("(arch)") && getuid(this_player())!="tmr")
   {
     message_vision(HIW"天上傳來威嚴的聲音說:"HIR+this_player()->name()+",你等級不夠不可進入!!\n\n"NOR, this_player());
     tell_object(this_player(),"突然一陣強光將你傳送到了另一個地方...\n");
     this_player()->move(__DIR__"hall5");
   } else 
   {
     message_vision(HIW"\n 嗨! "+this_player()->name()+" 歡迎來到魔神會議室!!\n\n"NOR, this_player());
   }
 }
 return;
}

