#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(MAG"³Â¾Kºj"NOR,({"tranquilizer gun","gun"}));
set("long","¥¦´£¨Ñ¤@ºØ¥i¥H¼È®É¥Ï±¼¼Ä¤H¦ý¤£·|¦Ü¼Ä©ó¦ºªº¤èªk, 
            ¦ý¬O®É¶¡¨Ã¤£¯àºû«ùªø¤[, ÄÝ©ó¥þ¦Û°Êªº°ª¯ÅªZ¾¹[0;1m¡[1mC[0m\n");
        set_weight(2700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "§â");
              set("limit_int",20);
                set("value",2500);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N±q­I«áªº$n®³¤U¨Ó, ±N$nªº«OÀI±ì©Ô¶}¡C\n");
        set("unwield_msg", "$N±N¤â¤¤ªº$n«OÀI±ì±À¦^, ¨Ã©ñ¦^­I¤W¥h¡C\n");
        init_gun(20);   
        setup();
}
void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("gun") > 20 && me->query_int() > 20 && random(10)<3 )
    {
      message_vision(HIW "\n¬ðµM±qºj¤f¼É¥X¤@°¦¤p½b¦V$n¡I¡I\n" NOR,me,victim);
      damage += me->query_skill("gun")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N¤@­Ó¥¢¯«, ³Q³o°¦½b³Â·ô¤F¡I\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
     victim->start_busy(5);
        }
      else message_vision(HIG "$N¤@­Ó¥©§®ªº°j±Û½ð, ±N¤p½bµ¹½ð±¼¤F¡C\n"NOR,victim);
    }
    return;
}

