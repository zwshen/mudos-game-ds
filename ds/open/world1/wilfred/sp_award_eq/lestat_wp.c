#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
        set_name(HIR"血魂"NOR,({"blood soul","blood","claw","soul","fist"}) );
        set ("long", @LONG
血紅色的拳套，突出四根銀白色的利爪，拳套末端有像是樹根
般的管狀物直接插入使用者的經脈之中，跟使用者連為一體，
具有強大的威力。
LONG
);
        set_weight(2000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","對");
        set("value",5000);
        set("material","steel");
        set("volume",3);
        set("no_drop",1);
        }
        set("weapon_prop/bar",1);
        set("weapon_prop/str",2);
        init_fist(60);
        setup();
}

int query_autoload() { return 1; }   

