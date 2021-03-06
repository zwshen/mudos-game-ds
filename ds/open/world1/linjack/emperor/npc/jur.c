inherit NPC;
void create()
{
        set_name("杜絕",({ "do jur","jur" }));
        set("long",
                "他就是惡名昭彰, 在聖宗上國各地都有人馬的大盜頭頭,\n"
                "他有一身頂絕的武功\, 他的武功\可能只略遜於各大派掌門,\n"
                "加上他人手眾多, 又是東郊四大盜之首, 常和他三名弟兄一\n"
                "同進退, 去圍剿他們的門派輕者死傷十數人, 重者就死傷慘\n"
                "重甚至於要解散門派. 連上國兩千大軍壓境這幫人仍能與之\n"
                "抗衡, 你就知道他們的實力有多雄厚了.\n"
        );
        set("title","濁世之人");
        set("age",45);
	set("attitude","aggressive");
        set("level",47);
	set("battlepoint",6);
        set("guild_gifts",({ 6,6,4,4 }));
	set("evil",15+random(6));
        set("apply/armor",30);
        set("chat_chance",5);
        set("chat_msg",({
  "杜絕正在盯著你看。\n",
  "杜絕說: 嗯! 殺! 別讓他跑了!\n",
  "杜絕正在看著桌上的圖。\n",
}));
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
  "杜絕說: 看我濁世之刀的厲害!\n",
  (: command("wield blade") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/blade3")->wield();
        carry_object(__DIR__"eq/leggings")->wear();
        carry_object(__DIR__"eq/t_boots")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        carry_object(__DIR__"eq/t_cloth")->wear();
        add_money("gold",2);
}
void die()
{
	object ob,room;
        room = load_object("/open/world1/linjack/emperor/bandit3");
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) { ::die();	return; }
        room->add_temp("pop",([ ob->query("id") : 1 ]));
        room->add_temp("clean",1);
        room->set_temp("die/jur",1);
        room->clean(1);
	::die();
	return;
}
