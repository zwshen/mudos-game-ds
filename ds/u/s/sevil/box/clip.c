inherit ITEM;
inherit F_BULLET;
void create()
{

        set_name("彈夾",({"clip"}));
        set("long","一個金屬製的彈夾，裡頭裝著左輪手槍型的子彈。裝填指令:(reload clip)\n");
        set_weight(1220);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("value", 200);
        set("unit", "個");
        set("amount",6);                //彈藥量
        set("bullet/damage",15);        //殺傷力
        set("bullet/unit","發");        //彈藥單位
        set("bullet/name","子彈");      //彈藥名稱
        set("type","left_gun");            //子彈型式
        }
        setup();
}


