inherit ITEM;

void create()
{
  set_name("sk3年輕乳霜", ({ "sk3 lotion","lotion" }) );
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "這是目前最暢銷的產品,擦(use)了看起來會變年輕。\n");
    set("unit", "瓶");
  }
  set("value", 30000);
  set("lotion_remaining", 2);  // 設定可使用的次數
  setup();
}

void init()
{
  add_action("do_use","use");
}

int do_use()
{
  object me=this_player(),ob=this_object();

  me->add("age", -1);  // 設定要回復什麼數值

  ob->add("lotion_remaining",-1);
  if(!ob->query("lotion_remaining"))
  {
    message_vision("$N將全部的$n塗光了,整個人變得春光蕩漾。\n",me,ob);
    destruct(ob);
    return 1;
  }
  message_vision("$N拿起一瓶$n在臉上不停的塗抹,似乎年輕了起來。\n",me,ob);
  return 1;
}

