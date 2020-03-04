#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"幽遮蘭城城西守備隊駐所"NOR);
        set("long", @LONG
這裡是幽遮蘭城城西守備隊的駐所，陰暗的木板牆在火
把的照耀下為整間屋子帶來了陰暗的氣息，整間屋子充斥著
由汗水、皮革、鐵器及油脂所混合的味道，大廳兩旁各有一
位守備隊員站得筆直，手執長矛，令人望而生畏，大廳兩旁
掛著為數不少的盾牌和長劍，還有幾面代表守備隊的旗子掛
在牆上，在火光的照耀下反射著黯淡的光芒。
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugw2",
                        "south": __DIR__"w1st3",
            ]));
           set("item_desc",([
"戰旗" : "
代表幽遮蘭城城西守備隊的戰旗，紅底藍邊，上繡著一
朵大波斯菊中崁有一顆藍色寶石。\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}

