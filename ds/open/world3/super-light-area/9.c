inherit ROOM;
void create()
{
     set("short","超•光子練習場『中級區』");
      set("long",@LONG
這裡是普通人的終極之路，接下來的就要靠自己的努力了！如果你是
擁有獵人執照的話，你要在北方的『超•試煉之場』得到優勝，將能朝下
一個目標前進吧！
LONG);
set("exits",([
      "east":__DIR__"8.c",
      "north":__DIR__"13.c",
]) );
set("objects",([
__DIR__"npc/lv14"   :4
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
