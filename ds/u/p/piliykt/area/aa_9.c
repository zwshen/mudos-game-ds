inherit ROOM;

void create()
{

set("short","練武場");
set("long", @LONG
你來到了這裡才發現到原來這裡是練武場, 這裡是趙王花費大筆的金
錢所投資的個人專屬戶護衛訓練的地方, 你處處可見這裡有許多的護衛弟
子再這練習武藝.
LONG
);
set("world", "past");
set("light",0);
set("exits", ([                

"west" : __DIR__"aa_5.c", 
"east" : __DIR__"aa_10.c", 
]));
set("objects",([
__DIR__"npc/trainee1" : 3,
              ]) );

setup();
}

