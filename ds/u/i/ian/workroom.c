#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIC"伊恩的工作室入口"NOR);

 set("long",@LONG
這裡是伊恩工作室的入口, 你前面豎立著一扇鐵門, 鐵門上已經覆上
了厚厚的一層霜, 旁邊的架子上掛著幾件保暖的皮裘, 上面也都蓋著一層
薄霜, 似乎是供入內的人保暖用的, 你一細看, 架子旁掛著一個牌子, 上
[D寫『內部溫度低於攝氏零度, 請穿皮裘入內, 以免凍傷. 』你不禁對這間
工作室的擁有者感到相當的好奇...
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "area":"/u/i/ian/area/birdpill",
                "enter":"/u/i/ian/workroom2",
                "ptstart":"/open/world1/tmr/area/hotel",
    ]));
        set("no_fight", 1);
        set("light",1);
 set("objects",([
 "u/i/ian/weapon/furredrobe":5,
                 ]));
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

