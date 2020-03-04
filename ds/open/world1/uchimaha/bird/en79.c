#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","石穴 ");
set("long", @LONG
你來到了地下石穴, 這裡非常的熱, 因為有一個巨大
的熔爐正在發出熊熊的火燄, 在這裡有一個獨臂老人正在
打製一把劍, 他對你的到來似乎很高興, 在這裡也有一個
石像, 可是好像跟你剛看到的不太一樣....

LONG
        );
        set("objects",([__DIR__"npc/ooldman" : 1,
               ]));
        set("item_desc",([
        "石像":"一個烏漆嗎黑的石像，石像的頭好像可以轉動的樣子(roll)。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{
        add_action("do_roll","roll");
}

int do_roll(string arg)
{
        object me;
        me=this_player();
        if (arg != "石像的頭") return 0;
        else {
               message_vision("只見$N把石像的頭一轉，出現了一個通往上方的梯子。\n\n",me);
               set("exits",([
               "up" : __DIR__"en78",
               ]) );
           return 1;
        }
}          


