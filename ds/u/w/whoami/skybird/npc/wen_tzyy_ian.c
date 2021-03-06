#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("聞紫煙",({"wen tzyy ian","wen","tzyy","ian"}));
 set("long","\n");
 set("title",YEL"十萬山山寨"NOR);
 set("age",38);
 set("gender","女性");
 set("level",65);
 set("max_hp",14000+random(3000)); 
 set("max_ap",8000+random(5000)); 
 set("Merits/bar",8+random(5));  
 set("Merits/wit",3+random(3));  
 set("Merits/tec",3+random(3));  
 set_temp("apply/str",15+random(30));  
 set_temp("apply/dex",15+random(30));  
 set_temp("apply/damage",45+random(30));  
 set_temp("apply/armor",35+random(30)); 
 set_temp("apply/hit",155+random(30));
 set_skill("whip",100);  
 set_skill("masen_whip",100); 
 set_skill("force",100); 
 set_skill("seven-love",100); 
 set_skill("dodge",100); 
 set_skill("run_cloud",100); 
 map_skill("dodge","run_cloud");
 map_skill("whip","masen_whip"); 
 set("MKS",10000); set("chat_chance_combat",300);
 set("chat_msg_combat",({
                         (: combat_ai :),
 })); 
 set_temp("pill",6);
 setup();
 set_living_name("Wen_Tzyy_Ian"); 
 carry_object(__DIR__"eq/snake-bone_blade")->wield();
} 

void init()
{ 
  object me=this_player(),ob=this_object();
  ::init();
  if ( !me->query("class1") ) return; 
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);
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
        if( !ob->query("quest/SkyBird") && ob->query_temp("assassinate") ){
        message("world:world1:vision",
HIG"\t『東北捷報』\n" 
CYN"\n\t\t山寨裡頭一片混亂！群賊四處奔走！！\n"HIW+BLK"\n\t\t\t十萬大山內作惡多端的頭頭聞紫煙被"+ob->query("name")+"給暗殺了•\n"NOR         
        ,users() ); 
        ob->delete_temp("assassinate"); 

/* 開了再用        ob->set("quest/SkyBird",1); */        } else {
        message("world:world1:vision",
HIG"\t『東北捷報』\n" 
CYN"\n\t\t山寨裡頭一片混亂！群賊四處奔走！！\n"CYN"\n\t\t\t十萬大山內作惡多端的頭頭聞紫煙終於被"+ob->query("name")+"擒殺了•\n"NOR         
        ,users() );
environment(this_object())->door_open(1);
        }
        tell_object(ob,HIW"\n(因為你殺死了聞紫煙，所以得到了 5 點聲望。)\n"NOR); 
        ob->add("popularity",5); 
        new(__DIR__"obj/head")->move(this_object());

        ::die();
        return;
}

void combat_ai()
{
        int i,x;
        object *target,npc;

        target = all_inventory(environment(this_object()));
        x = sizeof(target);

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield blade"); 

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < this_object()->query("max_hp")/3 ) 
        this_object()->add_busy(-2);
        heal();

        return;
}

void heal()
{
    object me=this_object(); 
    if( !me->query_temp("pill") ) return;
    if( me->query("hp") > me->query("max_hp")/3 ) return;

    message_vision("$N從懷中掏出一顆"HIY"金色藥丸"NOR"，隨即吞了下去•\n", me);              
    me->receive_heal("hp",me->query("max_hp"));
    me->receive_heal("mp",me->query("max_mp"));
    me->receive_heal("ap",me->query("max_ap"));
    me->add_temp("pill",-1);
    return;
}
 
varargs int receive_damage(string type, int damage, object who)
{
        int val,time;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(10)<4)
                {
                   message_vision(HIR"$N不顧身上傷勢，單手擋住$n的攻擊，隨即向前對$n發動攻擊！\n"NOR,this_object(),who);
                   for (time=0;time<1+random(2);time++) 
                   { 
                   this_object()->add_busy(-2);
                   COMBAT_D->do_attack(this_object(),who,this_object()->query_temp("weapon"),4);
                   COMBAT_D->report_statue(who); 
                   }
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}


