#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("彈夾",({"clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","是一個多用途的金屬製彈夾,每一組彈夾都裝有10發子彈。\n");
        }
      set("value", 400);
   set_weight(1000);
set("amount",10);                //彈藥量
  set("bullet/damage",20);        //殺傷力
set("bullet/unit","發");        //彈藥單位
set("bullet/name","子彈");      //彈藥名稱
set("type","clip");            //子彈型式
setup();
}
