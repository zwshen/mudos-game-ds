inherit ROOM;

void create()
{

set("short","山路");
set("long", @LONG
你正走在崎嶇不平的小山路, 這裡的道路特別窄小, 讓你走起來特別
累, 你不知不覺才發現到你的周圍都是高山和大樹.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "westdown" : __DIR__"cc_2.c", 
        "north" : __DIR__"cc_4.c",
   ]));

 setup();
}

