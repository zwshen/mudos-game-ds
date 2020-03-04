inherit ITEM;

void create()
{
  set_name("µP²°", ({ "deck box","box" }) );
  set("long",@LONG
µP²°¡C
LONG
);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "­Ó");
    set("volume",6);
    set("value",500);
  }
  setup();
  set_max_capacity(40);
  set_max_encumbrance(25000);
}

int query_autoload() { return 1; }

