#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIG" S"HIC"p"HIR"e"HIM"c"HIY"i"HIB"a"HIW"l "HIG"H"HIC"E"HIR"A"HIM"D "NOR, ({ "special_thing", "thing", "object" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","This is a special mark by cominging, this is what can invisible you name. \n");
                set("unit", "件");
                set("material", "unknown");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",1);
        }
        //============以下片段開放區域勿用, 否則會大混亂===============
        //==    若開放區域要寫此種偽裝eq , 必定要設為 Only One EQ    ==
        set("armor_prop/id",  ({ "Unknown person", "person" }));
        set("armor_prop/name",({"迷樣人物"}));
        set("armor_prop/short",({"迷樣人物 〈Unknown person〉"}));
        set("armor_prop/long", ({HIW"一陣白光閃入你的雙眼，完全看不到東西\n"NOR}));
        //==============================================================
        setup();
}

int query_autoload() { return 1; }

