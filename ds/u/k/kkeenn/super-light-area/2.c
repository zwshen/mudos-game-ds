inherit ROOM;
void create()
{
      set("short","超•光子練習場『初級區』");
      set("long",@LONG
這裡是適合初級生練習的地方，擁有的光束槍無論品質、威力都是最
弱的，以免打傷了別人，可憐這裡的人工動、植物被一堆沒有經驗的菜鳥
轟的東一個洞、西一個洞，眼前就一個新手差點打傷了安全人員....
LONG);
set("exits",([
     "out":__DIR__"1.c",
      "west":__DIR__"3.c",
     "north":__DIR__"7.c",
       "east":__DIR__"5.c",
]) );
set("objects",(
[__DIR__"npc/lv1_guard" : 4]
) );
        set("world", "future"); 
setup();
replace_program(ROOM);
}
