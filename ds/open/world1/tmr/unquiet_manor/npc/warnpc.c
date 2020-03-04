#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("走動的骸骨", ({ "unquiet skeleton", "skeleton" }) );
    set("long", @LONG
這是一具腐爛的骸骨，不知為何竟然還能走動。它的空洞眼眶
似乎正望著你，似乎要你不要殺他。
LONG);

    set("title",HIG"無寧莊園"NOR);
    set("gender", "male");
    set("age", 10);
    set("level",5);
    setup();
}

void die()
{
   object me;
   if( !me = query_temp("last_damage_from") )
        me = this_player(1);
   if( !me )
   {
     ::die();
     return;
   }
        command("war ... "+me->name(1) + "(" + me->query("id") +")..喀..喀..喀喀喀...喀....喀喀！！！");  
        message_vision("一道黑煙從$N冒出，直竄回到無寧莊園中...\n", this_object());
        load_object("/open/world1/tmr/unquiet_manor/map_17_8.c")->start_war();

  ::die();
  return;
}


