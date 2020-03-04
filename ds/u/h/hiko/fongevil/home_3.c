#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中茅廬");
set("long",@LONG
你來到茅廬中的其中一間房間，這裡給人的感覺比較高雅
，看來是屬於比較成熟的人的房間，房間主人該是年紀頗大，
而且看來蠻懂得休閒的，房內的桌上擺著一套不錯的茶具，可
見其興趣典雅。
LONG
    );
 set("objects",([
__DIR__"npc/mountain-man" : 1,
__DIR__"npc/boy-yu" : 1,
]));
set("item_desc", ([
    "茶具" : "用上好的木料所製而成，看來感覺十分高雅。\n",
                 ])); 
set("exits",([
"south":__DIR__"yu_home",
]));
 set("no_kill",1);
 set("no_clean_up",0);
 set("light",1);
 setup();
}             

void reset()
{
  object npc;
  if(objectp(npc = find_living("outboy")))
    if(!npc->query("go_home")) destruct(npc);
  else return;
  ::reset();
  return;
}






