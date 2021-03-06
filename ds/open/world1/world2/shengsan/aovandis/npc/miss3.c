// In room093.c 藍藍銀行
inherit NPC;
inherit BANKMAN;

void make_mark();

void create()
{
        set_name("銀行女行員",({"miss"}) );
        set("long","一位美麗的小姐親切的向您打聲招呼。\n");             
        set("age",38);
        set("level",15);
        set("race","人類");
        set("gender","女性");
        set("evil",-5);         // 邪惡度 -5 (正的表邪惡, 負表善良)
        set("exp_point",0);     // 設定強度, exp及combat_exp會參考到這個值
                                // 0 <= exp_point <= 9
                                // 內定值為 0 , 請依據強度來設合理的值...
        set("chat_chance",3);
        set("chat_msg",({
                (:command("say 有任何銀行業務要我為您服務嗎？"):),
                (:command("smile"):),
        })      );

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: make_mark :),
        }) );
        set_skill("dodge",10);
        set_skill("block",10);
        set_skill("parry",10);
        set_skill("unarmed",10);

        set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
        setup(); 
}

void init()
{
        ::init(); void make_mark() 
        {
        object *enemy, ob;
        command("sob");

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if(!ob) return;

        if( this_object()->query("helpready/"+ob->query("id")) )
                return;

        command("say "+ob->query("name")+"你是個魔鬼。");
        this_object()->set("helpready/"+ob->query("id"),1);     // 與 id 結仇
        }
}

