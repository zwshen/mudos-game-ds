#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM"喜鵲"NOR, ({ "love bird","bird" }) );
        set("long", 
                "傳說中在每年牛郎與織女在七夕情人節那天，都是連接兩人之間的橋樑，\n"
                "它們的身上都帶有一些些的喜氣，讓碰到的人可能在一年之內會傳喜事，是很吉詳的一種動物。\n");
        set("unit","隻");

        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "翅膀", "後腳","前腳"}));
        set("verbs", ({ "claw","crash"}));
        set("age", random(5000));
        set("level",100);
        set("chat_chance",11);
        set("chat_msg",({
  (: command,"say 情人節快樂呀！" :),
  (: command,"say 希望今天牛郎能見到織女∼(o︿o)" :),
}));
        setup();
}

void init()
{
        if( present("match-maker",environment(this_object())) )
        {
                command("follower match-maker");
                command("say 老大呀, 還在混呀, 快點找到牛郎啦!");
        }
}
