#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name(MAG"十方靈動"NOR,({"viper dagger","dagger"}) );
        set("long","一把紫色的匕首，形狀像是一條蛇，當你注意看時，好像會如有生命般
緩緩遊動，匕上有隱隱約約的看到一層紫氣。\n");
        set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value",40000);
              set("limit_level",12);
              set("material", "blacksteel");
        }
        set("wield_msg","$N握住了$n，手上紫氣隱隱顯現。\n");
        init_dagger(40);
        set("replica_ob", __DIR__"dagger.c");
        set("weapon_prop/bar", 1);
        set("weapon_prop/dex", 3);
        set("weapon_prop/int", 4);
        setup();        
}
