inherit ROOM;
void create()
{
     set("short","超•光子練習場『中級區』");
      set("long",@LONG
啊…這裡的機器人明顯的跟剛才的肉腳不一樣，他們不只有配槍，和
左手臂的光子能，天啊！要是它們故障發起瘋來，到處亂開槍，光束的威
力是很可怕的！！
LONG);
set("exits",([
      "east":__DIR__"11.c",
      "west":__DIR__"7.c",
]) );
set("objects",([
__DIR__"npc/lv11"  :4,
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
