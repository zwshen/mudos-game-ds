// This is a room made by roommaker.
inherit ROOM;
void create()
{
 set("short", "深海斜坡");
 set("long",@LONG
走到這裡幾乎已經沒有什麼光線了，只有一些微弱的光點四處飄來飄去，
彷彿是鬼火一般，列隊歡迎你的到來。水壓越來越大，你的耳朵也因此不停
的嗡嗡作響。這裡的生物十分罕見，其中不乏充滿攻擊性的巨大生物，你的
頭皮已經不由自主的開始發麻，緊握著你的武器以防備隨時都會向你展開攻
擊的致命猛獸。

LONG
);
 set("exits", ([ 
  ]));
 set("hide_exits", ([ 
  "westup" : __DIR__"sea17",
  "north" : __DIR__"sea19",
  "south" : __DIR__"sea36",
  ]));
 set("no_clean_up", 0);
 set("outdoors",0);
 setup();
 replace_program(ROOM);
}
