#include <ansi.h>
 
inherit EQUIP;
 
void create()
 
{
 
        seteuid(getuid());
 
        set_name("±m¦â¤Y¤l",({"pill"}));
 
        set("long","±m¦â¤p¤Y¤l\n");

        set("unit","²É");

        setup();

}



void init()

{

        add_action("change","change");

}



int change(float value)

{

        object ob;

        int damage;

        ob = this_player();

this_player()-> set("name",HIM"¯ó²ù"HIC"¦B²N²O"NOR);  return 1;

}

