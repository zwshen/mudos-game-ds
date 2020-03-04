#include <ansi2.h>
#include <weapon.h>
inherit FORK;

void create()
{
        set_name(HBK"大槍"NOR,({"greatly pike","pike"}) );
        set("long",@LONG
這是把吳鐘早年在武林中揚名立萬的大槍，相傳是由不知名的隕
石上，提煉深綠色的金屬，凝聚天地之精氣而鑄成。吳鐘晚年已
經不再使用這把大槍了，但是他的槍法在武林中的地位，卻是從
來沒有人可以撼動的。
LONG
        );
        set_weight(25000);
        if (clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit","桿");
                set("value",17000);
                set("volume",5);
                set("material","steel");
        }
        set("weapon_prop/bar",1);
        set("weapon_prop/wit",-1);//sV1
        init_fork(58);
        setup();
}


