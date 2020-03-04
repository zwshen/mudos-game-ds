inherit ITEM;
void create()
{
  set_name("銀色箱子",({"silver box","box"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","不知裡面裝著什麼呢！快點打開來看吧！(open box)");
    set("value",3000);
  }
  setup();
}

void init()
{
  add_action("do_open","open");
}

int do_open(string str)
{
  object me = this_player(), ob = this_object();
  string msg;
  int index, i;

  if(str != "box") return 0;

  message_vision("$N迫不及待的打開箱子一瞧究竟.....\n",me);
  switch(random(15))
  {
    case 1 : msg = "有一張獎卷";
             new(__DIR__"obj24")->move(environment(me));
             break;
    case 7 : index = random(50)+1;
             msg = "有"+chinese_number(index)+"碗四神湯";
             for(i=0;i<index;i++)
               new("/open/world1/acme/area/npc/obj/soup")->move(environment(me));
             break;
/*
    case 14 : msg = "有一個黑色水晶";
              new("/open/always/time-q/black_crystal")->move(environment(me));
              break;
*/
    default : if(random(3)) msg = "什麼都沒有";
                else
                {
                  msg = "噴出一團毒氣";
                  me->apply_condition("poison", me->query_condition("poison")+15);
                }
              break;
  }
  message_vision("\n哇.... 箱子裡竟然"+msg+"，真是太棒了！\n\n",me);
  destruct(ob);
  return 1;
}
