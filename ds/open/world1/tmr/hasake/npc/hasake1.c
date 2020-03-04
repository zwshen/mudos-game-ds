inherit NPC;
void create()
{
        set_name("哈薩克婦女", ({ "hasake woman", "woman"}));
        set("gender", "女性");
        set("age", 25);
        set("long", "一位熱情好客的哈薩克族婦女。\n");
        set("attitude", "friendly");
        set("level", 5);
        set("inquiry", ([
            "阿曼" : "阿曼是草原上一朵會走路的花。\n",
            "李文秀" : "李文秀這孩子，長得和阿曼一樣美麗，歌也唱得好。\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"哈薩克婦女道: 請進來坐坐吧，喝碗草原上香甜的乳酪。\n",
        }) );
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/shuinang");
}
