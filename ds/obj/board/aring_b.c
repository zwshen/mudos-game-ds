#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"¼C"NOR+CYN"ªL¸O"NOR,({"aring's board","board"}));
    set("location","/u/a/aring/workroom");
    set("board_id", "aring_b");
    set("master",({"acme"}) );
    set("long",
      "[36m¬ö¿ý¤@¨Ç¤j¤p¨Æ±¡ªº®Ñ¡C[0m\n");
    setup();
    set("capacity",100);

}



