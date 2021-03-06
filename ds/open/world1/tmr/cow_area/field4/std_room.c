#include <dbase.h>
#include <ansi.h>
inherit ROOM;

void change();

void create()
{
  seteuid(getuid());
  setup();
}

void init()
{
  object me = this_player();

  ::init();
  set("no_horse_member",1);
  
  if( !userp(me) ) return;
  set("outdoors","land");
  change();// 改變 long 
  if( environment(me)->query_temp("stop_creat") ) return;

  // 自動產生 MOB
  remove_call_out("creatmob");
  call_out("creatmob", 1, me);
}

void creatmob(object me)
{
 int amount=0;
  string file;
  object c_mob, *inv;
  mixed *mob;

  if( !me || environment(me) != this_object() ) return;


if( random(20) )
    file = __DIR__"../npc/npc10.c";// 只會叫出「母牛」
else
    file = __DIR__"../npc/npc11.c";// 叫出「母牛之王」
  if( mob = filter_array(children(file), (: clonep :)) ) amount += sizeof(mob);


   if(amount > 5)
  {
    if( !random(3) ) tell_room(this_object(),"這裡似乎有些風吹草動。\n");
    return;
  }

  inv = all_inventory(this_object());

if( sizeof(inv) > 15 ) {
if( !random(4) ) tell_room(this_object(),"這裡似乎有些風吹草動。\n");
return;
}

    if( random(100) < 70 ) {
    if( !random(3) ) tell_room(this_object(),"這裡似乎有些風吹草動。\n");
return;
    }

  c_mob = new_ob(file);
  c_mob->move(this_object());
  c_mob->set("startroom", base_name(this_object()));
  
  tell_room(this_object(),"附近突然出現了一" +c_mob->query("unit")+c_mob->query("name")+ "。\n");
  return;
}

void change()
{
  string *str = ({
@LONG
草原上生長著鮮嫩的牧草，地域廣闊，一望無際，
在這片草海上，站著數隻牯牛，或桃紅，或金黃，或湛
藍，有如晚霞照耀著海波金麟，將草原景色點綴得美不
勝收。
LONG,
@LONG
這片草原與遠方的天際連成一線，你實在很難想像
它有多大，只能漫無目地的朝同一個方向走去。
LONG,
@LONG
你身處在一片草原之上，四周的野草高大過人，只
見天地一色，融入在遠方的地平線上，你聽見附近不時
傳來飛禽走獸的的叫聲。
LONG,
@LONG
你來到了一個大草原，乍聞雄獅怒吼，有如旱雷大
作，把你嚇了一跳！你定了定神，發現原來此地己相當
靠近獅子的巢穴。
LONG,
@LONG
你來到了一片廣闊無際的草原，濃密的野草隨著風
的律動，如海浪般起伏著，讓你有如置身於一片草海之
中。
LONG,
@LONG
這裡是一片綠油油的草叢，放眼望去有如一片綠色
的海，風景優美，觀之令人心矌神怡。
LONG,
@LONG
當你來到這片無著邊際的草原時，赫然發現四周只
剩下你的背影，翠綠的青草隨著沁涼的徐風左右搖擺，
形成的一片蔚為壯觀的綠色大海，你的心似乎也不安份
的隨著浮動，忍不住想要駐足於此來享受這片美景的溫
存。
LONG
});

  set("short", HBK"幽暗牯牛草原"NOR);
  set("long",str[random(sizeof(str))]);
  return;
}


