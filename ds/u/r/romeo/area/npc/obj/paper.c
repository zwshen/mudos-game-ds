#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name("¥Õ¯È",({"paper}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "±i");
          set("long",
              "³o¬O¤@±iªg¨ìµæªoªº¥Õ¯È¡A¤W­±ÁôÁô¬ù¬ù¯B¥X´X­Ó¦r\n"
¡@¡@¡@¡@¡@¡@¡@"§A¥Î¤O¤@¬Ý­ì¨Ó¬O"MAG"¤ý¡ãªÌ¡ã¤§¡ã¸ô"NOR"¥|­Ó¦r\n");
            }
        set("value", 0);
        set_weight(110);
                set("replica_ob",__DIR__"book.c");
        setup();
}

void init()
{
        add_action("do_godie","godie");
}
int do_godie(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("¡u¤ýªÌ¤§¸ô¡v¥u¯à¦b¾Ô°«¤¤¨Ï¥Î¡C\n");

        if (me->is_busy() )
                return notify_fail("§Aªº¤W¤@­Ó°Ê§@ÁÙ¨S¦³§¹¦¨¡A¦A¹B¥\´N·|´²¥\¤F¡C\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("§Aªº¨­;
        if(me->query_temp("godie"))
                 return notify_fail("§Aªº©Û¦¡ÁÙ¨S¬I®i¡AµLªk¦A¨Ï¥Î¤F¡C\n");
        message_vision(HIR"\n$N®ðÄé¤¦¥Ð¡A¥k¤â¤@§Ý¡A·Ç³Æ¬I®i¥X;

         me->set_temp("godie",1);
         me->start_busy(2);
        me->receive_damage("hp",30);
         me->receive_damage("ap",90);
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
      return notify_fail("¹ï¤è¤w¸g§¨µÛ§À¤Ú¶]¤F¡C\n");
      return 0;
    }
      message_vision(HIR"\n$N¤@Án¨g¼S¡A¦b$Nªº­±«e¥X²{¤@¤f¥¨¼C¡A¹ïµÛ"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N©¿µM¤@¤fÂA¦å´é¥X¤f¤¤¡A¤@®É¶¡¨Ï¤£¥X¡u¤ýªÌ¤§¸ô¡v¡C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}

