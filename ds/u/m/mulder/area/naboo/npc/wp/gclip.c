//bag.c by luky
inherit ITEM;
#include <ansi.h>
inherit F_BULLET;
void create()
{

set_name("子彈",({"psitol clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "排");
        set("long","這是手槍的彈匰。裝填指令:(reload clip)\n");
        }
set("value", 800);
set_weight(1220);
set("amount",15);		//彈藥量
set("bullet/damage",25);	//殺傷力
set("bullet/unit","束");	//彈藥單位
set("bullet/name","激光");	//彈藥名稱
set("type","laser bolt");		//子彈型式
setup();
}

