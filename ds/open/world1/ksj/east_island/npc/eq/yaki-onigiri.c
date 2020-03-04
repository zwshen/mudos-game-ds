inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("御飯糰", ({"Yaki onigiri","onigiri"}));
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "將飯糰捏成圓三角形，包入梅干，便於攜帶食用。\n");
    set("unit", "個");
    set("value", 10);  
    set("food_remaining",1);
    set("heal_hp",30);  
    set("heal_ap",15);  
  }
}


