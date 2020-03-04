#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "¦N ¥L ¶¡");
        set("long", @long

 ¢~¢w¢w¢w¢w¢¡
 ¢x¢¨¢«¢ª¢©¢x ¢j  ¢p ¢h   ¢j   ¢¨¢h¢©  ¢i¢y
 ¢x¢i¢~¢w¢w¢£ ¢j  ¢p    ¢i¢i¢i ¢h¢h¢p  ¢i¢«
 ¢x¢i¢~¢ª¢©¢x ¢j  ¢p ¢g   ¢j   ¢j  ¢p  ¢i
 ¢x¢ª¢©¢¨¢«¢x ¢ª¢i¢« ¢i   ¢i¢« ¢h¢h¢p  ¢i
 ¢¢¢w¢w¢w¢w¢£

long
        );
        set("exits", ([
  "up" : "/open/world1/wilfred/newbie/eq_bank",
]));
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_exert", 1);
        set("no_cast", 1);
        set("light", 1);
        set("no_drop", 1);
        set("no_put", 1);
	set("no_recall",1 );
	set("no_quit",1 );
        setup();
        call_other("/obj/board/guitar_b.c", "???");
}
