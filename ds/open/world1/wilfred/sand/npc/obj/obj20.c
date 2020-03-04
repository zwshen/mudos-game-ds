inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("±s¶º¹Î",({"rice ball","ball"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "­Ó");
    set("value",300);
    set("heal_hp",50);
    set("food_remaining",6);
  }
  setup();
  call_out("it_name",1);
}

void it_name()
{
  string *str = ({
"¶Â­J´Ô¤û¬h",
"¨ý¼W¿N½æ",
"Äªµ«¤â±²",
"»G¨Å­»Âû",
"»Z¿NÅÁ",
"»ñ±ù½¼",
"©@­ùÂû",
"¥j¦­¨ý",
"´I¤h¤s",
"ÂC³½",
"¦×ÃP",
"¾{³½",
"ÂD³½",
"¶Ç²Î"
});
  if(!this_object()) return;
  set("long", "±s¶º¹Î¡A" +str[random(14)]+ "¤f¨ý¡C\n\n\t\t-¦³ 7-11 ¯u¦n-");
  return;
}
