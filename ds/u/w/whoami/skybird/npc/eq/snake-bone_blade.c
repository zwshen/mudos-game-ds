#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIW"蛇骨刀"NOR, ({ "snake-bone blade","blade" }) );
        set_weight(7400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把"); 
                set("long", "一把純白的利刃，不知道到底是用什麼做成的•它摺疊的刀身，\n"
                            "剛好能用來攻擊遠方的敵人•\n");
                set("material", "gold");
                set("value",17000);
                set("limit_str",47); 
                set("limit_level",30);
        }
    set("weapon_prop/str",2);
    set("weapon_prop/dex",2); 
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_whip(69);
    setup();
}

