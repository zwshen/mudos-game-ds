#include <ansi2.h>
#include <combat.h>
inherit NPC; 
inherit SSERVER;
void normal_ai();
void combat_ai();
void power();
void heal();  
void create()
{
  set_name("索貝克", ({ "suoo bey keh","keh","bey","suoo","hero" }) );
  set("gender", "男性" );
  set("nickname","獵狐高手");
  set("title",HIR"獵狐村"NOR+HIC" 英雄"NOR);
  set("long",@LONG
他是在數十年前曾經打敗過九尾的高手，在那次的激戰中受了重
傷到此隱居療傷•聽說在他成為這個村子的英雄之前還只是個打
鐵匠，這也難怪他拿的武器你從來都沒看過•
LONG);      
  set("age",30+random(10));
  set("level",43+random(4));
  set("exp",40000+random(3000));
  set("race","human"); 
  set("max_hp",9000+random(2000)); 
  set("max_ap",25000+random(10000));
  set("max_mp",25000+random(10000));

  set_skill("unarmed",150);
  set_skill("parry",150);
  set_skill("dodge",150);
  set_skill("force",100);
  set_skill("fork",100); 
  set_skill("sword",100);
  set_skill("blade",100);
  set_skill("staff",100);

  set_skill("da-fork",100);
  set_skill("dragonfist",100);
  set_skill("bagi_force",100);
  set_skill("horse-steps",100);
  set_skill("bird-eight",100);
  set_skill("moon_force",150);
  set_skill("buddha-force",150);
  map_skill("unarmed","dragonfist");

  set_spell("god-kill",120); 
  set_spell("god-fire",130);
  set_spell("god-benison",150);  
  set_spell("god-shield",100); 

  set("addition/wit",4+random(3)); 
  set("addition/bar",2+random(3));  

  set("addition/damage",15+random(50)); 
  set("addition/armor",100+random(50)); 
  set("addition/shield",100+random(50)); 

  set("addition/con",100+random(20));
  set("addition/dex",100+random(20));
  set("class1", "神武教");
  set("class2", "神武教"); 

  set_temp("apply/hit",random(10));
  set_temp("apply/dodge",random(20));
  set_temp("exert_mark/bagi-power",1000);

  set("chat_chance", 300);
  set("chat_msg", ({
(: normal_ai :),
}));

  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
(: combat_ai :),
(: power :),  
}));
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  add_money("coin",random(5000));
  carry_object(__DIR__"eq/tooth")->wield(); 
  carry_object(__DIR__"eq/cloud_boots")->wear();
  carry_object(__DIR__"eq/tiger-strip_pants")->wear();
  carry_object(__DIR__"eq/purple-cloud_chain_armor")->wear();
}
void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  if( me->query_temp("ko_fox_nine") ){
  command("whisper "+me->query("id")+"如果你缺防具可以找我幫忙喔！");
  }
  return;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if(strsrch(str,"防具") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say 我是看你也是能夠打敗九尾的勇者才跟你說的..");
   command("say 在東北澤林裡頭有隻兇猛的鱷魚");
   command("say 如果你能夠打敗牠，把牠的牙齒給我，我就能幫你做出不錯的防具");   
  }
  if(strsrch(str,"九尾") !=-1)
  {
   command("say 我就是打敗九尾的那個人啊！");
   command("cac");
  }
  if(strsrch(str,"鱷魚") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say 東北澤林的深處，似乎有一隻巨大的鱷魚，只是從來沒人見過");
  }
  return;
}

int accept_object(object who, object ob)
{ 
  object obj=this_object();
  if(ob->query("id") == "crocodile teeth")
  {
    if( who->query_temp("ko_crocodile") && who->query_temp("ko_fox_nine") 
    && obj->query_temp("no_give") < 1 )
    {
    message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
    command("tsk "+who->query("id")); 
    command("say 我馬上就幫你做件防具！");
    destruct(ob); 
    obj->set_temp("no_give",1);
    obj->set_temp("give_item",1);
    call_out("giveitem",1,obj);  
    } else {
    command("say 我才不要來路不明的東西！");
  }
  return 0;
}
  command("say 送我東西啊？多謝你了，不過我長久住在此地，倒也不缺什麼，你還是拿回去吧。");
  write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
}

void giveitem()
{
      int i;
      object me,obj,item,item1;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("give_item");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            message_vision(HIY"$N仔細的打量了一下這顆牙齒。\n"NOR,obj);
            obj->set_temp("give_item",i+1);
            call_out("giveitem",2,me);
            break;
          case 2:
            command("say 不錯，這個可以做成蠻好的防具");
            obj->set_temp("give_item",i+1);
            call_out("giveitem",1,me);
            break;
          case 3:
            command("say 你等等喔！");
            message_vision(HIY"$N走到房裡去開始敲敲打打………\n"NOR,obj); 
            obj->set_temp("give_item",i+1);
            call_out("giveitem",3,me);
            break;
          case 4:  
            switch( random(10) ){
            case 0..2:            
             item=new(__DIR__"eq/bar-neck");
             item->move(obj); 
             message_vision(HIY"$N終於從房裡頭走了出來………\n"NOR,obj);
             command("say 嗯..就是這個東西..");
             command("give necklace to "+ me->query("id") );
             break;
            default:
             item1=new(__DIR__"eq/wit-neck");
             item1->move(obj); 
             command("sorry"); 
             command("say 看來我的功\力還不到家，這個東西就代表我一點歉意.."); 
             command("give necklace to "+ me->query("id") ); 
             break;
            }  
             obj->delete_temp("give_item");  
             obj->delete_temp("no_give");          
 break;          
   }
} 

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( ob )
        message("world:world1:vision", 
HIB"\n\t東北方的天空中，有顆"BLINK+HIY"星"NOR+HIB"墜入了地平線∼∼
\n\t\t"HIW"獵狐村的英雄被"+ob->name(1)+"殺死了。\n\n"+NOR,users());
        ob->add("popularity",7);
//        tell_object(ob,HIW"(你得到了7點聲望)\n"NOR);
        ::die();
        return;
}
 
void heal()
{
    object me=this_object();
    message_vision(HIW"$N手握金針，在$N身上受傷的地方扎了幾下，忽然$N傷痕神奇的慢慢開始治癒了！\n"NOR, me);              
    me->receive_heal("hp",random(1000));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
}

void power()
{
object me,ob,wp;
me = this_player();
ob = this_object();
  wp = ob -> query_temp("weapon");
  int x;
  switch( random(3) )
  {
    case 0 : 
             if( me -> query_bar() > ob -> query_bar() )
             x = me -> query_bar() - ob -> query_bar();
             ob -> set("addition/bar",x);
             ob -> set("addition/damage",150);  
             COMBAT_D->do_attack(me,ob,me->query_temp("weapon"),4);
             COMBAT_D->report_statue(ob);
             ob -> set("addition/damage",-150);  
             ob -> set("addition/bar",-x); 
             break;
    case 1 : command("exert da-fork");
             break;
    case 2 : 
             x =  (ob->query_int()/30)+(ob->query_spell("god-fire")/30);        
             message_vision(HIY"\n$N將手中$n"HIY"往空中一拋，煞時間"+chinese_number(x)+"顆火球從$N手中狂射而出！！\n"NOR,me,wp);
             while (x--){
             SPELL_D("god-fire")->cast_fire(me,ob);
             me->receive_damage("mp",20);
             }
             break;
    case 3 : command("cast god-kill");
             break;
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob = this_object(), me = this_player();

  if(ob->is_busy()) ob->add_busy(-10);
  if(!random(3) && ob->is_fighting() && me != ob)
  {
    message_vision(HIG"\n$N大吼一聲，嚇得$n雙腳發軟，動彈不得！\n"NOR,ob,me);
    me->start_busy(2);
    power();
  }
  ::receive_damage(type,cost,me);
  return 0;
}

int be_stolen(object me, object what)
{
        if( !me || !what )
                return notify_fail("[錯誤]:請用 report 指令回報。\n");
        tell_object(me, this_object()->name() + "不經意地一轉頭﹐你急忙將手縮了回去﹗\n"
                "還好﹐沒有被發現。\n");
        me->start_busy(2);
        return 1;
}

void normal_ai()
{
        /* 沒裝備盾，則裝盾 */
        if( !this_object()->query_temp("armor/shield") )
                command("wear all");

        /* 沒有exert ,則exert */
        if( !this_object()->query_skill_mapped("fork") )
                command("exert da-fork");       
        if( !this_object()->query_skill_mapped("dodge") )
                command("exert bird-eight");      
        if( !this_object()->query_temp("skill_active/bagi_force"))
                command("exert bagi_force power_up");      
        if( !this_object()->query_temp("skill_active/buddha_force"))
                command("exert buddha-force armor");      

        /* 招出神武盾 (cast god-shield) */
        if( !this_object()->query_temp("armor/shield") && ( this_object()->query("mp") > this_object()->query("max_mp")/2 ) )
                command("cast god-shield");

        /* 受傷時自我醫療 */ 
        if( this_object()->query("hp") + 3000 < (this_object()->query("max_hp")/2) )
                heal();

        return;
}
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield tooth");

        /* 沒裝備盾，則裝盾 */
        if( !this_object()->query_temp("armor/shield") )
                command("wear shield");

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < 2500 && !random(5) )
                heal();

        /* 敵人busy ->attack */
        i=sizeof(target);
        while( i-- )
        {
                if( this_object()->is_killing(target[i]) || this_object()->is_fighting(target[i]) )
                {
                        if( target[i]->is_busy() ) 
                     switch ( random(5) ){
                       default:
                        if( userp(target[i]) ) command("cast god-kill on " + getuid(target[i]) );
                        else command("cast god-kill on " + target[i]->query("id") ); 
                       break;
                       case 0: 
                        if( userp(target[i]) ) command("cast god-fire on " + getuid(target[i]) );
                        else command("cast god-fire on " + target[i]->query("id") );
                       break;
                       case 1:
                        if( userp(target[i]) ) command("ex da-fork on " + getuid(target[i]) );
                        else command("exert da-fork on " + target[i]->query("id") );
                       break;
                       case 2: 
                        if( userp(target[i]) ) command("ex dragonfist voice");
                        else command("exert dragonfist voice");
                       break;
                       case 3: 
                        if( userp(target[i]) ) command("ex moon_force long-arc");
                        else command("exert moon_force long-arc");
                       break;
                     } 
                    this_object()->start_busy(-2);
                }
        }
  
        return;
}

