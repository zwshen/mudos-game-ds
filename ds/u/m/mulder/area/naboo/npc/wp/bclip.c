//bag.c by luky
inherit ITEM;
#include <ansi.h>
inherit F_BULLET;
void create()
{

set_name(HIW"子彈"NOR,({"rifle clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "排");
        set("long","這是手槍的彈匰。裝填指令:(reload clip)\n");
        }
set("value", 1500);
set_weight(1220);
set("amount",20);		//彈藥量
set("bullet/damage",35);	//殺傷力
set("bullet/unit","束");	//彈藥單位
set("bullet/name","激光");	//彈藥名稱
set("type","blaster rifle");		//子彈型式
setup();
}

