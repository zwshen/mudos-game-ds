inherit ROOM;

void create()
{

set("short","化┬");
set("long", @LONG
硂柑碞琌化糂吩┬, ㏄, 祇瞷硂柑ヴ妓珇
常琌禥, オよ本碭碩礶. 
LONG
);
set("light",1);
set("exits", ([                
"south" : __DIR__"aa_4.c",        

]));
set("objects",([
__DIR__"npc/king1.c" : 1,
              ]) );

setup();
}


