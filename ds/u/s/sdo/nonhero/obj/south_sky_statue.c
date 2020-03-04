#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"南方增長天天王雕像"NOR,({"south sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
增長天王亦為護世四天王之一，梵名毗樓勒叉，主守護南瞻部洲，常
住天宮，為須彌山第四層之南琉璃埵，是鳩槃荼的魅魔類及薛荔多的
餓鬼類之部主。其本誓為增長自他之威德，且有萬物能生之德分，故
由此而得名。此尊身顏青藍色，手持寶劍，頭戴摩羯獸冠，身鎧甲天
衣，顯微怒相。在諸佛淨土壇城中，司南門守護之職，主降伏。
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","座");
        }
        setup();
}