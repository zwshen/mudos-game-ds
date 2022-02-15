inherit ROOM;

void create()
{
  set("short", "雙貝酒吧");
  set("long", @LONG
這個酒吧的四周牆上裝飾排列著各種貝殼，看得你都眼花繚亂，
這間酒吧的主人是在港都長大的，自小就有搜集貝殼的嗜好，長大後
就開了這家酒吧，你四處看了一下，發現連酒杯也是使用貝殼製作。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room19",
      "southeast" : __DIR__"room24",
     ]));  
  set("objects",([
      __DIR__"npc/room20-boss":1,
     ]));
  set("light",1);
  setup();
}
