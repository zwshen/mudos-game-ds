#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIR"熊之臂彎"NOR,({"bear bolt", "bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "隻");
        set("long","一隻箭頭鋸齒狀的好箭, 有如熊爪, 可以將箭緊緊咬入裝甲之中.\n");
        }
set("value", 80);
set_weight(1200);
set("amount",1);                //彈藥量
set("bullet/damage",20);        //殺傷力
set("bullet/unit","隻");        //彈藥單位
set("bullet/name","弩箭");      //彈藥名稱
set("type","small");            //子彈型式
setup();
}

