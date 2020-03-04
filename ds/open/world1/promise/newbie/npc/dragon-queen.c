#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"龍后"NOR, ({ "dragon queen","queen" }));
        set("long","幼龍塔龍王的愛妻，實力儘次於龍王。\n");

        set("race","野獸");
        set("level", 14);
        set("age", 533);  
        set("exp",3000);        set("title",HIR"幼龍谷"NOR);
        set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",3000); 
carry_object(__DIR__"eq/dragon-ring")->wear();}
int special_attack(object me,object target,int hitchance)
{
    if(!me || !target) return 0;
    if(random(10)) return 0;
     {
    message_vision(HIR"龍后大力的往$n身上抓了幾下，造成不可抹滅的傷痕！！\n"NOR,me,target);
      target->receive_damage("hp",30+random(50), this_object());
      return 1; 
    }
   }
void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIW"\n\t\t"+ob->name(1)+""HIY"擊敗了幼龍塔 "HIM"龍后"HIY"，使龍王大發雷霆！！\n\n"+NOR,users());
                ::die();
        return;
}

void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "south")
  {

    message_vision(HIW"龍后怒道：要見我老公，先打到我在說！！\n"NOR,this_player(),this_object());
    
  }
  return 1;
}

