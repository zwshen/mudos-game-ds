#include <ansi.h>
inherit NPC;

void create()
{
       set_name("柴子玲",({"tsai tsi lain","tsai","lain"}));
       set("long",@LONG
    柴子雲，柴子玲兄妹皆為八極門李書文的得意弟子。其中柴子玲
天資聰穎，身段靈活，雖然後入師門但武功與其兄只在伯仲之間。由
於身體素有惡疾，所以絕少在江湖中行走，多半待於師父身旁，也因
此得到李書文的真傳。由於其兄於江湖中多年訪查，似乎得到治癒其
痼疾的線索，故離師遠行。但如今似乎舊疾復發，正倚著一桿鐵槍勉
強站立，神情好似十分痛苦。
LONG);
       set("gender","女性");
       set("age", 23);
       set("level", 27);
       create_family("八極門 ",7,"弟子");


       set("int", 90);
       set("dex", 70);
       set("guild_gifts",({10,7,0,3}));


      set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("fork",90);
        set_skill("bagi_fist",99);
        set_skill("da-fork",90);
        set_skill("horse-steps",99);



       set("chat_chance", 20);
       set("chat_msg", ({
            "柴子玲深鎖娥眉，輕咬櫻唇，似乎十分痛苦的樣子。\n",
            "只見柴子玲雙膝一軟，跌了下去，喘了幾口氣後又扶著鐵槍站了起來。\n",
            (:command("exert da-fork"):), 
            (:command("exert bagi_fist"):),
             }));


        set("chat_chance_combat",60);
        set("chat_msg_combat", ({

                (:command("exert bagi_fist"):),
                (:command("exert da-fork"):),

        }) );
   
        setup(); 
        carry_object(__DIR__"wp/b_s_pike")->wield();
}
