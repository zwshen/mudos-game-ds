#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit AXE;
void create()
{
        set_name(HIY"光之斧"NOR, ({ "light axe","axe" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這把巨斧十分光滑, 斧柄上刻有索蘭尼亞的記號,\n"
                            "這把斧曾被聖者祝福過, 使得此斧有著神奇的力量。\n");
                set("material", "gold");
                set("limit_str",30);
                set("limit_lv",20);
        }
    set("wield_msg","$N握起$n，頓時一陣耀眼的光芒從$N身上射出！\n");
    set("unwield_msg","$N放下手中的$n，並把$n小心的收好•\n");
    set("weapon_prop/str",2);
    set("weapon_prop/bar",2);
    set("weapon_prop/sou",-1);
    set("weapon_prop/tec",-1);
    init_axe(84,TWO_HANDED);
    set("replica_ob", __DIR__"bigaxe.c");
    setup();
}
void attack(object me,object victim)
{
        int damage,str,con,random1;
        if( random(250)>200)
        {
        str = me->query("con")-random(10);
        con = me->query("con")-random(10);
        random1 = 1+random(2);
        damage = random1*(str+con);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIW"光之斧散發出強烈的閃光。\n"NOR
        +HIY"一條金色的光束從光之斧射出，射中$N。\n"NOR
        +HIY"煞那間，有無數條光束從$N身上往四面八方射出！！！$N吐出了幾大口的鮮血。\n"NOR
        +HIC"結果造成$N"+damage+"點的傷害！！！！\n"NOR
        ,victim);
        return;
        }
}



