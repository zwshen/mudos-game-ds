#include <room.h>
inherit ROOM;

void create()
{
  set("short","木橋邊");
  set("long",@LONG
這個地段是裴伊川河床最狹隘的地點，往北就是危險重重的出雲
山，往南則是詭異的鬼之森，所以當初村民選擇在此地建造木橋，以
討伐天狗，事過境遷，木橋上滿是蛀孔及坑洞，不過小心一點倒還能
通行。
LONG);
  set("exits",([ 
      "west":__DIR__"room61",
      "south":__DIR__"room58",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
