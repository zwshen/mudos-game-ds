
inherit ROOM;
void create()
{
set("short","小路");
set("long", @LONG
這裡感覺比較亮了一些, 可能是前方有出口, 你聽到有一些微微的吱
吱聲音. 
LONG
);
set("exits", ([ 
                "west"  : __DIR__"tree3.c",
                "out"  : __DIR__"tree5.c",
                           ]));
set("objects",([
__DIR__"npc/mouse.c" : 2,
              ]) );
        
setup();
        
}

