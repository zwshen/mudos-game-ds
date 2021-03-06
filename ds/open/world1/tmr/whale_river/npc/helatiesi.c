// bear.c

#include <npc.h>
#include <ansi.h>
#include <skill.h>

void do_destruct();

void create()
{
        set_name("赫拉鐵斯", ({ "helatiesi monster","monster","_NPC_ID_HELATIESI_"}) );
        set_race("beast");
                set("title","湖怪");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age",200);
        set("long",@long
「赫拉鐵斯」是史上有名的湖怪，身長數尺，巨大的身體使得你好比
是隻對上大象的小兔子，根本無法與之抗衡。赫拉鐵斯深藍般的雙眼正注
視著你，強健而有力的長尾巴正在任意搖擺，一付不把你放在眼裡的模樣
，從赫拉鐵斯佈滿尖牙利齒的嘴裡吐出來的穢氣，直薰得你頭昏眼花。
long
                );
        set("chat_chance", 8);
         set_skill("unarmed",150);
         set_skill("parry",150);
         set_skill("dodge",150);
        set_attr("strength",50);
        set("chat_msg", ({
                "赫拉鐵斯「嘶」的一聲，發出個奇怪的叫聲。\n",
                "赫拉鐵斯「嘶」的一聲，發出個奇怪的叫聲。\n",
        }) );
        setup();
          advance_stat( "nina" , 300);
        set_level(30);
        carry_object(__DIR__"obj/helatiesi-ocean")->wear();
           set_temp("apply/damage",50);
        call_out("do_destruct",300);    // 300 秒後「潛入湖底」
}

void do_destruct()
{
        object ob=this_object();
        if(!ob) return;
        if(ob->is_fighting() )
        {
                message_vision(CYN"$N長尾一甩，把所有的敵人都掃了開去。\n"NOR,ob);
                ob->remove_all_killer();
        }
        message_vision(CYN"$N身形迅速地往大湖移動過去，隨即「噗通」一聲消失在湖中央了。\n"NOR,ob);
        destruct(ob);
}

int accept_object(object player, object ob)
{
        if( player->query_learn("chamber nina-fish")
            || player->query_skill("chamber nina-fish") )
        return 0;
        if( !ob->id("_OBJ_ID_OCREAN_HEART_") )  return 0;
        if( player->query("skills_point")+3 >SKILL_MAX_POINT) return 0;
        tell_object(player,HIW "赫拉鐵斯深深地望了你一眼，你似乎從牠的眼神中，領悟到一些能力？！\n" NOR);
        tell_object(player,HIG"(你的技能學習點數花掉三點。)\n" NOR);
        player->improve_skill("chamber nina-fish",100);
          player->add("skills_point",3);
        call_out("do_destruct",1);
        return 1;
}

