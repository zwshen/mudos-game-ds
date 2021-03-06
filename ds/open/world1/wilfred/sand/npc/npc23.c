#include <ansi.h>
#include <path.h>

inherit NPC;

string *go_temp = ({
"south","east","south","eastdown","east","east","south",
"east","east","east","east","east","east","east","east","east",
"south","east",
});

int do_super();

void create()
{
  set_name("黃沙賊頭頭", ({ "desert robber","robber" }) );
  set("gender", "男性" );
  set("long",@LONG
這是江湖上惡名昭彰的賊幫－－『黃沙幫』的老大。
LONG
);
  set("age",35);
  set("level",23+random(3));
set("exp",10000+random(2000));
  set("race","human");
  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("cow") :),
}) );
  setup();
  set_living_name("robber_war");
  call_out("do_shout",1);
}

void do_shout()
{
  remove_call_out("do_shout");
  command("tchat 兄弟們！咱們前往滄縣打劫去吧！！");
  command("tchat* wahaha");
  call_out("go",1,0);
  return;
}

void init()
{
  object ob = this_object(), me = this_player();
  object env = load_object(WD_PAST+"sand/room37");

  if(userp(me)) command("say 滾開！別擋路！！");
  if( me->query("id") == "harn-tar-fu" )
  {
    command("hehe");
    command("say 把錢拿出來！！動作快！！");
    call_out("robber",2,ob,env);
  }
}

void robber(object ob,object env)
{
  if(!ob) return;
  message_vision("錢莊很快的被$N洗劫一空！！\n",ob);
  message("world:world1:vision",
  HIY"黃沙賊頭頭大笑道：『哈哈哈，多謝各位老爺的銀子！！咱們後會有期了！』\n",users());
  call_out("robber_dest",2,ob); // 2003.4.14 新增  by ksj
  env->get_money();
  destruct(ob);
  return;
}

// 2003.4.14 新增  by ksj
void robber_dest(object ob)
{
  destruct(ob);
}

int go(int index)
{
  object ob = this_object();
  if(!environment(ob)) return 1;
  if(index == sizeof(go_temp)) return 1;

  if(ob->is_busy())
  {
    call_out("go",1,index);
    return 1;
  }

  command(go_temp[index]);

  if(index == 7)
  {
    call_out("action1",2);
    call_out("action2",5);
    call_out("go",7,++index);
    return 1;
  }
  call_out("go",random(3)+1,++index);
  return 1;
}

int action1()
{
  object ob = this_object();

  if(!environment(ob)) return 1;
  command("say 媽的賊兵，老子跟你拼了！兄弟們，你們先走，這裡給我來擋！！");
  message_vision(HIW"\n眾人答道： 是！！！\n\n"NOR,ob);
  return 1;
}

int action2()
{
  object ob = this_object();
  if(!environment(ob)) return 1;
  if(!present("boundary guard",environment(ob)))
    return 1;
  else
  {
    command("say 看來老子不顯點功\夫，你們倒是把老子當病貓看了 !!");
    do_super();
    return 1;
  }
}

int do_super()
{
  object ob = this_object(), *enemys;
  int i;

  ob->start_busy(0);
  new(__DIR__"wp/wp6")->move(ob);
  command("wield whip");

  message_vision(HIW"\n   $N"HIW"虎喝一聲 "HIR"『著！！！！！』"HIW" 鞭頭如銀蛇般，以快疾無比的速度分擊眾人！！\n\n"NOR,ob);

  enemys = all_inventory(environment());
  for(i=0;i<sizeof(enemys);i++)
  {
    if(enemys[i] == ob || enemys[i]->query("id") == "desert robber") continue;
    if(userp(enemys[i]))
      message_vision(HIW"$N大吃一驚，身形急拗，使個『鐵板橋』功\夫，在間不容髮的距離堪堪避過！！\n"NOR,enemys[i]);
    else
    {
      message_vision("鞭頭狠狠的擊中$N！！$N有如斷線的風爭般飛退！！接著滑出數十丈！！！ "HIR"(" +(random(2000)+1000)+ ")\n"NOR,enemys[i]); // 更改少許msg by alick,原本的說不通..obj 的屍體
      enemys[i]->die();
    }
  }
  return 1;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   message("world:world1:vision",
HIY"\t黃沙賊頭頭大喊：可惡的" +ob->name(1)+ "，我還會再來的！！\n"NOR,users());

   tell_object(ob,HIC"[你得到額外的 "+(1 + ob->query_temp("quest/sandwarp")/2)+" 點聲望]\n"NOR);
   ob->add("popularity",( 1 + ob->query_temp("quest/sandwarp")/2 ) );
   ob->delete_temp("quest/sandwarp");
   ::die();
   return;
}
