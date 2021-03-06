//2003.3.14 新增combine為 fly-sea-stone 的功能  by ksj
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIC"碧 海 石"NOR, ({ "sea stone", "stone" }));
  set("long",@LONG
一塊晶瑩澄澈的玉石，從形狀可以看出經過精心雕琢，感覺有股力量
充斥其周圍，碧海石之間會相互吸引結合(combine)。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 1);
    set("no_sell", 1);
    set("no_sac", 1);
    set("seastone", 1);
  }
  setup();
}

void init()
{
  add_action("do_combine","combine");
}

int do_combine(string str)
{
  int i,j;
  object *inv,ob1,ob2,ob3,me;
  me = environment(this_object());
  if( this_player() != me ) return 0;
  j=0;
  if(!str || str!="stone") return 0;
  inv = all_inventory(environment( this_object() ));
  for(i=0;i<sizeof(inv);i++)
  {
    if( inv[i]->query("seastone") ) j++;
    if(inv[i]->query("seastone") && j==1) ob1=inv[i];
    if(inv[i]->query("seastone") && j==2) ob2=inv[i];
    if(inv[i]->query("seastone") && j==3) ob3=inv[i];
  }
  if(j >= 3)
  {
    new(__DIR__"fly-sea-stone" )->move(environment(this_object()));
    message_vision(HIW"$N將三顆碧海石放在一起，碧海石立即吸引結合，發出耀眼光芒。\n"NOR,me);
    destruct(ob3);
    destruct(ob2);
    destruct(ob1);
  }
  else if(j >= 2)
  {
    message_vision("$N將碧海石放在一起，碧海石相互吸引，真是有趣。\n",me);
  }
  else return notify_fail("你身上只有一顆碧海石而已！\n");
  return 1;
}
