inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("米格60彈夾",({"mag clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個金屬製的彈夾, 每一組彈夾都裝有10發子彈。\n");
        }
        set("value", 800);
        set_weight(500);
        set("amount",10);
        set("bullet/damage",25);
        set("bullet/unit","發");
        set("bullet/name","子彈");   
        set("type","mag"); 
        setup();
         }

