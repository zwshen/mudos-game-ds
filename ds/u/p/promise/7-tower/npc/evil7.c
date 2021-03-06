#include <ansi.h>
#include <combat.h>
inherit NPC;

void combat_ai();

void check_temp();
void create()
{
set_name(WHT"斬無"NOR, ({"zhan wu","wu"}) );
  set("long",@LONG
本為疾風門最受期望的弟子，此人具有強烈的企圖心，雖然
心地本為善良，但因一些外在因素而迷的此人鬼迷心竅，在
一次因緣讓此人的性格大變，而成為令人人避之的萬世妖尊
。
LONG
);

  set("gender", "男性");  
  set("race", "人類");
  set("age",31);
  set("level",60);
  //set("attitude", "aggressive");
  set("evil",10000);
  set("title",HIY"【萬世妖尊】"NOR);  
  set("Merits/bar",12);
  set("Merits/bio",12);
  set("Merits/wit",12);
  set("Merits/tec",12);
  set("dex",300); 
  set("combat_exp",10000000);  set_skill("dance-sword", 100);
  set_skill("force", 100);
  set_skill("moon_force", 100);
  set_skill("fogseven", 100);
  set_skill("sorsin_force",100);
  map_skill("dodge","fogseven");
  map_skill("sword","dance-sword");
  add("addition_damage",300);
  add("addition_armor",300);
  set("chat_chance", 30);
  set("max_hp",30000);
        set("chat_msg", ({
               (: command("exert moon_force recover") :),
               (: check_temp() :), 
               (: combat_ai() :), 
        })); 

        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :), 
                (: combat_ai() :), 
                (: combat_ai() :), 
                (: command("exert moon_force recover") :),
                (: command("do wield sword,exert dance-sword") :), 
               (: check_temp() :),
               (: check_temp() :),
               (: check_temp() :),
               (: check_temp() :),
                (: command("do exert dance-sword") :),
                (: command("do exert dance-sword") :),
                (: command("do exert dance-sword") :),
                (: command("exert moon_force long-arc") :),
   }));
  setup(); 
  carry_object(__DIR__"wp/wp6")->wield();
  carry_object(__DIR__"eq/eq1")->wear(); 
  carry_object(__DIR__"eq/eq2")->wear();
  carry_object(__DIR__"eq/eq3")->wear();
  carry_object(__DIR__"eq/eq4")->wear();
  carry_object(__DIR__"eq/eq5")->wear();
  carry_object(__DIR__"eq/eq6")->wear();
  carry_object(__DIR__"eq/eq7")->wear();
  carry_object(__DIR__"eq/eq8")->wear();
 }

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 40 && userp(this_player()) )
    this_object()->kill_ob(this_player());
} 
void start_busy()
{
return;
}

void check_temp()
{
    object me=this_object();

    if(me->query_temp("nan")==1) 
    { me->delete_temp("nan",1); }
   return;
}
void add_busy()
{
return;
}

void combat_ai()
{

        int i;
        object *target,ob;
        ob = this_object();
        target = all_inventory(environment(ob));

        /* 武器被打掉，則裝回去 */
        if( !ob->query_temp("weapon") ) 
                command("wield sword");

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

                if(random(100)<40)
                {
                                damage/=2;
               message_vision("\n$N"HIR"氣定神凝的使出「蹉跎金剛指」，化解了大半片的攻擊！！\n"NOR,this_object());
                     }
           
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);

                return damage;
}
void die()
{
        object ob;
        int temp;
        //ob=this_player();
        if(this_object()->query_temp("die") == 0)
        {
                message("sound",NOR+YEL"斬無說道："HIR"要我死，下輩子吧。頓時金光閃爍，斬無似乎變了個樣。\n\n"NOR, 
                environment(this_object()));
                revive();
                set("max_hp", 35000);
                set("hp",35000); 
                set("name",WHT"斬無"HIC"(妖態)"NOR);                
                set("Merits/bar",20);
                set("Merits/bio",20);
                set("Merits/wit",20);
                set("Merits/tec",20);
                add("addition_damage",200);
                add("addition_armor",350);
                add_temp("die",1);
        }

        else if(this_object()->query_temp("die") == 1 )     
        {
                message("sound",NOR+YEL"斬無(妖態)說道："HIW"要我死，下輩子吧。頓時銀光閃爍，斬無似乎又變了個樣。\n\n"NOR, 
                environment(this_object()));
                set("max_hp", 40000 );  
                set("hp", 40000 ); 
                set("name",HIM"千煉"NOR+MAG"妖尊"NOR);               
                set("Merits/bar",20);
                set("Merits/bio",20);
                set("Merits/wit",20);
                set("Merits/tec",20); 
                set("dex",250);                

                add("addition_damage",250);
                add("addition_armor",400);
                add_temp("die",1);
        }
        else if(this_object()->query_temp("die") == 2)
        {

                message("sound",NOR+YEL"千煉妖尊說道："HIG"要我死，下輩子吧。頓時白光閃爍，斬無似乎又變了個樣。
        而且在斬無手上又多了把神兵！！\n\n"NOR,
                environment(this_object()));
                set("max_hp", 45000 ); 
                set("max_hp", 45000 );
                set("Merits/bar",23); 

                set("name",NOR+CYN"妖行"HIW"大教主"NOR);               
                set("Merits/bio",10);
                set("Merits/wit",20); 
                set("dex",400);               

                set("Merits/tec",23);
                add("addition_damage",250);
                add("addition_armor",500); 
                add_temp("die",1);           
                carry_object(__DIR__"wp/wp7")->wield();
        
        }
        else
        {      
                if( !ob = query_temp("last_damage_from") )
                      if( !ob ) return; 
        set("name",WHT"斬無"NOR);
        message("world:world1:vision",HIR"\n【七  邪  塔】 "NOR+RED"七邪塔之塔主 號稱"HIY"《萬世妖尊》"NOR+RED"的斬無,不敵"HIY+ob->query("name")+NOR+RED"的手下，慘遭滅塔之災！！\n\n"+NOR
                             ,users());
                ob->add("popularity",10);      
                return  ::die();
        }
}

