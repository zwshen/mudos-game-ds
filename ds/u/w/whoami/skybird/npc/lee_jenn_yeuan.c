#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("李鎮遠",({"lee jenn yeuan","lee","jenn","yeuan"}));
 set("long",@LONG
他身長約七尺，滿頭的白髮正好跟他皮膚黝黑的膚色形成強烈的
對比，而他的雙眼還不時閃出精光，讓人不感直視他的雙眼，他
那能揮舞著雙槍還邊施展大槍訣的絕技，更是讓人大為震懾•
LONG);
 set("title",HIC"天梟聖泉護衛長"NOR);
 set("attitude","peaceful"); 
 set("age",38);
 set("gender","男性");
 set("level",46+random(5));  
 set("max_hp",11000+random(3000)); 
 set("max_ap",8000+random(5000)); 
 set("str",85+random(30)); 
 set("dex",75+random(30));  
 set("Merits/bar",4+random(3));  
 set("Merits/wit",3+random(3)); 
 set_temp("apply/damage",135+random(30)); 
 set_temp("apply/hit",155+random(30));
 set_skill("bagi_fist",100); 
 set_skill("horse-steps",100);
 set_skill("unarmed",100);
 set_skill("da-fork",100); 
 set_skill("jingang-plan",100);
 set_skill("fork",100); 
 set_skill("dodge",70);
 set_skill("parry",70);
 map_skill("fork","da-fork");
 map_skill("unarmed","bagi_fist");
 set("chat_chance_combat",300);
 set("chat_msg_combat",({
                         (:command,"say 大膽小賊！找死？！":),
                         (: combat_ai :),
 })); 
 set_temp("TEAM_NPC",1);
 setup();
 carry_object(__DIR__"eq/steel_pike");
 carry_object(__DIR__"eq/sun_longpike")->wield(); 
 carry_object("/open/world1/wilfred/sand/npc/eq/eq24")->wear();
 carry_object(__DIR__"eq/flying_shoes")->wear();
 set_living_name("TEAM_NPC");
} 

void init()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  ::init();
  if( me->query_temp("TEAM_NPC") ){
    me->add_team_member(find_living("TEAM_NPC")); 
    ob->add_team_member(find_living("TEAM_NPC"));
    }
  if( me->query_temp("SkyBird/enemy") ) {
    ob->kill_ob(me);
    me->kill_ob(ob);
    }
}
void die()
{
        int i;
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",3); 
        ob->add_temp("SkyBird/enemy",1);
      
        message("world:world1:vision",
     HIY"\t天梟聖泉護衛長『李鎮遠』，奮戰到最後一刻，仍然不敵"+ob->query("name")+"，不由得敗下陣來……\n"NOR
        ,users() );
        tell_object(ob,HIW"\n(因為你殺死了李鎮遠，所以得到了 3 點聲望。)\n"NOR); 
      
        ::die();
        return;
}

void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield pike"); 
                command("wield pike 2");

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* 敵人->attack */
        command("team form jingang-plan");        command("exert da-fork"); 
        command("exert bagi_fist");
        this_object()->add_busy(-2);

        return;
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N從懷中掏出一瓶小瓶子，將瓶中液體塗抹在傷口處，傷口便神奇的癒合了•\n"NOR, me);              
    me->receive_heal("hp",random(800));
    me->receive_heal("mp",random(800));
    me->receive_heal("ap",random(800));
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

                if(random(100)<65)
                {
                   damage/=100;
                   message_vision(HIR"$N一個翻身，游刃有餘的躲過這次的攻擊•\n" NOR,this_object(),who);
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

