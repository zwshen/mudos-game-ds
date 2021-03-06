#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIW"千古石林"NOR);
  set("long", @LONG
這裡是一處谷地，到處都是高大的化石樹木，你後方的石林形成
一面天然的石牆，你回頭一望石林的頂端，以這種高度看樣子無法爬
上去了，若有絕頂輕功或許可以躍上(jump up)。
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room36",
      "northwest" : __DIR__"room38",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  setup();
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me=this_player();        
  if(arg!="up") 
    return notify_fail("你想要跳(jump)到哪？");
  if(me->is_busy() )
    return notify_fail("你正忙著，無法專心應付此動作。\n");
  if(me->query_skill("dodge",2) <90)
    return notify_fail("你的能力不足以跳上石林。\n" );
  if(!me->move(__DIR__"room32") )
    return notify_fail("你無法跳上石林。\n");
  tell_room(me,HIW"$N提氣一躍而上，雙足連點樹枝，幾次借力後成功\躍上石林。\n"NOR,me);
  return 1;
}
