#include <weapon.h>
#include <ansi.h>

inherit F_SWORD;
inherit F_UNIQUE; // only one

void create()
{
        set_name(HIW "御虛長劍" NOR, ({ "dominate long sword", "sword" }) );
        set_weight(1000);
        setup_sword(3, 13, 80, 6);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "把");
                set("value", 12000);
                set("rigidity", 60);
                set("apply_weapon/sword", ([
                        "con":2,
                        "str":-1,
                ]));
                set("long", @LONG
這是一把劍身薄的尤如一張紙的長劍，似乎沒什麼重量，風一吹就能
吹走的樣子。雪凝般的白色光線正從劍身展現開來，使得四周似乎明亮許
多，這把似乎就是傳說中的斬妖寶劍了。
LONG
);
        }
        setup();
}

/*
int inflict_damage(string strength, object victim)
{
        int dam = ::inflict_damage(strength, victim);
        if( dam && random(100) < 40 ) {
                environment()->add_temp("fight_msg", HIW "凌虛長劍射出一道刺眼的光芒，" NOR);
        }
        return dam;
}
*/

