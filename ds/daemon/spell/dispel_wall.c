// ¸Ñ°£µ²¬É¤§³N -Luky-
//

#include <ansi.h>
inherit SKILL;
int break_wall(object wall);
int cast(object me, object target,string dir)
{
    object wall1,wall2,env,env2;
    mapping wall=([]);
    if(!target) return notify_fail("cast dispel_wall on <µ²¬É> ©Î cast dispel_wall at <¤è¦V>\n");
    env=environment(me);
    if(!dir) // cast on wall.
    {
        //find other-side wall.
        if( living (target) )
            return notify_fail("¦¹ªk³N¤£¯à¥Î©ó¥Íª«¤W¡I\n");
        wall1=target;
        if(!wall2=wall1->query("link_wall")) return notify_fail("¬Iªk¥Ø¼Ð²§±`¡I¿ù»~¥N½X: sp_dw_1\n");
    }
    else //cast on other room. ignore target.
    {
        if(!wall1=env->query_temp("wall/"+dir)) return notify_fail("¨º­Ó¤è¦V¨S¦³µ²¬É¡I\n");
        if(!wall2=wall1->query("link_wall")) return notify_fail("¬Iªk¥Ø¼Ð²§±`¡I¿ù»~¥N½X: sp_dw_3\n");
    }
    if( environment(me)->query("no_magic") )
        return notify_fail("³o­Ó¦a¤è¤£¥i¥H¬Iªk¡I\n");
    if((int)me->query("mp") < 40 )
        return notify_fail("§Aªºªk¤O¤£°÷¡T\n");
    me->add("mp", -40);
    me->start_busy(2);
    message_vision("\n\n\t$N±NÂù¤â±i¶}¡A§CÀYÀq©À:[1;33m§ÎµLÅé¡ãªkµLÃä¡ã¯«¥ú²{¡ãÅ]»Ù¯}[0m\n\n",me);
    call_out("do_dispel",2,me,wall1,wall2);
    return 1;
}

int do_dispel(object me, object wall1,object wall2)
{
    int hard,sp,intt;
    if(!me)
    {
        return 1;
    }
    if(!wall1 || !wall2)
    {
        message_vision("$N©ñ±ó¤F³o¦¸ªº¬Iªk¡C\n",me);
        return 1;
    }
    if(environment(me)!=environment(wall1))
    {
        message_vision("$Nªº¬Iªk³Q¤¤Â_¤F¡C\n",me);
        return 1;
    }
    hard=wall1->query("level");
    sp=me->query_spell("dispel_wall");
    intt=me->query_int();
    message_vision(HIW+"$N²rµM¦X´x¡A¤@¹D©_²§ªº¥ú¨~¨³³t®g¦V$n¡A"+NOR,me,wall1);
    if(random(intt+sp/2)<=random(hard))
    {
        message_vision(HIW+"¦ý«o³Q$N¼u¤F¶}¨Ó¡T\n"NOR,wall1);
    }
    else
    {
        message_vision(HIW+"$N³Q¥ú¨~©Ò¥]¦í¤F¡T\n"+NOR,wall1);
        break_wall(wall1);
        break_wall(wall2);
    }
    me->improve_spell("dispel_wall",1+random(intt/3));
    return 1;
}

int break_wall(object wall)
{
    if(!wall) return 0;
    if(environment(wall))
    {
        tell_room(environment(wall),"·¥¥úµ²¬É¶}©lÅÜ±o³z©ú¦Ó³vº¥®ø¥¢¤F¡I\n");
        environment(wall)->delete_temp("wall/"+wall->query("dir"));
        destruct(wall);
    }
    return 1;
}
