inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("弩箭",({"bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "捆");
        set("long","一捆柳木箭身的箭, 可以提供良好的射程與殺傷力, 請用reload 指令將它放入武器內.\n");
        }
set("value", 70);
set_weight(900);
set("amount",15);                //彈藥量
set("bullet/damage",30);        //殺傷力
set("bullet/unit","隻");        //彈藥單位
set("bullet/name","弩箭");      //彈藥名稱
set("type","small");            //子彈型式
setup();
}

