// Room: /open/world1/tmr/dragoncity/hotel3f.c

inherit ROOM;
void open_star2() {
    "/adm/daemons/event/tidy.c"->trigger_event();
}

void open_star() {
    call_out("open_star2", 60+random(30));
}

void create()
{
        set("short", "磐龍客棧-三樓");
        set("long", @LONG
這兒是磐龍客棧的三樓，由於少帥軍在這處徵兵，所以這間客棧
擠滿了要加入少帥軍的有志青年，也有不少武林同道在這兒喝酒聊天
。只見人聲此起彼落，店家忙得焦頭爛額。
LONG
        );
        set("no_clean_up", 0);
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel2f",
]));
      set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/liruohai" : 1,
  ]));


        setup();
}

