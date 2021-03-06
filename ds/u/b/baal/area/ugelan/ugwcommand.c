#include <ansi.h>
#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
        set("short", RED"幽遮蘭城城西守備隊駐所"NOR);
        set("long", @LONG
房間的正中央擺了一張大桌子，在桌子的另一邊靠著幾
把椅子，桌上的油燈，再加上牆上的數支火把，極為少數的
光源在這個不小的空間造成了許多晃動的陰影，使的整個房
間給人一種陰沉的壓迫感，，房內唯一的出口﹝也就是你剛
進來的地方﹞旁站了兩名全副武裝的警衛，正對面的牆上掛
著守備隊的戰旗，兩旁的牆上則各開了一個玻璃窗，其中一
扇還是打開的。
LONG
        );
        set("exits", ([ 
                        "south": __DIR__"ugw2",
            ]));
           set("item_desc",([
"大桌子" : "
一張厚實的大桌子，上面雕著守備隊的徽記：盾牌。\n",
"玻璃窗1" : "
一扇半開的玻璃窗，一陣陣的涼風從戶外吹進來。\n",
"玻璃窗2" : "
一扇緊閉的玻璃窗。\n",
"戰旗" : "
代表幽遮蘭城城西守備隊的戰旗，紅底藍邊，上繡著一
朵向日葵中崁有一顆藍色寶石。\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        create_door("south","木門","north",DOOR_CLOSED);
}

