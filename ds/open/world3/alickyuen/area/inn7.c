// Room: /u/a/alickyuen/area/inn7.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"ST．SOFT＠Restroom"NOR);
        set("long", @LONG
這�堿O供客人休息和閒談的房間，你看到這裡的佈置非常整齊，有電
視等東西，一應俱備，沙發上有一班客人正在閒談中，氣氛相當融合。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"inn5",
        ]));
set("objects",([
"/open/world3/tmr/basic/npc/hunter_master":1,
]) );
        set("item_desc", ([
        "沙發" : "一張由冰所做成的沙發，使人有一陣陣涼快的感覺。\n",
        ]));
        set("light",1);
        set("world", "future");
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object gun;
        object me;
        me=this_player();
 
       if (!arg || arg != "沙發") 
                return 0;
       if(query_temp("getcard")) 
                return notify_fail("找了又找，最後也沒找到什麼。\n");

        message_vision("$N在沙發底找到了一張磁卡。\n"  ,me);
        gun=new(__DIR__"obj/card.c");
        gun->move(me);
        set_temp("getcard",1);      
        return 1;  
}


void reset()
{
        if(query_temp("getcard") )
                delete_temp("getcard");
      ::reset();
}

