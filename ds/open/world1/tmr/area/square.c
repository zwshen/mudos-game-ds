// Room: /u/t/tmr/area/square.c

inherit ROOM;

void create()
{
        set("short", "小廣場");
        set("long", @LONG
一座位於城中央的小廣場，廣場中有個大水缸提供給人喝水用，北邊
是座木橋，往東則是通往此地名勝「朝天湖」，不少的旅客從東邊走來，
由他們臉上驚喜、讚喜的表情，你不禁仰慕「朝天湖」的勝景。往西邊就
孟村的東村口。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mstart",
  "north" : __DIR__"wbridge",
  "south" : __DIR__"street4",
  "east" : __DIR__"day_lake",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/obj/pot" : 1,
//       "/open/world1/jangshow/mage":1,
  __DIR__"npc/too":1 ,
  __DIR__"npc/uo":1 ,
  "/open/world1/cominging/area/npc/dove":4,
        ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);

        setup();

}
