inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("火藥",({"bullet"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "散");
        set("long","這是火槍專用的彈藥, 填裝指令: reload\n");
        }
set("value", 100);
set_weight(1100);
set("amount",1);                //彈藥量
set("bullet/damage",10);        //殺傷力
set("bullet/unit","散");        //彈藥單位
set("bullet/name","火藥");      //彈藥名稱
set("type","small");            //子彈型式
setup();
}
