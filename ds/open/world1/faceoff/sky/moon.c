// Room: /open/world1/faceoff/sky/moon.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"龍井棧道-斷口處"NOR);
        set("long", @LONG
龍井棧道的道路直到這裡就結束了，你眼下是一片深不見
底的峽谷，氣候涼爽、終年雲霧遼繞。龍井明月為十大自然奇
觀之一，有詩道：明月出龍井，蒼茫雲海間，述盡龍井明月的
美不勝收。
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"ten27",
]));
        set("outdoors", "land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

