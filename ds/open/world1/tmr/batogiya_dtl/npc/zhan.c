#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("哈顫", ({ "ha zhan", "zhan"}) );
    set_race("human");
    set("age", 6);
    set("long", "眉毛粗而短，眼睛瞇而小，嘴角下垂，一副呆頭呆腦的樣子。\n");
    set("title","摑民幫");

    set("chat_chance", 20);
    set("chat_msg", ({
        "哈顫仰天狂嘯：「選舉無效！！」\n",
        "哈顫仰天狂嘯：「沒有真相！沒有村長！」\n",
        "哈顫對你說道：「可以幫我找硬幫幫大老『宋神掌』宋處愚嗎？」\n",
        "哈顫對你說道：「聽說有位『福小姐』手上握有厲害的證據，能幫我連繫她嗎？」\n",
        "哈顫對著天發呆道：「我什麼都可以不要，我只要當村長，就算只當一次也好啊∼」\n",
    }));

    setup();
    switch( random(5) ) {
        case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
        case 1: carry_object(__DIR__"obj/armor")->wear(); break;
        case 2: carry_object(__DIR__"obj/belt")->wear(); break;
        case 3: carry_object(__DIR__"obj/boots")->wear(); break;
        case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
    }

    switch( random(5) ) {
        case 0: carry_object(__DIR__"obj/blade")->wield(); break;
        case 1: carry_object(__DIR__"obj/dagger")->wield(); break;
        case 2: carry_object(__DIR__"obj/whip")->wield(); break;
        case 3: carry_object(__DIR__"obj/axe")->wield(); break;
        case 4: carry_object(__DIR__"obj/sword")->wield(); break;
    }

    carry_money("gold", 3);
}

int accept_fight(object ob)
{
    do_chat("哈顫對著你怒道：「滾開！別礙著我！」\n");
    return 0;
}

void relay_say(object ob, string arg)
{
    if( arg == "福小姐" )  {
        do_chat( ({ "哈顫說道：「你認識『福小姐』！？可以幫我跟她拿證據嗎？」\n", }) );
        ob->set_temp("quest/haha_quest1", 1);
        return;
    }

    if( arg == "宋神掌" || arg == "宋處愚" )  {
        do_chat( ({ "哈顫說道：「你認識『宋神掌』！？可以幫我跟他要證據嗎？」\n", }) );
        ob->set_temp("quest/haha_quest2", 1);
        return;
    }

    if( arg == "可以" ) {

        if( ob->query_temp("quest/haha_quest1") == 1 ) {
            do_chat( ({ "哈顫說道：「那就麻煩你幫我跟福小姐要證據吧。」\n", }) );
            ob->set_temp("quest/haha_quest1", 2);
        }

        if( ob->query_temp("quest/haha_quest2") == 1 ) {
            do_chat( ({ "哈顫說道：「那就麻煩你幫我跟宋神掌要證據吧。」\n", }) );
            ob->set_temp("quest/haha_quest2", 2);
        }
    }
}

int accept_object(object me, object ob)
{
    object item;

    if( is_fighting() ) {
        do_chat((: command, "say 別吵！沒看到我正在打架啊！" :));
        return 0;
    }

    if( ob->id("_HAHA_PROOF_1_") ) {
        if( file_size("obj/money/gold.c") < 0 ) return 0;
        if( catch(item = new("/obj/money/gold.c")) ) return 0;
        item->set_amount(5);

        if( item->move(me) ) {
            message_vision(HIW"$N從口袋裡掏出了一些黃金，拿給了$n。\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N從口袋裡掏出了一些黃金，拿給了$n，但是掉在地上了。\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
        me->delete_temp("quest/haha_quest1");

    } else if( ob->id("_HAHA_PROOF_2_") ) {
        if( file_size(__DIR__"obj/book.c") < 0 ) return 0;
        if( catch(item = new(__DIR__"obj/book.c")) ) return 0;

        if( item->move(me) ) {
            message_vision(HIW"$N從背後拿出了一本書，拿給了$n。\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N從背後拿出了一本書，拿給了$n，但是掉在地上了。\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
        me->delete_temp("quest/haha_quest2");
    } else { return 0; }

    message_vision("$N狂笑道：「哇哈哈！哇哈哈！村長我當定了！」。\n", this_object(), me);
    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}
