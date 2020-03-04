inherit NPC;

void create()
{
        set_name("¤uÃÆ", ({"worker"}) );
        set("long",@LONG
¤@°¦¦£±o·wÀYÂà¦Vªº¤uÃÆ¡A¨e±Mª`¦a·h¹B¿ÂÃÆ­Ì¤é±`©Ò»Ýªº­¹ª«¡C
LONG);
        set("unit","°¦");
        set("race", "beast");
        set("limbs", ({ "ÀY³¡", "¨­Åé", "Ä²¨¤"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",20);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-20);    
        set("chat_chance",5);
        set("chat_msg",({
                "¤uÃÆ¦£¸L¦a·h¹BµÛª««~¡C\n",
           (: command("sweat") :),
           (: random_move :),
        }));

        setup();
}
void die()
{
     object obj;
     message_vision( "[0;1;32m¤[1m@[1m°[1m¦[1m¤[1mp[1m¤[1mp[1mª[1mº[1m°[1mH[1mÂ[1mÎ[1m±[1mq[1m¤[1mu[1mÃ[1mÆ[1mª[1mº[1m¨[1m­[1m¤[1mW[1m±[1m¼[1m¤[1mF[1m¤[1mU[1m¨[1mÓ[1m¡[1mC[0m" ,this_object() );
     obj=new(__DIR__"hill_aphid_5");
     obj->move(environment(this_object() ) );
        ::die();
        return;
}
