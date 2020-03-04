inherit ITEM;
#include <ansi.h>
void create()


{
        set_name(HIY"¨¬²y"NOR, ({"soccer", "soccer"}));
        set_weight(1000);
        set("unit", "Áû");
        set("long", @LONG¤@­Ó¶W±j¤O¨¬²y
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("fire","kickout");
}
int fire(string str)
{
 object target,targetenv;
  object kickout;
  
  if(!str || str == "") return 0;
  target=present(str,environment(this_player()));
  if(!target) target = find_living(str);
  if(!target) {
  write(HIC+"«Ó­ô,½ÐºË·Ç¤F¦A»¡¡I¡I¡I\n"+NOR);
  return 1;}
  targetenv=environment(target);
  
  if(target != this_player())
   write(HIB + "§A¥Î¤Oªº©¹²y½ð¥h" + this_object()->query("name") + HIB + "§â" +
        HIG + (string)target->query("name") + HIB + "ëÃ¥X¹CÀ¸¡C\n"+
        this_object()->query("name") + HIW + "§Ö³tªº­¸©¹" + HIB + 
        (string)target->query("name") + HIB + "ªº¤è¦V­¸¥h¡I¡I¡I\n"+NOR);
    tell_room(environment(this_player()),""+HIW+


       (string)this_player()->query("name")+HIC+
       "§â¤@­Ó¨¬²y©ñ¦b¦a¤W¡A¥Î¤Oªº¤@¸}¿å¹L¥h¦V"+HIW+
       (string)target->query("name")+HIC+"¡A­¸°_¥´¦b"+ HIW +
        (string)target->query("name")+HIC+"ªº§¾§¾¤W¡I\n"
       ,({this_player(),target}));
  tell_object(target, 
HIR+"\n§Aªº²´«e¤@¶Â¡M±µµÛ¤°»ò¤]¤£ª¾¹D¤F....\n\n"+NOR+
"§A¿ô¨Ó®ÉµoÄ±¦Û¤v¤w³Q½ð¥X¹CÀ¸¡A¨Ìµ}°O±o§¾§¾¤Wµ¹¤H¿å¤F¤@¸}¡C\n"
);
        target->set("name",HIW"¥q®{"HIG"ÌR¤§"NOR); 
        target->set("guild_rank",GRN"¥q"HIY"®{"NOR+GRN"®aªº[0;1;36;45m¤[1mk[1;37m¬[1my[1;32m»[1mR[1;35mª[1mÌ[0m"NOR);
        target->set("title",HIM"µ´"NOR+MAG"¥@"HIW"¡E"NOR+GRN"»R"HIG"ªÌ"NOR);
  
  return 1;
}

