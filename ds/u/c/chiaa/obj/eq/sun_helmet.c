//u/c/chiaa/obj/eq/sun_helmet.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
  set_name(HIY"旭日"WHT"頭"HIB"盔"NOR ,({ "sun helmet","helmet" }));
  set("long", "這是用黃金與天然的礦石加工而成的頭盔,散發出耀眼的光芒,
     就好像旭日東昇一般.\n");
    set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "頂" );
              set("material", "gold ore");  //材質 金 礦石            
              set("armor_prop/armor", 30);  //防禦力+30
              set("armor_prop/shield", 5);  //抵抗+5
              set("value", 2000); //價值
              set("wear_msg","$N將$n緩緩戴在頭上,全身散發出耀眼的光芒!!\n");
              set("unequip_msg","$N將$n卸下,光芒隨即散去。\n");
        }
              set("weapon_prop/force",15);        //加 enable 技能15
 
        setup();
}
