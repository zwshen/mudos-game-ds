inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("[Magic-Card]店老闆", ({ "boss" }) );
  set("gender", "男性" );
  set("age", 22);
  set("long","星空彩繪的店老闆，專門販售 Magic 紙牌。\n");
  set("level",1);
  set("attitude", "friendly");
  set("sell_list",([
  __DIR__"bag1" : 20,  // 目前販賣的版本為第 1 個版本
  __DIR__"bag2" : 20,  // 目前販賣的版本為第 2 個版本
  __DIR__"bag3" : 20,  // 目前販賣的版本為第 3 個版本
  __DIR__"bag4" : 20,  // 目前販賣的版本為第 4 個版本 , 這個版本要感謝 baal 大力幫忙
  __DIR__"box"  : 10,
  __DIR__"browse_card_set" : 10,   // 感謝 cominging 大力幫忙
  ]) );
 setup();
}

void init()
{       
  add_action("do_list","list");
  add_action("do_buy","buy");
}

