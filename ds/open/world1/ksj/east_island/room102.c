#include <room.h>
inherit MOBROOM;

void create()
{
  set("short","山腰");
  set("long",@LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，往下的斜坡可以爬回山下。
LONG);
  set("exits",([ 
      "northeast":__DIR__"room103",
      "down":__DIR__"room101",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("chance",50);
  set("mob_amount",3); 
  set("mob_object",({    
      __DIR__"npc/warrior-ghost1",
     }) );
  setup();
}     

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_2") )
  {
    if( dir == "down")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}         
