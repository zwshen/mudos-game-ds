#include <ansi.h>  
inherit ROOM;
 
void create()
{
  set("short", "霧洞深處 - 迴地居");

  set("long", @LONG
霧茫茫的一片，在此黑暗的洞穴內，似乎有種極為恐怖的生物，
沙沙的聲響不斷的發出，你小心翼翼的站在一旁，若是隨便亂扔東西
有可能會出現什麼恐怖的生物，一旁堆著許多果實的殘骸。
LONG
  );
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"snake-room2",
     ]));
  set("item_desc",([
      "果實的殘骸" : "許\多被啃食到一半的各種果實，但就是沒有紅色的果實？\n",
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
  object me=this_player(),ob=this_object(),mobp,z; 
  if(ob->query_temp("throwed")) return notify_fail("剛剛有人丟過了。\n");
  if(!arg||arg!="fruit") return notify_fail("你要丟什麼?\n");
  if(!objectp(z=present("fire fruit",me) ) )
    return notify_fail("你沒有東西可以丟啊 ? \n");
  message_vision("$N將火紅果丟向洞穴深處...\n"
                 "突然衝出一隻巨蛇！吞下那顆火紅果！\n",me);
  destruct(z);
  me->start_busy(2);  
  mobp=new(__DIR__"npc/hua-di"); 
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


