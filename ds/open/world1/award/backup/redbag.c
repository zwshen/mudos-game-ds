#include <ansi.h>
inherit ITEM;

string *msg = ({
"  ",
HIW"\n  $N將紅包拿了出來。\n"NOR,
HIW"\n  紅包上寫著「恭喜發財」的燙金字樣，有過年的氣氛。\n"NOR,
HIW"\n  $N興奮的將紅包打開.....。\n"NOR,
HIC"\n哇...紅包裡面是.... "NOR,
});

void create()
{
  set_name(HIR"紅包"NOR,({"red envelope","bag","envelope"}));
  set("long","這是一個過年除夕時，大人用來送給小孩的東西，裡面通常有驚喜。\n"
             HIW"要打開紅包請"HIC"open"NOR"。\n");
  set("weight",1000);
  if( clonep() )
  set_default_object(__FILE__);
  else
  {
    set("value",100);
    set("unit", "個");
    set("needaward",1);
  }
  setup();
}

void init()
{
  add_action("do_open","open");
}

void do_loop(object me,object ob,object gift,int index,string obname)
{
  string cmsg;
  if(sizeof(msg) != index)
  {
    index++;
    if(index > 4)
    {
      call_out("do_loop2",1,me,ob,gift,obname);
      return;
    }
    cmsg = msg[index];
    message_vision(cmsg,me);
    call_out("do_loop",1,me,ob,gift,index,obname);
  }
}

void do_loop2(object me,object ob,object gift,string obname)
{
  message_vision(obname + NOR"！！！\n",me);
  gift->move(me);
  destruct(ob);
}

int do_open(string arg)
{
  string obname;
  object me,ob,gift,bag;
  int index = 0,index2 = 8,money,exp,award,temp=random(2); // index2 : 禮物共幾種
  ob = this_object();
  me = this_player();

  if(!arg || (arg != "bag" && arg != "envelope") ) return 0;
  if( environment()->query("redbag") > 3 ) {
     tell_object(this_player(),"拿那麼多包...發一點給別人開吧.\n");
     return 0;
  }
  this_player()->add("redbag",1);
  index2 = random(index2)+1;
  money = random(10000);
  exp = random(5000);
  bag = new(__DIR__"gift/none");
  switch(index2)
  {
    case 1 : obname = HIW+chinese_number((exp*2)+10000+temp)+"點經驗值";
             gift = new(__DIR__"gift/none");
             me->add("exp",(exp*2)+10000+temp);
             break;
    case 2 : obname = HIY"一萬"+chinese_number(money)+"元";
             gift = new(__DIR__"gift/none"); // <-- 空紅包袋
	     me->receive_money(10000+money);
             break;
    case 3 : obname = HIW+chinese_number(exp+5000)+"點經驗值";
             gift = new(__DIR__"gift/none");
             me->add("exp",5000+exp);
             break;
    case 4 : obname = HIW"特殊貢獻值一點";
             gift = new(__DIR__"gift/none");
             me->add("award/totalvalue",1);
	     me->add("redbag",-1);
             break;
    case 5 : obname = YEL"超級大肉包";
             gift = new(__DIR__"gift/specialfood");
	     bag->move(me);
             break;
    case 6 : obname = HIR"幽冥劍一支";
             gift = new("/open/world1/acme/area2/npc/wp/darksword");
	     bag->move(me);           
             break;
    case 7 : obname = HIM"點液血塊";
	     gift = new("/open/world1/tmr/area/npc/obj/dragon-blood");
	     bag->move(me);
             break;
    case 8 : obname = HIC"筆記型電腦";
             gift = new("/open/world2/shengsan/aovandis/npc/obj/notebook");
             bag->move(me);
             break;
  }
  call_out("do_loop",1,me,ob,gift,index,obname);
  return 1;
}
