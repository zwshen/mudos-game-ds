// Room: /u/l/luky/sea/sea1.c
inherit ROOM;
void create()
{
set("short", "白沙地");
set("long", @LONG
你正走在一片軟軟的沙地上，踩上去的每一步都留下了一個很深的腳印。
一粒粒白色的沙子有意無意的掉進了你的鞋子，你索性把鞋子拖下來綁在腰際
，赤著腳大步大步到處跑。細柔的沙粒使你的雙腳覺得非常舒暢。
LONG
);
set("Env_sector_type","Under_water");
set("hide_exits", ([
  "west" : __DIR__"pearl_0",
]));
set("exits", ([ 
  "north" : __DIR__"sea8",
  "south" : __DIR__"sea2",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
