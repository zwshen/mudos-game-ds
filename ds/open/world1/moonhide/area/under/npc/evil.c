#include <ansi.h>

inherit NPC;

void create()
{
         set_name(HIR"天魔"NOR, ({ "tian devil", "devil" }) );
        set("long",@LONG
長年壓制在地底下，與天妖乃同出一轍，生性好強，對污濁
它的生物，只有「死」這個辦法。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("attitude","aggressive");
        set("level", 45 + random(10));
        set("age", 200 + random(100));
        set("evil",-20);
        set("title", HIC"天"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/evil-armor-only")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear();  
     carry_object(__DIR__"obj/fire-fruit");
}

void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIR"\n天魔發出一陣奸笑，趁著$N手忙腳亂時，狠狠地往$N胸口要害抓了下去！！\n" + NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                case 1: 
                        message_vision(HIR"\n天魔對$N露出兇惡的眼神，嘴裡還發出嘶嘶的恐怖聲響...\n" + NOR,me);
                        this_object()->kill_object(environment(me));
                        break;
        }
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if( random(10) ) return 0;

    tdex=target->query_dex();
    tcon=target->query_con();

    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIR"\n$N"+HIW"身上魔氣大盛，撮指成尖，使出【天魔錐】，硬生生地插進$n的胸腔！！\n"+NOR,me,target);
      target->receive_damage("hp",400+random(150), this_object());
      return 1; 
    }

        message_vision(HIR"\n$N"+HIW"突然眼放"+HIG"青光"+HIW"，口內漸漸聚集一股能量••\n" 
                    +HIW"噴出！毀滅性的"+HIR"火燄"+HIW"無情的燒向$n，\n"
                    +HIW"造成"+HIR"嚴重的燒傷！\n"+NOR ,me,target);      
        target->receive_damage("hp",300+random(100), this_object());
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
HIG"\n\n\t\t"+ob->name(1)+""+HIY"苦鬥"+HIR"天魔"+HIY"數百回合！\n\n" 
HIY"\t\t就在油盡燈枯\之際，"+HIR"天魔"+HIY"背頸的要害竟然被擊中了！！！\n\n"
MAG"\t\t紫色的邪氣大量竄出，"+MAG"伴隨著一聲淒厲的叫聲，破雲而逝∼∼\n\n"+NOR,users());

   //HIG"\n\t\t\t\t\t 直直奔向幽靈聖地──《修羅域》\n\n"+NOR
        ob->add("popularity",6); 
        ::die();
        return;
}

