inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("超級槍彈夾",({"super bullet clip","bullet","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個金屬製的彈夾, 每一組彈夾出廠時都裝有500發子彈。裝填指令
:reload clip");
        }
set("value", 600);
set_weight(1220);
set("amount",500);
set("bullet/damage",2200);
set("bullet/unit","發");
set("bullet/name","巨彈");
set("type","super-big");
setup();
}
