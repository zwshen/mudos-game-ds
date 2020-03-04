#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ÃÆ¦Z", ({"queen ant","queen","ant"}) );
        set("long",@LONG
³o¬O¤@°¦ÃÆ¦Z¡A¨e¥¿¦b§V¤O¦aÁc­l«á¥N¡C¥Ñ©ó¨eªº¨­Âß¬Û·íªÎ¤j¡A©Ò
¥H¦æ°Ê¬Û·íªº¤£¤è«K¡C
LONG);
        set("unit","°¦");
        set("race", "beast");
        set("gender","»Û©Ê");
        set("limbs", ({ "ÀY³¡", "¨­Åé", "Ä²¨¤"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",5);
        set("max_hp",10000);
        set("hp",10000);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-40);
        set("str",3);

        setup();
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
        message("world:world2:vision", 
        "\n[0;1;36m [1m [1m[[1m¥[1m»[1m¤[1mé[1mÀ[1mY[1m±[1mø[1m·[1ms[1m»[1mD[1m][0m [0;1;33m¯[1m«[1m¤[1mì[1mª[1mº[1m¯[1m}[1mÃ[1ma[1mª[1mÌ[1m-[1m-[1;31mÃ[1mÆ[1m¦[1mZ[1;33m-[1m-[1m¡[1mA[1m³[1mQ[0m"+HIW+ob->name(1)+"[0;1;33m±[1mþ[1m¦[1mº[1m¤[1mF[1m¡[1mC[0m\n\n"
        , users());
        ob->add("popularity", 7); //Án±æ
        ob=new_ob(__DIR__"obj/queen_head");
        ob->move(this_object());
        ::die();
        return;
}
