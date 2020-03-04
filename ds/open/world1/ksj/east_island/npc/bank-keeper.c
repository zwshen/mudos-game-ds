#include <ansi.h>
inherit NPC;
inherit BANKMAN;

void create()
{
  set_name("佐佐木" , ({ "bank keeper","keeper" }) );
  set("level",3);
  set("no_fight",1);
  set("race","人類");
  set("gender","男性");
  set("age",45);
  set("talk_reply","這裡能提錢(withdraw)、存錢(deposit)以及查詢(balance)");
  set("long","他是這間錢莊的老板。\n");
  setup();
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
