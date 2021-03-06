// mumen.c 墓門
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "墓門");
        set("long", @LONG
你走過了草地，發現自己已身處深谷之中，霧氣蒙蒙，寒意逼人。
四下是片不小的開闊地，突兀地聳立著一座一人高的白色球型圓冢，墓
上砌的石頭已經班駁了，看的出來這是座古墓。墓前沒有立碑，也沒有
任何的標記。墓后是陰森森的松林古木，更平添十分凄清落寞的蕭瑟之
意。墓門僅齊肩高，往內是古墓派所在。墓門口被一塊黑黝黝的大石頭
(stone)封閉得絲毫不透。
    古墓傳人歷來不輕出江湖，但不少癡情男女仰慕楊龍二人雙劍合壁
快意江湖的豪情，歷盡千般磨難后終成眷屬驚世戀情。不遠千里往來投
拜。
LONG    );
        set("outdoors", "gumu");
        set("exits", ([
                "east"  : __DIR__"xuanya",
                "west"  : __DIR__"huangshalin",
                "north" : __DIR__"caodi",
                "south" : __DIR__"mudao01",
        ]));
        set("objects", ([
                __DIR__"npc/yufeng" : 2+random(2),
        ]));
        set("item_desc", ([
                "stone": "這是塊巨石，怕不有萬斤上下，隱隱約約刻有著‘"+YEL"降龍石"NOR+"’幾個字。\n"
        ]) );
        setup();
}

void init()
{
        add_action("do_move", "push");
}

int do_move(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "stone" )
        {
        return notify_fail("你要移動什麼？\n");
        }
        if( !query("exits/south"))
        {
          return notify_fail("降龍石已經落下，你沒有東西好移動了。\n");
        }
        if((int)me->query_str()>33)
        {
                message_vision("$N站在降龍石前，雙掌發力推動降龍石，只聽得降龍石吱吱連聲，緩緩向下落去，封住了墓門。\n", me);
                delete("exits/south");
                if( !(room = find_object(__DIR__"mudao01")) )
                        room = load_object(__DIR__"mudao01");
                room->delete("exits/north");
                remove_call_out("reopen");
                  call_out("reopen", 600, me);
                tell_room(room,"只聽得降龍石吱吱連聲，緩緩向下落去，封住了墓門。\n");
        }
        else
                message_vision("$N試著推了推巨石，巨石紋絲不動，只得罷了。\n", this_player());
        return 1;
}


void reopen()
{
        object room;

        tell_room(this_object(), "只聽得降龍石吱吱連聲，緩緩向上升去，恢復了原狀。\n");
        set("exits/south",  __DIR__"mudao01");

        if( !(room = find_object(__DIR__"mudao01")) )
                room = load_object(__DIR__"mudao01");
        room->set("exits/north", __DIR__"mumen");
        tell_room(room, "只聽得降龍石吱吱連聲，緩緩向上升去，恢復了原狀。\n");
}

