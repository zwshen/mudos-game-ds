#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name(HIC"¡m¤ý¡ãªÌ¡ã¤§¡ã¸ô¡n"NOR,({"king book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "¥»");
          set("long",
"³o¬O¤@±iªg¨ìµæªoªº¥Õ¯È¡A¤W­±ÁôÁô¬ù¬ù¯B¥X´X­Ó¦r\n"
"²Å¸¹¡A¹ê¤£ª¾¦³¦ó¥Î³~¡C\n");
            }
        set("value", 0);
        set_weight(250);
                set("replica_ob",__DIR__"book1.c");
        setup();
}

void init()
{
        add_action("do_you","you");
}
int do_you(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("¡u¬î¥½­Iºq¡v¥u¯à¹ï¾Ô°«¤¤ªº¹ï¤â¨Ï¥Î¡C\n");

        if (me->is_busy() )
                return notify_fail("§Aªº¤W¤@­Ó°Ê§@ÁÙ¨S¦³§¹¦¨¡A¤£¯à¬I®i¯S§ð¡C\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("§Aªº¨­;
        if(me->query_temp("you"))
                 return notify_fail("§A¤w¥¿¦b¬I®i¤¤¤F¡A¤£¯à¦A¥Î¤F¡C\n");
        message_vision(HIR"\n$N®ð¾®¯«©w¡A§CÁn»¡¤F´X¥y¡A¬ðµM¤j³Ü¤@Án¡A·Ç³Æ¬I®i¥X;

         me->set_temp("you",1);
         me->start_busy(2);
        me->receive_damage("hp",20);
         me->receive_damage("ap",80);
         call_out("do_crazy",4,me,target,6);
         call_out("do_clean",8,me);
         return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
if(me->query("mp")<30 && me->query("ap")<60 ) return notify_fail("§Aªº¨­Åéª¬ªp¤;
     if( random(100)>30 && me->query("ap")>50 && me->query("mp")>30 )
  {
    if(!me) return 0;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("¥Ø¼Ð¦ü¥G²æÂ÷¤F§Aªº§ðÀ»½d³ò..\n");
      return 0;
    }
      message_vision(HIR"\n$N¥õ¤Ñªø¼S¤@Án¡A¥þ¨­¨ª¤õ¥E²{¡A¹ïµÛ"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N¤ß·Ð·N¶Ã¡A¤@®É¶¡¨Ï¤£¥X¡u¬î¥½´dºq¡v¡C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}

