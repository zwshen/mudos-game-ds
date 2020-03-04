// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","針葉林");
       set("long", "這是極西天山腳下的一片針葉林，林中鳥獸成群，滿地鋪蓋著厚厚一
層鬆針。西北方的一座高聳的山脈便是天山了，山上終年積雪，山下卻是
綠樹成蔭。往東南走便是大草原，有辛勤的哈薩克族人在那裡放牧。\n");

        set("exits", ([
        ]));
        
        set("outdoors", "forest");

        setup();
       replace_program(ROOM);
}