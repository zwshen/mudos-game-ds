#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"µµ¬âÀJ¹³"NOR, ({"statue"}) );
      set("long", @LONG 
¤@°¦¤j«¬ªº¥¨óç[0;1m¡[1mA[0m®ÇÃä¦³¤@­ÓÂ_¤F¥kÁu¥B©ÜµÛ¤@¤Ç¯}
©Ü­·ªº¤H[0;1m¡[1mA[0m¥ªªÓÁÙ­IµÛ¤@¬`¥¨¼C[0;1m¡[1mA[0m¤£ª¾¹D¬O½Ö ? 
[³o®yÀJ¹³¦n¹³¥i¥H²¾°Ê(move)ªº¼Ë¤l?]
LONG
 );

        set_weight(9999999);
        set("unit", "®y");
        set("no_sell", 1);
        set("no_give", 1);
        set("no_get", 1);
        set("no_drop", 1);

        setup();
}
void init()
{
    add_action("do_move","move");
}
int do_move(string arg)
{ 
    object me=this_player(),ob=this_object(),mobp; 
    if(ob->query_temp("moved")) return notify_fail("­è­è¦³¤H²¾°Ê¹L¤F¡C\n");
    if(!arg||arg!="statue") return notify_fail("§A­n²¾°Ê¤°»ò?\n");
     switch (random(4) ){ 
                case 0:
      message_vision("$N±N"+ob->name(1)+"²¾°Ê¤F¤@ÂIÂI¡Iµo¥X¤F¡y¹É¹É¡zªºÁnÅT..\n",me); 
      tell_object(me,"¨Ã¨Sµo¥Í¤°»ò¨Æ...\n");
                      me->start_busy(2); 
                      ob->set_temp("moved",1); 
                      call_out("stop_moved",600,ob);
                      break;
               case 1:
      tell_object(me,"ª`·N¡I\n");
      message_vision("$N±N"+ob->name(1)+"²¾°Ê¤F¤@ÂIÂI¡Iµo¥X¤F¡y¹É¹É¡zªºÁnÅT..\n"
                     "¬ðµM¤@¹D¥¨¤jªº¶Â¼v­°Á{....\n",me);
                     me->start_busy(3);
                     mobp=new(__DIR__"god-prey"); 
                     mobp->move(environment(this_player()));   
                     mobp->kill_ob(this_player()); 
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",600,ob);
                     break;   
/*·s¼W By Jangshow */

               case 2:
       message("world:world1:vision","\n\n"+HIW"¤@°}¨g­·¡I±½¿º¦b¥j¹Óªº¥~³ò¡I¥¨¸V¯«óç¥ÑªÅ¤¤¸¨¤U¡I\n\n"+NOR,users());
                     mobp=new(__DIR__"god-prey");
                     mobp->move(environment(this_player()));
                     mobp->set("level",70+this_player()->query("level")/6);   
                     mobp->kill_ob(this_player());
                     me->damage("hp",500);
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",1000,ob); 
                     break;
                 }  
        return 1;
}
void stop_moved(object ob)
{
     if(!ob) return; 
     ob->delete_temp("moved");
}

