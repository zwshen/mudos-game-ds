#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "«È©Ð");
        set("long", @LONG
³o¬O´H¦B«È´Ìªº«È©Ð¡A¸Ì­±Â\¤F¦n´X±iªº´H¦B§É¡A³o¬O¥»«È´Ìªº
³Ì¤j¯S¦â¡A§A¥i¥H§äªº¶¶²´ªº´H¦B§É¥h¥ð®§¡A§Éªº«e­±³£·|¥ß¤@±iµP
¤l¡A¤W­±³£·|±Ð§A«ç»ò½m¥\¦^®ð¡A¨ä¹ê¤£±Ð¡A¤j®a¤]À³¸Ó·|§a !(qk) 
LONG
        );
        set("exits", ([
  "out" : __DIR__"hotel.c",
]));
        set("light", 1);
        set("no_clean_up", 0);  
        set("no_fight", 0); 
        set("valid_startroom", 1);
        setup();
}

void init()
{
        add_action("do_qk","qk");
}

int do_qk()
{
        object me;
        me=this_player();
        if( me->query_temp("qk") <= 0 )
        {
                write("§A¥ð®§ªº¦¸¼Æ¨SÂP ~ ~¡I\n");
                return 1;
        }
        if(me->query_temp("is_busy/qking"))
        {
                write("§A¥¿¦bºÎÄ±¡C\n");
                return 1;
        }
        message_vision(HIW "$N§ä¤F¤@±i¶¶²´ªº[36m´H¦B§É[0m¡A¸õ¨ì¤W­±¥h¥ð®§¤F¡ã\n\n" NOR,me);
        tell_object(me, HIC "§A¹B°_¤º¥\\¡A¤Æ´H¦B¤§®ð¬°¤º¤O.....\n\n\n\n" NOR );
        tell_object(me, HIR "§Aªº§¾ªÑ¦ü¥G­á¶Ë¤F..... :)\n\n\n" NOR );
        me->disable_player_cmds("§A¥¿¦b¥ð®§¡C\n");
        me->set_temp("is_busy/qking","§A¥¿¦b¥ð®§¡C");
        me->start_busy(5);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
    tell_object(me,HIG"§A±N¤G¯ß¤§®ðº¥º¥¦^Ã­¡A·Ç³Æ¦¬¥\\¡ã\n"NOR);
        me->receive_heal("hp",me->query_con()*1);
        me->receive_heal("ap",me->query_con()*3);
        me->receive_heal("mp",me->query_int()*2);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIG"§AªºÂù¤â¥ª¥kªº¹º¤F´X°é¡A²´¥Ö¤@¶}¡Aºë¯««ì´_¤F¤£¤Ö\n"NOR);
        me->receive_heal("hp",me->query_con()*3);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIB"$N´£§l¤@¤f®ð¡A¦ù­ÓÃi¸y¡A±q[36m´H¦B§É[0m¤W¨«¤F¤U¨Ó[33m¡C[0m\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/qking");
        me->receive_heal("hp",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*1);
        me->receive_heal("ap",me->query_con()*10);
        me->add_temp("qk",-1);
        return;
}

