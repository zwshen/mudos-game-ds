#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW+BLK"陰"HIY"陽"NOR"石", ({ "sun-moon stone", "stone" }));
  set("long",@LONG
一顆結合了陰石和陽石的石頭，似乎有著無窮的力量•
LONG);
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  set("combine_stone_1",1);
  setup();
}

void init()
{
  add_action("do_combine","combine");
}

int do_combine(string str) 
{  int i,j;
  object *inv,ob1,ob2,me;
  me = environment(this_object());
  if( this_player() != me ) return 0;
  j=0;
  if(!str || str!="stone") return 0;
  inv = all_inventory(environment( this_object() ));
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i]->query("id")=="top_grade iron stone") j +=2000; ob1=inv[i];
    if(inv[i]->query("id")=="sun-moon stone") j +=30;  ob2=inv[i]; 
  }
  if(j == 2030)
  {
    new(__DIR__"sun-moon_iron_stone" )->move(environment(this_object()));
    message_vision(HIB"$N將陰陽石和精鐵石放在一起，用盡身上內力硬是將它們結合！\n"NOR,me);
    tell_object(me,HIG"你得到一顆陰陽鐵石！\n"NOR);
    me->set("ap",0);
    destruct(present("top_grade iron stone",this_player())); 
    destruct(present("sun-moon stone",this_player()));
  }
  else return notify_fail("你身上只有一顆石頭而已！\n");
  return 1;
}

