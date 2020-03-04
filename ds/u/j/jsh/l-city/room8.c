#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "長城");
        set("long", @LONG
test
LONG
        ); 
        set("item_desc",([ 
        "木門":"一扇蠻破舊的木門，裡面不知道是什麼地方[enter]？\n",
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room9", 
  //"west" : __DIR__"room6",  
  "southwest" : __DIR__"room7",])); 
set("light",1);

        setup();
}
void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
          object me,x;
          me=this_player();
          if(arg != "木門") return 0;
          else { 
                        message_vision("$N往木門裡走了進去。\n",me); 
            message("world:world1:vision",HIR"\n\t開羅士兵大喊：劫獄啊！！有人劫獄啊！！\n"
                             +HIB"\n\t開羅將軍"+HIR"大喊：來人啊！將"+HIG""+me->name(1)+""+HIR"給我拿下！\n\n"+NOR,users());  
            {
            me->move(__DIR__"jail");
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());      
            }
            return 1;
          }
}

