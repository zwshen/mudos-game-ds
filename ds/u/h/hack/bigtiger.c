inherit NPC;

void create()
{
        set_name("大老虎", ({"big tiger","tiger"}) );
        set("long", "一隻非常大的老虎，正在這裡虎視眈眈看著你。\n");
        set("unit","隻");
        set("race", "beast");
        set("limbs", ({ "頭部", "身體", "背部", "後腳", "肚子" })); //受攻部位
        set("verbs", ({ "crash","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 1);
        set("level",3);
        set_temp("apply/hit",-10);      //弱化命中率
        set_temp("apply/dodge",-10);    //弱化閃躲率
        set("chat_chance",1);
        set("chat_msg",({
                //(: this_object(), "random_move" :),
                "大老虎~~~吼~~~~的一隻對著你大叫。\n",
        }));

        setup();
         }
