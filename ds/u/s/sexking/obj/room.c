#include <ansi.h>
inherit ROOM;

int flee(object obj);
int get_money();

string *temp_msg = ({
"\n不知過了多久，矇矓間只聽得有人在說話 ....\n\n",
WHT"男人說道： 怎麼，死了沒？\n"NOR,
HIW"年輕人說道： 沒氣了，應該是死了吧。\n"NOR,
WHT"男人說道： 好，丟在這裡就好了，走吧。\n"NOR,
HIW"年輕人說道： 是。\n"NOR,
HIW""BLK"\n你眼前一黑，又昏了過去 ....\n"NOR,
HIG"\n又不知過了多久.... 你終於恢復了神智...\n\n"NOR,
});

void create()
{
  set ("short", YEL"山寨"NOR);
  set ("long", @LONG
只見在前方不遠一處略為高聳的沙地上，搭了一圈柵欄，門口處
站著幾位身穿黃色獸皮衣，頭戴黃色皮帽的守衛，在後方柵欄內升起
了黃沙幫的旗號－－黑黃斑紋虎頭，此地守衛森嚴，看來並非久留之
地。
LONG
);

/*
  set("exits", ([
  "south" : __DIR__"room36",
]));
  set("objects",([
  __DIR__"npc/obj/obj20" : 1,
]));
*/
  set("outdoors", "land");
  setup();
}

void init()
{
  object me;
  ::init();
  if( interactive(me = this_player()) )
  {
    remove_call_out("action1");
    call_out("action1",1,me);
    me->start_busy(2);
  }
}

int action1(object me)
{
  if(!me) return 1;
  if(random(3))
  {
    message_vision(WHT"似乎沒人發現$N潛了進來。\n"NOR,me);
    return 1;
  }
  message_vision(HIW"\n$N不小心踏斷腳下的樹枝！！發出一些聲響！\n\n"NOR,me);
  message_vision(HIC"糟了！$N被發現啦！！\n"NOR,me);
  message_vision(HIR"$N突然被人從背後狠狠敲了一記悶棍！！\n"NOR,me);
  message_vision(HIR"$N哼了一聲隨即軟倒在地，接著被二個彪形大漢拖進山寨了。\n\n"NOR,me);
  me->set_temp("block_msg/all",1);
//  me->move(__DIR__"room3");
//  tell_room(__DIR__"room3",HIW"你看見有個渾身是血的人被丟在這裡，情況悽慘，己氣若遊絲了。\n"NOR);
  me->set("hp",random(30)+1);
  me->start_busy(20);
  call_out("action2",7,0,me);
  return 1;
}

int action2(int index, object me)
{
  string msg = temp_msg[index];
  if(!me) return 1;
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  if(++index < sizeof(temp_msg)) call_out("action2",4,index,me);
    else me->delete_temp("block_msg/all");
  return 1;
}

int flee(object obj)
{
  object npc, ob = this_object();

  if(!obj)
  {
    while(objectp(npc = find_living("desert_robber")))
    {
      tell_room(environment(npc),"黃沙賊慌忙逃逸了。\n");
      destruct(npc);
      ob->delete_temp("start_robber");
    }
  }
  else
  {
    destruct(obj);
    if(objectp(npc = find_living("desert_robber")))
      return 1;
    else
    {
      message("world:world1:vision",HIC"\n黃沙賊被打得落荒而逃了。\n\n",users());
      ob->delete("start_robber");
    }
  }
  return 1;
}

int start_robber()
{
  object ob = this_object();
  int i;
  if(ob->query("start_robber")) return 1;

  message("world:world1:vision",
HIR"\n\t【邊塞快報】"YEL"西方黃沙發生異變！下令全軍駐守關口，不得有誤！！\n\n"NOR,users());

  for(i=0;i<5;i++)
    new(__DIR__"npc/npc48")->move(__DIR__"room1");
  for(i=0;i<3;i++)
  {
    new(__DIR__"npc/npc21")->move(ob);
    new(__DIR__"npc/npc22")->move(ob);
  }
  new(__DIR__"npc/npc23")->move(ob);

  ob->set_temp("start_robber",1);
  call_out("flee",100);
  return 1;
}

int get_money()
{
  object *all_ppl, maxppl;
  int i, money, lose, maxlose = 0;

  all_ppl = children("/obj/user");
  all_ppl = sort_array(all_ppl, "sort_user", this_object());

  for(i=0;i<sizeof(all_ppl);i++)
  {
    money = all_ppl[i]->query("bank/past");
    lose = money / 100 * (random(5)+1);
    if(lose > maxlose)
    {
      maxlose = lose;
      maxppl = all_ppl[i];
    }
    all_ppl[i]->add("bank/past",-lose);
  }
  message("system","【錢莊聯盟】共有" +chinese_number(sizeof(all_ppl))+ "位武林人士的存款遭劫。\n",users());
  message("system","大財主"+maxppl->query("name")+"損失最為慘重，存款遭劫"+chinese_number(maxlose)+"枚古幣。\n",users());
  return 1;
}

