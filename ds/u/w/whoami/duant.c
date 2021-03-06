#include <ansi.h>
inherit NPC;
void create()
{
        set_name("段洪",({"duan hong","duan","hong"}) );
        set("long",@LONG
疾風門劍聖，雖為劍聖確不見其劍乃用劍之最高奧義•
LONG);
        set("title",HIW"疾風劍聖"NOR); 
        set("nickname","虛劍御空");        
        set("age",40+random(5));
        set("level",80);
        set("gender","男性");
        set("attitude", "peaceful");  
        set_skill("fogseven", 100+random(50)); 
        set_skill("dodge", 100+random(50)); 
        set_skill("unarmed", 100+random(50)); 
        set_skill("sword", 100+random(50)); 
        set_skill("star-sword", 100+random(50));
        set_skill("sorgi_sword", 100+random(50)); 
        set_skill("moon_force", 100+random(50)); 
        set_skill("sorsin_force", 100+random(50));
        set_skill("force", 100+random(50));
        map_skill("dodge","fogseven");
        map_skill("sword","star-sword");
        set("Merits/bar",8+random(10));
        set("int",175);
        set("addition_armor",50+random(100));
        set("Merits/wit",8+random(4));
        set("addition_damage",50+random(100));
        add("apply/hit",80+random(30));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                (: command ("exert moon-force shadow") :),
        }));
        setup();
}

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {
        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                   damage/=10000;
                   message_vision(HIC"\n$N鋼鐵般的軀體硬生生的將攻勢完全化解！！\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

