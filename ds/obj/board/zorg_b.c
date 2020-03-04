#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("¶®©Î¯d¨¥ªO(Zorg's Board)",({"board"}));
        set("location","/u/z/zorg/workroom.c");
        set("board_id", "zorg_b");
        set("long",
        "Please live your message in here,If you have any question look help board¡C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}


