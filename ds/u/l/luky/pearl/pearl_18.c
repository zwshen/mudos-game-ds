// Room: /u/l/luky/room/pearl_18.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

  這裡是珍珠北街與[1;33m    ▂▂▂▂▂▂▂[m  珊瑚大道的交叉路口。往
南便是珊瑚大道。[1;33m  ▂[0;33m◢[31m  ≡≡≡≡≡[1;33m▕  ▂[m  北邊有個精緻的道具
屋。整條街由東[33m  ◢[1;33m  ￣￣￣￣￣￣￣￣￣▕[m  向西延伸。
＿＿＿＿＿＿＿＿[33m█[m＿[1;37m  阿爾加斯道具屋[33m  ▕[m＿＿＿＿＿＿＿＿＿＿
"  .   -          ▕[1;33m     ＿＿＿＿[m     ╱:          -  '    "
:      -          ▕ ♁[33m  ◣[1;31m㎜㎜㎜[33m╲[m♁ ▏:          -    "  :
= ."   -          ▕[33m     █[m �翦踛�[1;33m ▏[m ▏:          -       =
==-  " -       -  ▕[33m     █[m │││[1;33m ▏[m ▏:  -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"pearl_22",
"north" : __DIR__"pearl_28",
"west" : __DIR__"pearl_17",
"east" : __DIR__"pearl_19",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
