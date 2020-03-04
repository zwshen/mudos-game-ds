#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "墓道");
  set ("long", @LONG
來到這裡，只能摸索前進，甬道漸窄，幾乎抻手不見五指，只能
籍由來路的微光分辨事物，在前頭不遠有個出口，但洞裡昏暗不堪，
只能依稀看到石碑寫著：【萬龍古墓】。
LONG
);

  set("exits", ([
  "north" : __DIR__"room77",
]));
  set("no_recall",1);
  setup();
}

void init()
{
  write(HIW""BLK"前方似乎有些光亮.... 糟糕，來路己無法辨識，現在只有繼續前進了。\n"NOR);
}
