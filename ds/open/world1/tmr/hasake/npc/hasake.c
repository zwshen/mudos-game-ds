inherit NPC;
void create()
{
        set_name("哈薩克牧民", ({ "hasake herdsman", "herdsman"}));
        set("gender", "男性");
        set("age", 26);
        set("long", "一位健壯的哈薩克族民，正趕著幾十只羊。\n");
        set("attitude", "friendly");
        set("level", 5);
        set("inquiry", ([
            "蘇普" : "蘇普是蘇魯克的兒子，跟他爹一樣是個好漢子！\n",
            "蘇魯克" : "蘇魯克是我們哈薩克人中的大英雄，他有個兒子叫蘇普。\n",
            "阿曼" : "阿曼是草原上一朵會走路的花。\n",
            "計老人" : "計老人會釀又香又烈的美酒，會醫牛羊馬匹的疾病。\n",
        ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"哈薩克牧民高興地說: 上個月，我用刀砍死了一頭狼，剝了狼皮送給咱阿妹。\n",
"哈薩克牧民道:  歡迎來到我們哈薩克部族，請去喝碗香甜的乳酪吧。\n",
        }) );
        carry_object(__DIR__"obj/madao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}
