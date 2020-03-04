#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
set_name("[1;30m¶}¤s¤M[0m",({"kaisan blade","blade"}));
set_weight(16600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "§â");
set("long","³o¬O¤@§â¤èÀYªºÅK»s¶Â¦âªø¤M,®³³oºØ¤Mªº¤H³q±`¤£¬O¤°»ò¦n¤H.\n");
set("value",2390);
set("blade",41);
set("material","iron");
        }
set("wield_msg","$N±q¤@®¹³ø¯È¤¤©â¥X¤@§â¾W§Qªº$n\n");
set("unequip_msg", "$N©ñ¤U¤â¤¤ªº$n, ¥Î³ø¯È¥]¦n¦¬ÂÃ°_¨Ó¡C\n");
init_blade(665);
setup();
}
