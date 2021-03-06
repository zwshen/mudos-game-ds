#include <room.h>
inherit ROOM;

void create()
{
  set("short","岩洞");
  set("long",@LONG
這裡是岩石丘中往內凹進去的天然岩洞，周遭的地上散佈著不知
名的骨骸，岩洞旁邊有一部份的岩壁看起來較旁邊的岩壁乾淨，沒有
長什麼癬苔或雜草，岩壁上面忽明忽暗好像有火光閃動。
LONG);
  set("exits",([ 
      "south":__DIR__"room54",
      "southeast":__DIR__"room55",
      "southwest":__DIR__"room53",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("light","0");
  set("king-room",1);
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
      __DIR__"npc/apeman-king":1,
     ]) );
  setup();
}            

void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object me,claw;
  me=this_player();
  if(!arg || arg!="岩壁") return 0;
  if(!objectp(claw=present("climb claw",me) ) )
    return notify_fail("你缺乏合適的工具，無法攀登岩壁。\n");
  if ( (me->query("class1") == "thief") && (me->query_skill("hide") > 60) )
  {
    message_vision("$N摒息凝氣，無聲無息地爬上岩壁頂部了。\n",me);
    me->set_temp("hide",1);
    me->move(__DIR__"room57");
    tell_room(environment(me),"岩壁邊似乎有點動靜。\n",me );
    return 1;
  }
  message_vision("$N手腳並用，小心緩慢地爬上岩壁頂部了。\n",me);
  me->move(__DIR__"room57");
  tell_room(environment(me),me->query("name")+"緩緩地從岩壁下爬上來了。\n",me );
  return 1; 
}
