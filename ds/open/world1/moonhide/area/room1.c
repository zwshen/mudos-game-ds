// Room: /open/world1/moonhide/area/room1.c

inherit ROOM;

void create()
{
        set("short", "不知名的洞口");
        set("long", @LONG
你走到一個山洞前面，左右兩邊都刻滿了詩詞歌賦，文彩豐富，內容
生動，洞前有一小盞的油燈在照明，你一眼望去，裡面盡是一片的黑
暗，一片無止盡的黑暗，如果你有照明設備的話，也許可以看的比較
清楚。往裡面還有一段路。
LONG
        );
        set("current_light", 1);
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("light", 1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"prey" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/open/world1/tmr/gumu/shulin3.c",
]));

        setup();
        replace_program(ROOM);
}

