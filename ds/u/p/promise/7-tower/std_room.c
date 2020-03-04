#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"七邪塔"NOR);
        set("long", @LONG
站在塔前方，能看見塔竟然毫無止境，塔頂灌串天空雲層，無疑
是在向天底神明宣戰。在旁毫無生物，聽位於在不遠處的人民說道，
此塔裡住著一些妖魔鬼怪，聽說各各法力高強，不容忽視。
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
   "back" : "/open/world1/tmr/area/hotel",
    ]));
        
        set("no_fight",1);
        set("no_cast",1);
        set("no_exert", 1);
        set("no_steal", 1);
        set("world", "past");
        set("no_clean_up", 0);
        set("light",1);
        setup();
}

void init()
{
        add_action("do_enter","enter");
        
}

int do_enter(string arg)

{
        object me = this_player();
        string gender;
        gender=me->query("gender");

        if( arg != "七邪塔" )
                return 0;
        if ( gender=="男性" ) gender="少俠";
        if ( gender=="女性" ) gender="俠女";
        if ( me->query("age") > 50 ) gender="前輩";
        if ( me->query("level") < 40 )  return notify_fail(HIW"塔內傳出一聲大吼：HIB" +gender+ "HIW你還未夠班，回去修練幾年在來闖吧。\n"NOR);
message("world:world1:vision",
NOR+GRN"\t傳說中勇者『"HIW+me->query("name")+NOR+GRN"』貿然進入七邪塔，此刻開始七邪塔必然興起一陣血腥！！\n\n"NOR,users());
        me->move(__DIR__"1f_1");
        me->start_busy(1);
        
        return 1;
}

