#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIC"碧海餘韻"NOR, ({ "sea blade","blade" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是龍門嘯月的對刀, 在江湖上失蹤已久, 不料今日竟能見到!\n");
                set("material", "blacksteel");
	set("value",20000);
        }
        init_blade(35);
       set("weapon_prop/dex",1);
        set("weapon_prop/str",1);
        set("wield_msg",MAG"$N將碧海餘韻抽出, 剎時隱隱傳來樂韻之聲...。\n"NOR);

        set("unwield_msg",CYN"$N將手中的$n放回刀鞘。\n"NOR);

        setup();
}
