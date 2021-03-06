#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",  "林牧老碑 - " HIM"傳送之陣" NOR);
  set("long", @LONG
你正站在林牧老碑的魔法陣內，你眼前出現了十個
出口，你必須選擇其中一個出口，才能離開這裡。
LONG
);
  set("no_horse_member",1);

  set("exits", ([
  "field1" : __DIR__"field1/room12.c",
  "field2" : __DIR__"field2/room12.c",
  "field3" : __DIR__"field3/room12.c",
  "field4" : __DIR__"field4/room12.c",
  "field5" : __DIR__"field5/room12.c",
  "field6" : __DIR__"field6/room12.c",
  "field7" : __DIR__"field7/room12.c",
  "field8" : __DIR__"field8/room12.c",
]));
  set("no_clean_up", 0);

  setup();
}

void show(object me, int field)
{
string msg = sprintf(
  HIM"\n\t武林傳出了一則驚人的消息:%s(%s)"HIM"冒險闖入"HBK"第%s座幽暗牯牛草原"HIM"了！！\n\n"+NOR
, me->name(), me->query("id"), CHINESE_D->chinese_number(field) );
      message("world:world1:vision", msg ,users());
}

int valid_leave(object me, string dir)
{
switch( dir ) {
case "field1": show(me, 1); break;
case "field2": show(me, 2); break;
case "field3": show(me, 3); break;
case "field4": show(me, 4); break;
case "field5": show(me, 5); break;
case "field6": show(me, 6); break;
case "field7": show(me, 7); break;
case "field8": show(me, 8); break;
} 
        return ::valid_leave(me, dir);
}
