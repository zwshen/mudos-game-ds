inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIR"《要你命三千》"NOR, ({ "kill 3000", "3000" }));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "本");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
  }
  setup();
}

void init()
{
  add_action("do_killallmob","killallmob");
}

int do_killallmob()
{
        object ob,me,env,*target; 
        int x=0;
        ob = this_object();
        me = this_player();

        target = all_inventory(environment(me));

//      if( !ob ) return 0;
//        if( !env = environment(me)) return 0;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");

        if( me->is_fighting() )
            me->start_busy(1);

                message_vision(HIR "$N從背後拿出摺好的板凳，掃視著在場的所有生物\n\n" NOR,me);

                for(x;x<sizeof(target);x++){
                 if( !living(target[x]) ) continue; 
               if( target[x]->is_fighting(me) ) continue; 
                    if( target[x] == me ) continue;

                    message_vision(HIY"$N突然對著$n喊到：得罪了方丈還想走！！\n\n"NOR,me,target[x]);
                    me->kill_ob(target[x]);
                    target[x]->kill_ob(me);
                    }    
                return 1;      
}
