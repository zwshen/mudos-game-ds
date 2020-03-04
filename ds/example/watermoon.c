inherit NPC;
void create()
{
        set_name("水雲齋",({ "watermoon","水雲齋" }));

 set("long", @LONG

    嬌小的身軀讓人覺得似乎弱不禁風，但卻更顯得其楚楚可憐的姿態，
然而其美麗的雙眼卻流露出堅定的眼神，彷彿沒有任何事情能影響她的決
定。在她的身上讓人感覺不出任何哀愁的氣氛，她總是將所有悲傷的事情
都收在自己內心的深處，但卻也因此其愛侶卻因無法走入她的內心而深深
的自責著。

LONG
        );
        set("gender", "女性" );
        set("level", 80);
        set("age",16);
        set_temp("class_wind/power",300);

map_skill("sword","star-sword");
set("chat_chance", 8);
set("chat_chance_combat", 8);
set("chat_msg",({
  (: command("say 在你說要離開我之前，我會一直愛著你的。") :),
(:command("sigh") :),
  (: command("say 為何你總是不相信我的真心呢......") :),
(:command("stare") :),

}));
set("chat_msg_combat", ({
  (: command("say 嘿, 想對我不規矩，你還早呢.....") :),
  (: command("exert fogseven shadow") :),
  (: command("exert moon_force recover") :),
  (: command("exert star-sword penuma-sword") :),
  (: command("exert moon_force long-arc") :),
  (: command("exert star-sword tian") :),
  (: command("exert star-sword nine") :),
}));
      set_skill("unarmed",100);
        set_skill("sword",100);
        set_skill("force",100);
        set_skill("fogseven",100);
        set_skill("moon_force",100);
         set_skill("sorgi_sword",100);
        set_skill("star-sword",100);

        setup();
}

