#include <ansi.h>
#include <npc.h>
inherit F_BANDIT;

string proof_file="/d/batogiya_dtl/npc/obj/proof2.c";

void create()
{
        set_name("宋處愚", ({ "song chu-yu" ,"song","yu" }) );
        set("long",@long
    宋處愚長的一付精明幹練相，正賊兮兮的望著你，似在不停地打
量你身上的財物，好像一付馬上要上前搶奪一樣。宋處愚雖然長的略
顯矮小，但身上武功不凡，只是度量狹小，沒有誠言，頗受幫眾們的
排擠。
long
);
        set_race("human");
        set("age", 30);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",140 );
        set_skill("song blade" , 140 ); // 宋家刀法
        map_skill("blade","song blade");
        set_skill("parry",90);
        set_skill("dodge",90);
        set("attitude", "aggressive");
        set("title","硬幫幫中頭目");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
        carry_object(__DIR__"obj/memory_card2");
}

void relay_say(object ob, string arg)
{
    object item;

    if( ob->query_temp("quest/haha_quest2") == 2 && arg == "哈顫" )  {
        do_chat( ({ "宋處愚說道：「哦∼原來你識得『哈顫』那傻小子啊，找我有什麼事嗎？」\n", }) );
        ob->set_temp("quest/haha_quest2", 3);
        return;
    }

    if( ob->query_temp("quest/haha_quest2") == 3 && arg == "證據" ) {
        if( this_object()->query_temp("quest/give_item") ) {
            do_chat( ({ "宋處愚說道：「哦∼原來你是要來拿證據的啊，沒多久之前已經有人來拿過了。」\n", }) );
            return;
        }

        do_chat( ({ "宋處愚說道：「哦∼原來你是要來拿證據的啊，吶！拿去，就是這個了。」\n", }) );
        ob->set_temp("quest/haha_quest2", 4);

        if( file_size(proof_file) < 0 ) return;
        if( catch(item = new(proof_file)) ) return;

        if( item->move(ob) ) {
            message_vision(HIW"$N從背後拿出了一本證據，拿給了$n。\n"NOR, this_object(), ob);
        } else {
            if( item->move(environment(ob)) ) {
                message_vision("$N從背後拿出了一本證據，拿給了$n，但是掉在地上了。\n", this_object(), ob);
            } else {
                destruct(item);
                return;
            }
        }

        this_object()->set_temp("quest/give_item", 1);
        call_out("reset", 900);
        return;
    }
}

void reset()
{
    this_object()->delete_temp("quest/give_item");
}

