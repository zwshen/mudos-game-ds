#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{set_name(HIR"血痕"NOR,({"blood blade","blade"}) );
set_weight(37000);//damage*50就是該武器的重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("lone",
"這是一把全身潔白的寶刀,刀刃之間有一個小小的刀痕,似乎只有這刀痕,
與血痕的痕字相合,其潔白的刀刃似乎與其刀名十分的不符合。\n");
set("value",3700);//damage*5就是該武器的價格
set("blade",52);
                set("material", "blacksteel");

set("wield_msg",HIR"$N將$n"+HIR"由腰間抽出\n"NOR);
set("unequip_msg", HIR"$N將$n"+HIR"慢慢放回腰間。\n"NOR);
init_blade(728);
}
setup();
}
int fail_eq(object me)
{
  return 0;
}
void attack(object me,object victim)
{
int damage,str;
if (this_player()->query("air")>50)
{
    if( random(300)> 200 )
{
if(this_player()->query("lck")>random(this_player()->query("level")*10))
if(this_player()->query("mp")>120)
{
str=this_player()->query_str();
damage=random(500)+700;
this_player()->add("mp",-70+random(50));

        victim->receive_damage("hp", damage, me );
message_vision(HIR"突然血痕吸收$N"+HIR"的血之後\n"+
"慢慢透漏出一點點的紅色的殺氣。\n"+"忽然紅色的殺氣化成一把血刀直擊$N\n"
+HIR"$N"+HIR"來不及躲避---["+damage+"]點傷害\n"NOR,victim);
         return;
}
}
}
return;
}
