#include <weapon.h>
inherit ROOM;

void create()
{

set("short","大神木");
set("long", @LONG
此地是神木村的重要地點, 因為這裡正是大神木所在地, 傳說這棵大
神木有很神奇的力量, 每當村裡的人生病, 只要向這棵大神木誠心禱告,
就會不治而育, 也因此村裡的人很看重這棵大神木, 所以周圍有不少的官
兵在巡邏, 讓你無法靠近大神木.
LONG
);
set("outdoors", "land");
     
set("light",1);
set("exits", ([ 
       "east" : __DIR__"road_1.c",       
   ]));
 set("item_desc",([
        "神木":"一株長的又高又大的大樹似乎可以(jump)。\n",
        ]) );
set("no_clean_up", 0);
set("objects",([
__DIR__"npc/garrison_1.c" : 3,
       ]) );
       
setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
       me=this_player();
        if (!arg || arg!="神木" ) return 0;
        message_vision("$N施展不凡的輕功\,跳上了大神木。\n",me);
        me->move(__DIR__"lll");
        tell_room(environment(me),me->query("name")+"忽然有一個人跳了上來。\n",me);
        return 1;
}

