#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("¬õ¹Ðº¾¸H¨Æ",({"board"}));
set("location","/u/f/fanny/workroom.c");
        set("board_id", "fanny_b");
        set("long",
        "¤@¶ô±K±K³Â³Â¼gº¡¤F¦rªºÁ¡¤ìªO¡C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
