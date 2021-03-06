#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIR"航海日誌"NOR, ({"red journal","journal"}));
  set("long",@LONG
一本紅皮冊子，看來曾經被水泡過而顯得破爛，裡面的文字都模糊不
清了，但你總覺得哪邊不對勁，也許再檢查(review)一下比較好。
LONG
);
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "本");
    set("volume",1);
    set("value",0);
  }
  setup(); 
}

void init()
{
  add_action("do_review","review");
}

int do_review(string str)
{
  object me,z;
  me=this_player();

  if(!str || str!="journal") return 0;
  if( me->is_busy() )
    return notify_fail("你還在忙，沒時間檢查。\n");
  if(!objectp(z=present("red journal",me) ) )
    return notify_fail("你沒有東西可以檢查呀。\n");

  message_vision("\n$N將日誌仔細地翻閱\，結果日誌禁不起摧殘而散落一地了。\n"NOR,me);
  me->start_busy(2);
  call_out("get_paper",1,me);
  return 1;
}

void get_paper(object me)
{
  int i;
  i=0;
  while(i<1)
  {
    if(!random(3))
    {
      message_vision(YEL"\n從日誌的夾頁中掉出來一張羊皮紙！\n"NOR,me);
      new(__DIR__"treasure-paper1")->move(environment(this_player()));
      i++;
    }

    if(!random(3))
    {
      message_vision(YEL"\n從日誌的夾頁中掉出來一張羊皮紙！\n"NOR,me);
      new(__DIR__"treasure-paper2")->move(environment(this_player()));
      i++;
    }

    if(!random(3))
    {
      message_vision(YEL"\n從日誌的夾頁中掉出來一張羊皮紙！\n"NOR,me);
      new(__DIR__"treasure-paper3")->move(environment(this_player()));
      i++;
    }
  }
  destruct(this_object());
}
