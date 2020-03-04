// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "沙地");
set("long", @LONG
你正走在一片軟軟的沙地上。你看到西南方不遠處有個塔, 應該是用來瞭
望遠方的觀測塔吧。周圍佈滿了各式各樣的珊瑚礁岩石, 這裡一點聲音都沒有
, 安靜的讓人害怕, 你感覺到似乎有什麼神秘的生物正在看著你。
LONG
);
set("exits", ([ 
  "west" : __DIR__"sea7",
  "south" : __DIR__"sea5",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
