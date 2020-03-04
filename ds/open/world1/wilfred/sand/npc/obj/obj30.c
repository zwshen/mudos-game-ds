inherit ITEM;
void create()
{
  set_name("ª÷Äq",({"gold mine","mine"}));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else set("value",10000);
  setup();
}