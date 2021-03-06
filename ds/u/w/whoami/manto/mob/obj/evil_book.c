inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(RED"《魔欲經》"NOR, ({ "evil book", "book" }));
  set("long",@LONG
一本黑色封皮的書，《魔欲經》三個字在封面上閃爍著黑芒，這本書
就像一隻來自地獄深淵裡的魔眼，暗暗吸灼著你的靈魂。

似乎有個聲音一直催促你翻開閱讀它(Read)。
LONG);
set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "本");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_read","read");
}

int do_read()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("evil book",this_player()) ) )
    return notify_fail("你沒有東西可以使用。\n");
  if( me->is_fighting() )
    return notify_fail("你正在戰鬥中，無暇分心。\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
   return notify_fail("此處無法使用"NOR+RED"魔欲經。\n"NOR);
  if( env->query("no_recall") )
    return notify_fail("此處無法使用"NOR+RED"魔欲經。\n"NOR);
  message_vision(HIW"$N用顫抖的雙手翻開"NOR+RED"魔欲經"NOR+HIW"，經書突然散發了燦爛的紅光，在這一片紅光之中，"NOR+HIR"魔欲經"NOR+HIW"三個字閃動著深邃的黑芒。\n"NOR,me);
message("world:world1:vision",
CYN"\n"+me->query("name")+"眼神迷惘，脫口揚聲唸道：「"NOR+RED"生不生，欲以為舟，亂非亂，魔念其中，心隨欲往千般事，坐化為魔苦中生"NOR+CYN"」\n\n"NOR
        ,users() );
       call_out("wakeevil",7);
  return 1;
}

void wakeevil()
{
        message("world:world1:vision",
CYN"\n你耳邊傳來模糊的歌聲。。。\n"NOR
WHT"\t\n福兮，禍兮，煉獄人間，靈兮，欲兮，何以為魔？。。。。。。\n"NOR
        ,users() );
  destruct(this_object());
        return;
}
