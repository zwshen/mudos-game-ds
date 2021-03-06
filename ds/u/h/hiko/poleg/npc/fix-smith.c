#include <ansi.h>
inherit NPC;

void create()
{
  set_name("鐵匠師傅", ({ "fix smith","smith" }) );
  set("gender", "男性" );
  set("long",@LONG
是個享有很好的聲譽的打鐵匠，據說是出自於滄縣
老師傅門下，目前自己開業中，而要修武器的方式
是[give smith 武器<id> ]以及付出一些錢。
LONG
);
  set("title",HIC"修理高手"NOR);
  set("age",51);
  set("level",50);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"鐵匠師博把燒紅的鐵塊用手中槌子敲打，發出『鏘』的聲音。\n",
"鐵匠師傅說著︰要講打鐵技術的話，我滄縣的師傅才是最強的呀。\n",
(: command("sweat") :), 
(: command("hmm") :),
}));
set("talk_reply","想要修理武器或是裝備嗎？ 把東西交給俺就行了！ (give smith 武器 <id>)\n");
  setup();
  carry_object("/open/world1/wilfred/newbie/hammer")->wield();
}

int accept_object(object who, object ob)
{
        if( this_object()->is_fighting() )
                {
                command("say Sorry我現在沒空!"); // add by alickyuen.
                return 0;
        }
  if( ob->query_amount() > 0 )
  {
    command("thank");
    return 1;
  }
        if( ob->query("no_repair") )
        {
                command("say 這件東西沒辦法修理啦...另覓高人吧~");
                return notify_fail("");
        }
if( ob->query("secured") ) 
  {
    command("say 東西請先解除保存狀態再交給俺。");
    return notify_fail("");
  }

  message_vision(NOR"$N"NOR"拿出"+ob->query("name")+NOR"("+ob->query("id")+")給$n。\n"NOR,who,this_object());

  if( !ob->query("skill_type") && !ob->query("armor_type") )
  {
    command("say 俺不會修理這種東西，您另請高明吧。");
    return notify_fail("");
  }

  if(this_object()->is_busy())
  {
    command("say 俺還在忙，請您等一下。");
    return notify_fail("");
  }

  command("say 請稍等，俺馬上修理。");
  this_object()->start_busy(4);
  call_out("fixing",5,ob,who);
  return 1;
}

void fixing(object ob, object who)
{
  int price, level;

  if(!who || environment(who) != environment(this_object()))
  {
    command("drop all");
    return;
  }

  level = 100 - ob->query_durable();
  if(ob->query("value") == 1) price = level * ob->query("init_value") / 100;
    else price = level * ob->query("value") / 100;

  message_vision(NOR+YEL"\n鐵匠師博說﹕"NOR"$n"NOR+YEL"的修理費是"HIC+chinese_number(price)+NOR+YEL"枚古幣。\n\n"NOR,this_object(),ob);
  if(who->query("bank/past") < price)
  {
    command("say 您好像付不出這筆錢吧，等你存款夠了再來找俺。");
    command("give "+who->query("id")+" "+ob->query("id"));
    return;
  }

  if(level > 90) command("say 這玩意兒幾乎快壞了嘛，沒關係，看俺的手段。");
    else if(level > 60) command("say 壞得滿嚴重的，不過不難修。");
           else if(level > 30) command("say 這東西還不算壞得很嚴重嘛，趁早修理也是好的。");
                  else command("say 這玩意兒倒是沒什麼損壞，你要修俺便給您照辦。");

  ob->set_durable(100);
  who->add("bank/past",-price);
  command("say 行了，修好了，謝謝惠顧，錢會從您的銀行裡扣。");
  command("give "+who->query("id")+" "+ob->query("id"));
  return;
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

message_vision(HIR"$N臨死前大喊道︰師傅∼∼我完成不了發揚打鐵技術的使命了。\n"NOR,this_object() );
      
tell_object(ob,HIC"[你增加了 1 點聲望!!]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}



