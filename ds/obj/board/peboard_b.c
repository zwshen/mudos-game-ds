#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"¥jªF°Q½×ªO"NOR,({"PE board","board"}));
set("location","/u/j/jsh/workroom_pe");
        set("board_id", "peboard_b");
        set("long",
        "[0;5;34m½[5mÐ[5m¯[5md[5m¨[5m¥[0m¡C\n");
        setup();
        set("capacity",300);
set("master",({ "jsh"}));
 
}

