#include <ansi.h>

inherit NPC;

void create()
{
        set_name("悟緣", ({ "wu bonze","bonze" }) );
        set("race","human");
        set("gender", "男性");
        set("level",39);
        set("age",20);
        set("evil",-20);
        set("attitude", "peaceful");
        set("title",HIY"聖"BLK"魔"HIW"佛僧"NOR);
        set("long",@LONG
在那場戰役中，不幸殺了他一個師兄兼好友的一位師兄，他
懊惱萬分，從此之後喪失理性又傷了許多寺中上上下下的師
兄們，在那事之後便被方丈大師關到著，永不見天日。

LONG
);
        set_skill("quanyin-steps",80);
        set_skill("buddha-force",80);
        set_skill("wuchen-staff",80);
        map_skill("staff","wuchen-staff");
        
        

        setup();
        carry_object("/u/k/kakasi/eq/w_cloth")->wear();
        carry_object("/u/k/kakasi/eq/w_boots")->wear();
        carry_object("/u/k/kakasi/eq/w_cloak")->wear();
        carry_object("/u/k/kakasi/wp/w_staff")->wield();
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
HIW"\n 悟緣說:\n\n\t師父我知道我錯了請你原諒我。\n\n"+NOR
                ,users());
                ob->add("popularity",2); 
       tell_object(ob,HIW"(你殺死了悟緣，所以得到了 2 點聲望。)"NOR);
                ::die();
                //destruct(this_object());
                return;
}


int special_attack(object me,object target,int hitchance)
{
        if(!me || !target) return 0;
        if(random(4)) return 0;
        if(me->query("mp")<21) return 0;
        message_vision(HIW"$N"HIY"喃喃自語，馬上又充滿了活力。\n"NOR,me,target);
        me->receive_heal("hp",210+random(99) );
        me->receive_damage("mp",21);
        me->add_busy(1);
        return 1;
}

