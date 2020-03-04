#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()
{
set_name("[1;36mÂy¤M[0m",({"hunt blade","blade"}));
set_weight(36400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "§â");
set("long","³o¬O¤@§â¾W§QµL¤ñªºªø¤M,±`¥Î¨Ó¥´Ây¥Îªº\n");
set("value",4368);
set("blade",52);
set("material","iron");
        }

init_blade(728);
setup();
}
