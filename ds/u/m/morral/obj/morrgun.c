#include <weapon.h>
#include <ansi.h>

inherit GUN;
void create()
{set_name(HIY"���§Q�M�κj"NOR,({"morral gun","morral","gun"}) );
set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long",HIG"�j�p��W�C\n"NOR);
set("value",200000);
set("rigidity",50000);
set("bullet_type","super-big");
set("max_load",500);
init_gun(3000);
                set("material", "blacksteel");
set("wield_msg","$N�ޥX$n�I\n");
set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
}
setup();
}  