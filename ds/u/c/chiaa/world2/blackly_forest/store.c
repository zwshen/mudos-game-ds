//u/c/chiaa/world2/blackly_forest/store.c
#include <ansi.h>
inherit ROOM;


void create ()
{
  set("short", "商店");
  set("long", @LONG
這裡是忍者村人們買東西的地方,也是較多人的地方!
忍者村的物資大都都是由這裡提供的!
LONG
        );
        set("no_fight", 1);         //房間為禁止作戰區域
        set("no_magic", 1);         //房間為禁止施法區域
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
  
   "east"  : __DIR__"nivi_road3",       //忍村道路3 
   ]));

setup();
replace_program(ROOM);
}
