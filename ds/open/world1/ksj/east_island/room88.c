#include <room.h>
inherit ROOM;

void create()
{
  set("short","竹屋");
  set("long",@LONG
這裡是一間竹子搭建的小屋，屋子的裡面沒有什麼擺設，屋外插
了幾個竹枝紮成的假人，地上佈滿了深深的腳印，有幾尊假人爆碎散
落一地，甚至是剩下一根焦黑的竹架空立著。
LONG);
  set("exits",([ 
      "east":__DIR__"room85",
     ]));
  set("no_clean_up",0);
  set("light","1");
  set("objects",([
      __DIR__"npc/asahi":1,
     ]) );
  setup();
}            
