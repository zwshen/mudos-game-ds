#include <weapon.h>
inherit F_BLADE;

void create()
{
        set_name("天王長刀", ({ "tian-wang long blade","blade" }) );
        set_weight(5000);
          setup_blade(4, 10, 80, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blade"}));
                set("unit", "把");
                set("value",12000);
                set("rigidity", 80);
                set("long",@long
　　這是一把造型十分特殊的長刀，刀鋒上有著流水般的符號，在陽
光映射下，隱隱然透露出兇邪的殺氣。此刀為江湖上有名的硬幫幫首
領－宋天王的愛用刀之一。
long
        );
        }
         set("apply_weapon/twohanded blade", ([
                        "cps":2,
                        ]));

        setup();
}


