#include <path.h>
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("ªZ¿ÄÄl",({"weapon furnace","furnace"}));
  set_weight(99999999);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG
ÅK¦K±M¥Îªº¿ÄÄl¡A¥D­n¬O¥Î¦bªZ¾¹ªº¿Ä¦X¡A¦ý¨D¦¹¤èªk¨Ó·Ò»s
ªº¤H¬O¤Ö¤§¤S¤Ö¡C

  ¨Ï¥Î¤èªk¡G 
  1¡G¥ý©ñ¤J¨âºØªZ¾¹
  2¡G¤ÉÄl¤õ(fireup)

LONG
);

  }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_fireup","fireup");
}

int do_fireup()
{
  object ob = this_object(), *obs, *only_check;
  int i, index = 0;

  obs = all_inventory(ob);
  if(sizeof(obs) < 1) return notify_fail("§A­n©ñ¤JªF¦è¤~¯à¿Ä¦X¡C\n");
  if(sizeof(obs) > 2) return notify_fail("§A©ñ¤JªºªF¦è¤Ó¦h¤F¡I¡I\n"[30m);[0m
  message_vision("\n$N¤É°_¤FÄl¤õ¡A¶}©lªZ¾¹ªº¿Ä¦X ...... \n\n",this_player());


  if(sizeof(obs) > 2)
  {
    message_vision("\nµ²ªG¤°»ò¨Æ³£¨Sµo¥Í.... \n\n",this_player());
    return 1;
  }
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "white crystal") index += 10;
    if(obs[i]->query("skill_type") == "sword") index += 100; 
  }

  only_check = filter_array( children(WD_PAST+"sand/npc/wp/wp12"), (: clonep :) );

  if(index != 110 || sizeof(only_check) > 0 )
  {
    message_vision("\nµ²ªG¤°»ò¨Æ³£¨Sµo¥Í.... \n\n",this_player());
    return 1;
  }

  for(i=0;i<sizeof(obs);i++)
    destruct(obs[i]);

  tell_room(environment(ob),HIW"¤¦Äl¸ÌÃz®g¥X¤@°}±j¥ú ...... §A¬Ý¨ì¤¦Äl¸Ì¦ü¥G§M·Ò¥X·sªºª«¨Æ¡H\n"NOR);
  new(WD_PAST+"sand/npc/wp/wp12")->move(ob);
  return 1;
}

