#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
void heal();
void create()
{
  set_name("御遲妄",({"yuh chyr wanq","yuh","chur","wanq"}));
  set("long",@LONG
此人身上散發出一種肅殺之氣，雙眼如鷹，雙瞳散發著詭異的光
芒，身高七尺有餘，他就是天梟三聖之一『御遲妄』•江湖中傳
聞此人內功已臻至傳奇之境，再配上一身天嘯匕法更是所向無敵
•二十二歲那年就曾經一人獨殺絕命雙煞，從此威名遠播•在他
三十五歲的那年，因為意見不合而導致天梟分裂，於是仗著一身
高強功力，佔地為王，天梟攻武一派就此誕生•
LONG
    );
  set("attitude","peaceful"); 
  set("age",48);
  set("gender","男性");
  set("level",45);
  set("title",HIR"天梟三聖"NOR);
  set("Merits/wit", 5+random(5)); 
  set("Merits/bar", 9+random(5));
  set("str",85+random(15)); 
  set("dex",85+random(15)); 
  set_temp("apply/armor",135+random(18));
  set_temp("apply/damage",135+random(30));
  set("combat_experience",2000000);
  set("max_hp",23500+random(1500));
  set("max_ap",8500+random(1500));
  set("class2", "skyowl_military");
  set_skill("unarmed",88);
  set_skill("dagger",100);
  set_skill("force",98);
  set_skill("parry",87); 
  set_skill("dodge",100);
  set_skill("sky-dagger",100);

  set("chat_chance", 300);
  set("chat_msg", ({
(: normal_ai :),
}));
  set("chat_chance_combat",300);
  set("chat_msg_combat", ({
(: combat_ai :),
(:command,"say 哼！！憑你也想動我一根寒毛？！":),
}));
 setup();
 carry_object(__DIR__"eq/dragon_dagger")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
 carry_object(__DIR__"eq/sky_boots")->wear();
 carry_object(__DIR__"eq/sky_helm")->wear();
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
  add_action("do_join","join");
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("hmm");
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
        message("world:world1:vision",
CYN"\n  武林傳出了一則驚人的消息:\n\n\t"HIR"天梟三聖"NOR+CYN"之一的"HIR"御遲妄"NOR+CYN"居然敗在"+ob->name(1)+"的手上。\n\n"+NOR
        ,users());
        ob->add("popularity",3); 
        tell_object(ob,HIW"(因為你殺死了御遲妄，所以得到了 3 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void normal_ai()
{
        /* 沒有exert ,則exert */
        if( !this_object()->query_skill_mapped("dagger") )
                command("exert sky-dagger");       

        /* 受傷時自我醫療 */ 
        if( this_object()->query("hp") < (this_object()->query("max_hp")/2) )
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
                command("wield dagger");

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* 敵人->attack */

        command("ex sky-dagger");
        this_object()->start_busy(-2);

        return;
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N從懷中掏出一瓶小瓶子，將瓶中液體塗抹在傷口處，傷口便神奇的癒合了•\n"NOR, me);              
    me->receive_heal("hp",random(800));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
}

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(100)<70){
                   damage/=10;
                   message_vision(HIR"\n$N將手中武器一橫，擋下了這猛烈的一擊！\n" NOR,this_object());
                }
                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();

     if(me->query("class2")=="skyowl_military") return notify_fail("你已是天梟教武派教眾了。\n");
     if(arg!="skyowl") return notify_fail("你要拜入那一個門派?\n");
     if(me->query("class1") != "skyowl" || me->query("class2") ) return notify_fail("你並不是天梟教教眾。\n");
     command("say 哈哈..又有人想要入我武派，專研天梟教之武學了..");
     command("say 不過這三陵九霄心法可沒你想像中的易學..沒一點武學根基的人是學不來的..");
     command("say 這樣吧，如果你能擊敗疾風門的左護法，我就可以收你入我們武派.."); 
     me->add_temp("skyowl/military", 1);
        return 1;   
}
