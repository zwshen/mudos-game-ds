#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
set_name(HIC"【SM用】"HIW"皮鞭"NOR,({"sm whip","whip"}));
set("long","這是一把SM皮鞭,可以增加一些情趣及痛楚.\n");
set_weight(7600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1800);

set("material","iron");
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N從一皮腰際中抽出一條綿長的$n\n");
set("unwield_msg", "$N放下手中的$n, 綑在腰際旁邊。\n");
init_whip(14); 
set("combat_msg", ({   
"$N手握$w﹐一邊大叫:「叫我女王!!叫我女王!!」﹐說著說著把$W甩到對方身上",
"$N用$w往$n的背部「ㄆㄧㄚ!」的一聲鞭了過去﹐但是$N對$n說:「好爽~我還要~」﹐",
"$N用$w把$n的身體纏繞的緊緊的﹐雖然$n快窒息但看起來好像很爽",
"$N握著$w﹐一邊大叫:「叫我的名!!叫我的名!!」﹐然後用把$n身體打成一片條紅班",
"$N趁$n打過來時用﹐$w把$n的武器纏住﹐順便踢了$n幾腳",
}) );
setup();
}

