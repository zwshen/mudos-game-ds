#include <ansi.h>
#include <armor.h>
inherit NECK; 
string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});
void create()
{
set_name(HIY"日月法鍊"NOR,({"sun-moon necklace","necklace"}));
set("long", @LONG
一條飽含日月力量的項鍊，不論何處總是發出光芒，握在手中還
有著溫暖的感覺，你覺得這條項鍊真是不平凡•
LONG);
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",3);
    set("value",0); 
    set("material","gold");
  }
  set("wear_msg", "$N穿上一"+this_object()->query("unit")+"$n，感覺有如日月繯繞在身旁•\n");
  set("limit_lv",44);
  set("armor_prop/armor",3);
  set("armor_prop/shield",15); 
  set("armor_prop/wit", 1); 
  set("armor_prop/tec",-1); 

  set("armor_prop/str",-3); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",-1); 
  setup();
  call_out("receive_by_necklace", 70);
}

void receive_by_necklace()
{
        object me = environment(this_object());
        int p_mp, i;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/neck") == this_object())
        {
                p_mp = me->query("max_mp");
                if( me->query("mp") < p_mp*2/3 )
                {
                        me->receive_heal("mp", p_mp*1 / 20);
                        for(i=0;i<sizeof(wounds);i++)
                                me->receive_curing(wounds[i], 1); // 療傷
                        tell_object(me,HIY"\n日月法鍊傳出一股溫暖的氣息，你心靈感到一股充實感......\n"NOR);
                }
                else
                {
                        tell_object(me,HIY"\n日月法鍊傳出一股溫暖的氣息，但是沒有什麼事發生！\n"NOR);
                }
        }
        call_out("receive_by_necklace", 90);
} 

void init()
{
        if(!this_object()->query_light())
                this_object()->start_light(1);
}

