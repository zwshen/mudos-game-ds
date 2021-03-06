//懶的在寫新的new skill,所以借用疾風門的sorgi_sword和moon_force 
//和已QC過的skill-[cloudsteps]來做輔助,其sk [Sorgi_sword 70,Moon_force 100,cloudsteps 100]
//此mob的特殊能力為拆招,引用Tmr的作品 
//特功為[舞劍輪迴],其機率為30%,附著delay 2秒
//Edit by Promise@DS 04/1/31
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("懷少真",({"huai shao zhen","huai","shan","zhen"}));
        set("long" ,
"掌管天地變化之人，具有操縱自然天擇神力之人。是當今武林
，專研占星術之中的佼佼者。\n");
        set("nickname", HIY"文天眾"NOR );
        set("attitude", "friendly"); 
        set("age", 30);
        set("gender","男性");
        set("combat_exp", 1200000);
        set("level", 45);
        set("title","《"HIW"鬼閃 "HIG"組"NOR"》" );
        set("max_ap",4000); 
        set("max_mp",4000);
        set("max_hp",10000);
        set_temp("apply/armor",20);
        set("str",300);
        set("dex",300);
        set_skill("cloudsteps",100);
        set_skill("unarmed", 70);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",70);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","cloudsteps");
        set("chat_chance",8);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force recover"):),
}));
        setup();
        carry_object(__DIR__"wp/sky-rainbow-sword")->wield();
        carry_object(__DIR__"eq/ghost-cloth")->wear(); 
        carry_object(__DIR__"eq/cloud-boots")->wear();
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who); 


                if(random(100)<50)
                {
                                damage/=2;
                                message_vision(HIG"\n$N心念一橫，五把舞劍環繞在$N旁，屆時檔掉了少許\的傷害！！\n" NOR,this_object());
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);

                return damage;
} 
 int special_attack(object me,object target,int hitchance)
{
  int tdex,tcon,damage;  
  damage = random(me->query_skill("sword") + 600);       
  if(!me || !target) return 0;
  if(random(10)) return 0;
  tdex=target->query_dex();
  tcon=target->query_con();
  if( random(hitchance*30) > tdex+tcon )
  {
message_vision(HIW"\n懷少真口中喃喃自語："HIG"沉靜的舞劍，綻放出威力之面，六把舞劍六象齊飛！！\n
"HIM"                             ◢  "NOR+MAG"�僓稙��稙��稙��稙�"HIM"  ◣           "NOR"
"HIM"                           ◢█  "NOR+MAG"╯�朅��朅��朅���"HIM"    █◣         "NOR"
"HIY"                         ◢██  "HIW"���嘵��嘵��嘵��嘵�"HIY"  ██◣       "NOR"
"HIY"                         ◥██   "HIW"�僓��灨﹜~���朅�"HIM"   ██◤       "NOR"
"HIM"                           ◥█  "NOR+MAG" ╯╰╭╯╰���朅�"HIM"   █◤         "NOR"
"HIM"                             ◥   "NOR+MAG"  �灨�      ╰"HIM"     ◤           "NOR"

"RED"                           ◢█ "HIR"╭╯�����灨╰�  ��"NOR+RED"  █◣          "NOR" 
"BLU"                         ◢██ "HIB"�� �歈裐歈� �矙矙�"NOR+BLU"  ██◣        "NOR" 
"BLU"                         ◥██ "HIB"╯ �裺潁裺� ╰�矙�"NOR+BLU"  ██◤        "NOR"       
"RED"                           ◥█ "HIR" ╭╯╮╭╯╮   ��"NOR+RED"  █◤          "NOR" 
"RED"                             ◥ "HIR" ╯  ╰╯  ╰ ╰╯"NOR+RED"  ◤            "NOR" 
"HIR"$n在一陣陣劍雨裡，被化為「"HIW"無名"HIR"」、「"HIM"花雨"HIR"」、「"HIY"血汗"HIR"」、「"HIG"青光"HIR"」、「"HIB"舞影"HIR"」的伍把"HIW"舞"HIR"劍，劍劍擊中要害，難痛無比！！"NOR"("HIR +damage+ NOR")\n"NOR,me,target);
       target->receive_damage("hp",damage, this_object()); 
       target->add_busy(2);    return 1; 
  }
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

        message("world:world1:vision",CYN"
古堡第一層傳出了陣陣的哀號聲："HIW+ob->query("name")+HIW"果然是高手，在下甘拜下風！！\n
"HIC+ob->query("name")+HIC"打倒了"HIC"操縱萬物天擇的"HIM"懷少真"HIC"後，繼續往古堡二樓邁進！！\n"NOR        ,users());
        ob->add("popularity", 3); 
        ::die();
        //destruct(this_object());
        return;
}

