inherit ROOM;
void create()
{
     set("short","超•光子練習場『中級區』");
      set("long",@LONG
這裡的生化人越來越強，不難看出自己已經快要到達二級殺手的功力
了！再往下走下去就快到達試煉之所了，真是步步為營ㄚ，西邊隱隱傳來
可怕的怒罵聲....
LONG);
set("exits",([
      "east":__DIR__"7.c",
      "west":__DIR__"9.c",
]) );
set("objects",([
__DIR__"npc/lv13"   :4
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
