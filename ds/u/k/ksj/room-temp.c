#include <ansi.h>  
inherit ROOM; 
void create()
{
        set("short", "霧洞內");
        set("long", @LONG
霧茫茫的一片，在此黑暗的洞穴內，似乎有種極為恐怖的生物
，沙沙的聲響，不斷的發出。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : "/open/world1/cominging/area/fgo2.c",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_throw","throw");
}

int do_throw(string arg)
{ 
  object me=this_player(),ob=this_object(),mobp; 
  if(ob->query_temp("throwed")) return notify_fail("剛剛有人丟過了。\n");
  if(!arg||arg!="fruit") return notify_fail("你要丟什麼?\n");
  message_vision("$N將"+ob->name(1)+"丟向洞穴深處...\n"
                 "突然衝出一隻巨蛇！吞下那顆火紅果！\n",me);   
  me->start_busy(2);  
  mobp=new(__DIR__"hua-snake"); 
  mobp->move(environment(this_player()));   
  mobp->kill_ob(this_player()); 
  ob->set_temp("throwed",1); 
  call_out("stop_throwed",600,ob);
  return 1;
}
void stop_throwed(object ob)
{
     if(!ob) return; 
     ob->delete_temp("throwed");
}
