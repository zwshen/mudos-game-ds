#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石屋中");
set("long",@LONG
你矮身進入了石屋中, 立刻發現有一雙充滿殺意的眼神從
黑暗中射出! 你心裡一驚, 定了定神後, 方才發現有一個受了
傷的彪形大漢臥在草席上, 看來似乎有些怪怪的....
LONG
    );
 set("exits",([ "out":__DIR__"seacoun27",
]));
set("objects", ([__DIR__"../npc/yu" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}            