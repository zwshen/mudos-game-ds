inherit NPC;

void create()
{
        set_name("蠕動的屍體", ({ "corpse" }) );
        set("long", "一個死亡已久卻會動的屍體。\n");
        set("race", "野獸");
        set("gender","雌性");   // 1999.2.28 增加此註解
        set("age", 10);
        set("level",2);
        
        set("str", 54);
        set("dex", 16);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 10);
        set("chat_msg", ({
                (: command("angry") :),
                "屍體爬呀爬，爬到了你腳邊。\n",
                "屍體大喝一聲:還~~我~~~命~~~來。\n",
                "屍體憤怒的看著你。\n",
                "屍體突然不動了。\n" }) );
                
        set_temp("apply/damage", 30);   //附加傷害力
        set_temp("apply/hit", 20);      //附加命中率
        set_temp("apply/armor", 0);     //附加防禦力 

        setup();
}

int accept_object(object who, object ob)    //可接受東西
{
        if( ob->id("water") ) {
                set_leader(who);
                message("vision", name() + "生氣的說道:『想害死我啊？給我喝聖水!』\n", this_player());
                return 1;
        }
}
