#include <ansi.h>
inherit NPC;
void create()
{
        set_name("千層雪", ({ "snow" }) );
        set("level",60);
           set("combat_exp",6000);
         set("exp",1500);
set("long","這位是地獄裡最恐怖的殺手，手持地獄魔器－七星魔匕，殺盡了無數的高手
，但是美若天仙的外貌更是與她蛇蠍般心腸的手段相反。\n");
;
        set("age",20);
        set("evil",70);
      set("race","human");
     set("title",HIR "血腥"NOR);
        set("gender","女性");
        set("attitude","killer");
             set_skill("unarmed",80);
        set_skill("dodge",80);
                  set_skill("parry",80);
        set_skill("dagger",100);
        setup();
        carry_object(__DIR__"wp/devil-dagger")->wield();
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
HIC"\n  秦假先以飛快的速度回報:"HIW"\n\n\t戰國皇陵第一殺手「千層雪」死在"+ob
->name(1)+"的手中了。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
        ::die();
        //destruct(this_object());
        return;
}
