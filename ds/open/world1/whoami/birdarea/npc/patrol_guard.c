#include <ansi.h>
inherit NPC;
int aa;
void create()
{
       set_name("巡邏守衛",({"patrol guard","guard"}));
        set("level",25+random(10));
        set("title",HIR"獵狐村"NOR);
        set("race", "ogre");
        set("age", 23);
        set("long", "一位被富翁所雇用的巡邏守衛，負責捉拿被富翁盯上的獵物。\n");
        set("str",50+random(10)); 
        add("max_hp",9000+random(1000));
        set("dex",random(30)+20);
        set("int",40); 
        set("addition_armor",120);
        set("addition_shield",120);
        set("attitude","aggressive");
        set_skill("dodge",50+random(40));
        set_skill("unarmed",70+random(20));
        set_skill("parry",random(30)+50);
        setup();
        set_living_name("_Fox_Village_Guard_");
     for (aa=0;aa<5;aa++)
     { 
       switch( random(14) )
       {
        case 1: carry_object(__DIR__"eq/f_hat")->wear(); break;
        case 2: carry_object(__DIR__"eq/f_neck")->wear(); break;
        case 3: carry_object(__DIR__"eq/f_cloth")->wear(); break;
        case 4: carry_object(__DIR__"eq/f_armor")->wear(); break; 
        case 5: carry_object(__DIR__"eq/f_cloak")->wear(); break;
        case 6: carry_object(__DIR__"eq/f_wrists")->wear(); break;
        case 7: carry_object(__DIR__"eq/f_gloves")->wear(); break;
        case 8: carry_object(__DIR__"eq/f_ring")->wear(); break;
        case 9: carry_object(__DIR__"eq/f_waist")->wear(); break;
        case 10: carry_object(__DIR__"eq/f_pants")->wear(); break; 
        case 11: carry_object(__DIR__"eq/f_leg")->wear(); break;
        case 12: carry_object(__DIR__"eq/f_boots")->wear(); break;
       }
     } 
   add_money("coin",800+random(500));           

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
        if( !random(10) ){
        tell_object(ob,HIW"\n(因為你殺死了"+this_object()->query("name")+HIW"，所以得到了 1 點聲望。)\n"NOR); 
        ob->add("popularity",1); 
        }
        ::die();
        return;
}

