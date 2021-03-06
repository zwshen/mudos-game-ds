// Room: /open/world1/tmr/bagi/ghat4.c

inherit ROOM;

void create()
{
        set("short", "雪地");
        set("long", @LONG
你正在一片冰天雪地之中，由於地處於高山上，終年下雪，四周只有
數株長青的松柏，往西南方有條叉口，往東北方過去，風雪更盛。遠遠地
似乎望見一片大湖。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northeast" : __DIR__"ghat6",
          "southwest" : __DIR__"ghat3",
        ]));
        set("outdoors","snow");
        set("world", "past");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
